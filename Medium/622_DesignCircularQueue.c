# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct MyCircularQueue{
    int size;
    int max;
    Node* front;
    Node* rear;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* CQ = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    CQ->size = 0;
    CQ->max = k;
    CQ->front = NULL;
    CQ->rear = NULL;
    return CQ;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->max) return false;

    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    
    if (obj->front == NULL) {
        obj->front = newNode;
        obj->rear = newNode;
        newNode->next = newNode;
        obj->size++;
        return true;
    }
    obj->rear->next = newNode;
    newNode->next = obj->front;
    obj->rear = newNode;

    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) return false;

    Node* old = obj->front;
    if (obj->size == 1) {
        obj->front = NULL;
        obj->rear = NULL;
        free(old);

        obj->size--;
        return true;
    }
    obj->rear->next = old->next;
    obj->front = old->next;
    free(old);

    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->front->data;
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) return -1;
    return obj->rear->data;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->size == 0) return true;
    else return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if (obj->size == obj->max) return true;
    else return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    while (!myCircularQueueIsEmpty(obj)) {
        myCircularQueueDeQueue(obj);
    }
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/