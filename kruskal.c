#include <stdio.h>

#define MAX 100
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];
int n, e;

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal() {
    Edge temp;
    int minCost = 0;

    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edges in the minimum spanning tree:\n");

    for (int i = 0; i < e; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            minCost += edges[i].w;
            union1(u, v);
        }
    }

    printf("Minimum cost: %d\n", minCost);
}

int main() {
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal();
    return 0;
}
