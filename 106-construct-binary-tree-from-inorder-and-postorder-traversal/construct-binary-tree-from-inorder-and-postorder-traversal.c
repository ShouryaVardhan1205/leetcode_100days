struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[(*postIndex)--];
    root->left = root->right = NULL;

    int mid = inStart;
    while (inorder[mid] != root->val) mid++;

    // Right before left (postIndex goes right to left)
    root->right = build(inorder, postorder, mid + 1, inEnd,   postIndex);
    root->left  = build(inorder, postorder, inStart, mid - 1, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}