/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

#include <stdlib.h>

struct Node* cloneGraphHelper(struct Node* node, struct Node** visited) {
    if (node == NULL) {
        return NULL;
    }
    
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }
    
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));
    
    visited[clone->val] = clone;
    
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneGraphHelper(node->neighbors[i], visited);
    }
    
    return clone;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) return NULL;
    

    struct Node* visited[105] = {NULL};
    
    return cloneGraphHelper(s, visited);
}