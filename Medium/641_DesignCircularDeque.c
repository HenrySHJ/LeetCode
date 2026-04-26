# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int size;
    int max_size;
    Node* front;
    Node* rear;
} MyCircularDeque;

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* CD = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    CD->size = 0;
    CD->max_size = k;
    CD->front = NULL;
    CD->rear = NULL;
    return CD;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (obj->size == obj->max_size) return false;
    
    if (obj->front == NULL) {
        obj->front = newNode;
        obj->rear = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
        obj->size++;
        return true;
    }

    newNode->next = obj->front;
    newNode->prev = obj->rear;
    obj->front->prev = newNode;
    obj->front = newNode;
    obj->rear->next = newNode;
    
    obj->size++;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;

    if (obj->size == obj->max_size) return false;

    if (obj->front == NULL) {
        obj->front = newNode;
        obj->rear = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
        obj->size++;
        return true;
    }

    newNode->prev = obj->rear;
    newNode->next = obj->front;
    obj->front->prev = newNode;
    obj->rear->next = newNode;
    obj->rear = newNode;

    obj->size++;
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->front == NULL) return false;

    Node* old = obj->front;
    if (obj->size == 1) {
        obj->front = NULL;
        obj->rear = NULL;
        obj->size--;
        free(old);
        return true;
    }
    
    old->next->prev = old->prev;
    obj->rear->next = old->next;
    obj->front = old->next;
    free(old);

    obj->size--;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->front == NULL) return false;

    Node* old = obj->rear;
    if (obj->size == 1) {
        obj->front = NULL;
        obj->rear = NULL;
        obj->size--;
        free(old);
        return true;
    }
    old->prev->next = obj->front;
    obj->front->prev = old->prev;
    obj->rear = old->prev;

    obj->size--;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->front) return obj->front->data;
    else return -1;
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->front) return obj->rear->data;
    else return -1;
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->front == NULL) return true;
    else return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if (obj->size == obj->max_size) return true;
    else return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    while (!myCircularDequeIsEmpty(obj)) {
        myCircularDequeDeleteFront(obj);
    }
    free(obj);
}

int main() {
    MyCircularDeque* obj = myCircularDequeCreate(4);
    bool param_1 = myCircularDequeInsertFront(obj, 3);
    bool param_2 = myCircularDequeInsertLast(obj, 2);
    bool param_3 = myCircularDequeDeleteFront(obj);
    bool param_4 = myCircularDequeDeleteLast(obj);
    int param_5 = myCircularDequeGetFront(obj);
    int param_6 = myCircularDequeGetRear(obj);
    bool param_7 = myCircularDequeIsEmpty(obj);
    bool param_8 = myCircularDequeIsFull(obj);
    
    myCircularDequeFree(obj);
}
