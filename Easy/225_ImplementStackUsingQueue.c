# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct MyStack {
    Node* top;
} MyStack;


MyStack* myStackCreate() {
    MyStack* S = (MyStack *)malloc(sizeof(MyStack));
    S->top = NULL;
    return S;
}

void myStackPush(MyStack* obj, int x) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;

    newNode->next = obj->top;
    obj->top = newNode;
}

int myStackPop(MyStack* obj) {
    if (obj->top == NULL) return -1;

    Node* old = obj->top;
    int element = old->data;
    obj->top = old->next;
    free(old);
    return element;
}

int myStackTop(MyStack* obj) {
    if (obj->top == NULL) return -1;
    else return obj->top->data;
}

bool myStackEmpty(MyStack* obj) {
    if (obj->top == NULL) return true;
    else return false;
}

void myStackFree(MyStack* obj) {
    while (!myStackEmpty) {
        myStackPop(obj);
    }
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/