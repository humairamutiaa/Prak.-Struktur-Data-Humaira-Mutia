#include <stdio.h>

void DFS(int);
int G[10][10], visited[10], n; // n is number of vertices and graph is stored in array G[10][10]

int main() {
    int i, j;

    // Read the number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Read the adjacency matrix
    printf("\nEnter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // Initialize visited array to zero
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS starting from vertex 0
    printf("Depth First Search starting from vertex 0:\n");
    DFS(0);

    return 0;
}

void DFS(int i) {
    int j;

    printf("%d ", i);
    visited[i] = 1;

    for (j = 0; j < n; j++) {
        if (!visited[j] && G[i][j] == 1) {
            DFS(j);
        }
    }
}