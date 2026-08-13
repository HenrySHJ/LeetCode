# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    char left_ch;
    char right_ch;
} Node;

Node tree[400005];
char S[100005];

// Making parent node as merged node
Node merge(Node left, Node right, int left_len, int right_len) {
    Node res;
    // Setting left and right char
    res.left_ch = left.left_ch;
    res.right_ch = right.right_ch;

    // Setting max length
    res.max_len = max(left.max_len, right.max_len);
    if (left.right_ch == right.left_ch) 
        res.max_len = max(res.max_len, left.suff_len + right.pref_len);
    
    // Setting prefix length
    res.pref_len = left.pref_len;
    if (left.pref_len == left_len && left.right_ch == right.left_ch) 
        res.pref_len += right.pref_len;
    
    // Setting suffix length
    res.suff_len = right.suff_len;
    if (right.suff_len == right_len && left.right_ch == right.left_ch) 
        res.suff_len += left.suff_len;
    
    return res;
}

// Preprocessing : Make Segment Tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = (Node){1, 1, 1, S[start], S[start]};
        return;
    }
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
}

// Updating segment tree
void update(int node, int start, int end, int idx, char ch) {
    if (start == end) {
        S[idx] = ch;
        tree[node] = (Node){1, 1, 1, ch, ch};
        return;
    }

    int mid = (start + end) / 2;

    if (idx <= mid)
        update(2 * node, start, mid, idx, ch);
    else
        update(2 * node + 1, mid + 1, end, idx, ch);

    tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
}

int* longestRepeating(char* s, char* queryCharacters, int* queryIndices, int queryIndicesSize, int* returnSize) {
    int n = strlen(s);
    int k = queryIndicesSize;
    strcpy(S, s);

    // Build Segment Tree : O(nlgn)
    build(1, 0, n - 1);

    // Allocate answer array
    int* ans = (int*)malloc(sizeof(int) * k);
    *returnSize = k;

    // Update segment tree for every query : O(klgn)
    for (int i = 0; i < k; i++) {
        update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
        ans[i] = tree[1].max_len;
    }

    return ans;
}