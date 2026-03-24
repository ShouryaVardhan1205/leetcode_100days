/**
 * Definition for a binary tree node.
 */


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    // Base case
    if (root == NULL)
        return NULL;

    // If current node matches p or q
    if (root == p || root == q)
        return root;

    // Search in left and right subtree
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both sides return non-NULL → LCA found
    if (left != NULL && right != NULL)
        return root;

    // Otherwise return non-NULL child
    return (left != NULL) ? left : right;
}