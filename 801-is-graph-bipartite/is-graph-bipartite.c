#include <stdbool.h>
#include <stdlib.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize) {
    int color[101];

    // Initialize all nodes as uncolored
    for (int i = 0; i < graphSize; i++) {
        color[i] = -1;
    }

    // Check all components
    for (int start = 0; start < graphSize; start++) {
        if (color[start] != -1)
            continue;

        // BFS queue
        int queue[101];
        int front = 0, rear = 0;

        queue[rear++] = start;
        color[start] = 0;

        while (front < rear) {
            int node = queue[front++];

            for (int i = 0; i < graphColSize[node]; i++) {
                int neighbor = graph[node][i];

                // If not colored
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    queue[rear++] = neighbor;
                }
                // If same color → not bipartite
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
    }

    return true;
}