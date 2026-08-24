# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Solution 1 : Hash Table
# define HASH_SIZE 10007 

typedef struct Node {
    int key;            
    int count;          
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int getHash(int key) {
    int hash = key % HASH_SIZE;
    if (hash < 0) hash += HASH_SIZE;
    return hash;
}

int addHash(int key) {
    int idx = getHash(key);
    Node* cur = hashTable[idx];

    while (cur != NULL) {
        if (cur->key == key) {
            cur->count++;
            return cur->count;
        }
        cur = cur->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;

    return 1;
}

void clearHashTable() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = hashTable[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int majorityElement(int* nums, int numsSize) {
    memset(hashTable, 0, sizeof(hashTable));

    int m = numsSize / 2;
    int ans = nums[0];

    for (int i = 0; i < numsSize; i++) {
        int cnt = addHash(nums[i]);
        if (cnt > m) {
            ans = nums[i];
            break;
        }
    }

    clearHashTable();
    return ans;
}

// Solution 2 : Boyer-Moore Majority Vote Algorithm
int majorityElement(int* nums, int numsSize) {
    int candidate = 0; 
    int count = 0;    

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) 
            candidate = nums[i];

        if (nums[i] == candidate) 
            count++;
        else 
            count--;
    }

    return candidate;
}