#include <stdbool.h>

void dfs(int** rooms, int roomsSize, int* roomsColSize, int room, bool* visited) {
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; i++) {
        int key = rooms[room][i];
        if (!visited[key]) {
            dfs(rooms, roomsSize, roomsColSize, key, visited);
        }
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];

    // initialize visited array
    for (int i = 0; i < roomsSize; i++) {
        visited[i] = false;
    }

    // start DFS from room 0
    dfs(rooms, roomsSize, roomsColSize, 0, visited);

    // check if all rooms are visited
    for (int i = 0; i < roomsSize; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}