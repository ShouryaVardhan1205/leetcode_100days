/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    // Queue for BFS
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    // Result arrays
    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    int level = 0;
    int leftToRight = 1;

    queue[rear++] = root;

    while (front < rear) {
        int size = rear - front;
        result[level] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            int index = leftToRight ? i : (size - 1 - i);
            result[level][index] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        leftToRight = !leftToRight; // Toggle direction
        level++;
    }

    *returnSize = level;
    return result;
}