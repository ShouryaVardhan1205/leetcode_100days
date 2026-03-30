void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;
    
    while (curr) {
        if (curr->left) {
            struct TreeNode* rightmost = curr->left;
            while (rightmost->right) rightmost = rightmost->right;
            
            rightmost->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}