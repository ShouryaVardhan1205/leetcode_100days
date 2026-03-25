/**
 * Definition for a binary tree node.
 */


// Queue structure
struct Queue {
    struct TreeNode* data[2000];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Enqueue
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

// Dequeue
struct TreeNode* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);

    int levelCount = 0;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front;  // nodes in current level

        result[levelCount] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[levelCount] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(&q);
            result[levelCount][i] = node->val;

            if (node->left)
                enqueue(&q, node->left);
            if (node->right)
                enqueue(&q, node->right);
        }

        levelCount++;
    }

    *returnSize = levelCount;
    return result;
}