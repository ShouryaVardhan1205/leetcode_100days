/**
 * Definition for a binary tree node.
 */


int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // Queue implementation
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    // Result array
    int* result = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    // Push root
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* current = queue[front++];

            // If it's the last node of this level
            if (i == levelSize - 1) {
                result[(*returnSize)++] = current->val;
            }

            if (current->left)
                queue[rear++] = current->left;

            if (current->right)
                queue[rear++] = current->right;
        }
    }

    return result;
}