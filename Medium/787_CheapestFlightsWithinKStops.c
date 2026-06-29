# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# define INF INT_MAX

typedef struct Node {
    int weight;
    int vertex;
    struct Node* next;
} Node;

typedef struct HeapNode {
    int cost;
    int vertex;
    int stops;
} HeapNode;

typedef struct Heap {
    HeapNode* data;
    int capacity;
    int size;
} Heap;

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(Heap* heap, HeapNode node) {
    // Exception : Max size
    if (heap->size >= heap->capacity)
        return;

    // Adding new node to heap
    int i = heap->size;
    heap->data[heap->size++] = node;
    
    // Heapify MinHeap
    while (i > 0 && heap->data[(i - 1) / 2].cost > heap->data[i].cost) {
        swap(&heap->data[(i - 1) / 2], &heap->data[i]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(Heap* heap) {
    HeapNode root = heap->data[0];
    heap->size--;
    heap->data[0] = heap->data[heap->size];
    
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int smallest = left;
        
        if (right < heap->size && heap->data[right].cost < heap->data[left].cost) {
            smallest = right;
        }
        if (heap->data[i].cost <= heap->data[smallest].cost) break;
        
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return root;
}

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    // Initializing Adjaceny list
    Node** adj = (Node**)calloc(n, sizeof(Node*));
    for (int i = 0; i < flightsSize; i++) {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];

        Node* node = (Node*)malloc(sizeof(Node));
        node->weight = w;
        node->vertex = v;
        node->next = adj[u];
        adj[u] = node;
    }

    // Initialize dist[dest][k] : minDist
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc((k + 2) * sizeof(int));
        for (int j = 0; j <= k + 1; j++) {
            dist[i][j] = INF;
        }
    }

    // Initialize Heap
    Heap heap;
    heap.capacity = flightsSize * 2 + 2; 
    heap.size = 0;
    heap.data = (HeapNode*)malloc(heap.capacity * sizeof(HeapNode));

    // Set starting node
    HeapNode startNode = {0, src, 0};
    push(&heap, startNode);
    dist[src][0] = 0;

    int finalAnswer = -1;

    // Main Dijkstra
    while (heap.size > 0) {
        HeapNode curr = pop(&heap);
        int cost = curr.cost;
        int now = curr.vertex;
        int stops = curr.stops;

        if (now == dst) {
            finalAnswer = cost;
            break;
        }

        // Arrival to destination
        if (now == dst) {
            free(dist); 
            free(heap.data);
            return cost;
        }

        // Stops count over
        if (stops >= k + 1) continue;

        // No chance to update
        if (cost > dist[now][stops]) continue;

        Node* cur = adj[now];
        while (cur) {
            int nxt = cur->vertex;
            int nextCost = cost + cur->weight;
            int nextStops = stops + 1;

            // New shortest path
            if (nextCost < dist[nxt][nextStops]) {
                dist[nxt][nextStops] = nextCost;
                HeapNode nxtNode = {nextCost, nxt, nextStops};
                push(&heap, nxtNode);
            }
            cur = cur->next;
        }
    }

    // free Memory
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);
    free(heap.data);
    for (int i = 0; i < n; i++) {
        Node* cur = adj[i];
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(adj);
    return finalAnswer;
}