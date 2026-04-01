#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.


// DFS returning state
int dfs(struct TreeNode* root, int *cameras) {
    if (root == NULL)
        return 2; // covered

    int left = dfs(root->left, cameras);
    int right = dfs(root->right, cameras);

    // If any child needs camera
    if (left == 0 || right == 0) {
        (*cameras)++;
        return 1; // has camera
    }

    // If any child has camera
    if (left == 1 || right == 1) {
        return 2; // covered
    }

    return 0; // needs camera
}

int minCameraCover(struct TreeNode* root) {
    int cameras = 0;

    if (dfs(root, &cameras) == 0)
        cameras++;

    return cameras;
}