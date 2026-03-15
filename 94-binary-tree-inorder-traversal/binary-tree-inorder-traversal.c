/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int* arr, int* index){
    if(root == NULL)
        return;

    inorder(root->left, arr, index);   // Left
    arr[(*index)++] = root->val;       // Root
    inorder(root->right, arr, index);  // Right
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int* arr = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    inorder(root, arr, returnSize);

    return arr;
}