#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 1000

void addEdge(int graph[MAX][MAX], int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void vertexCover(int graph[MAX][MAX], int V) {
    bool visited[MAX] = {false};

    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && !visited[v]) {
                    visited[u] = true;
                    visited[v] = true;
                    break;
                }
            }
        }
    }

    printf("Vertex Cover: ");
    for (int i = 0; i < V; i++) {
        if (visited[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int V = 7;
    int graph[MAX][MAX] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 4, 6);

    vertexCover(graph, V);

    return 0;
}
