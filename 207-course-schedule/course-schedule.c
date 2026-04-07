#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if all courses can be finished
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    
    // Step 1: Create indegree array
    int* indegree = (int*)calloc(numCourses, sizeof(int));

    // Step 2: Create adjacency list
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int)); // max possible edges
    }

    // Step 3: Fill graph and indegree
    for (int i = 0; i < prerequisitesSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];

        graph[b][graphSize[b]++] = a;
        indegree[a]++;
    }

    // Step 4: Queue for BFS
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    // Add nodes with indegree 0
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Step 5: Process queue
    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < graphSize[node]; i++) {
            int neighbor = graph[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    // Step 6: Free memory
    for (int i = 0; i < numCourses; i++) {
        free(graph[i]);
    }
    free(graph);
    free(graphSize);
    free(indegree);
    free(queue);

    // Step 7: Check result
    return count == numCourses;
}