#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES];
    int vertexCount;
} Graph;

void initGraph(Graph* g, int vertices) {
    g->vertexCount = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->adj[v][u] = 1;
}

void dfs(Graph* g, int node, bool visited[]) {
    visited[node] = true;
    printf("%d ", node);
    for (int i = 0; i < g->vertexCount; i++) {
        if (g->adj[node][i] == 1 && !visited[i]) {
            dfs(g, i, visited);
        }
    }
}

int main() {
    Graph g;
    int vertices = 6;
    initGraph(&g, vertices);

    addEdge(&g, 0, 1);
    addEdge(&g, 0, 3);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 5);
    addEdge(&g, 3, 4);
    addEdge(&g, 3, 5);

    bool visited[MAX_VERTICES] = {false};

    printf("DFS traversal starting from vertex 0:\n");
    dfs(&g, 0, visited);
    printf("\n");

    return 0;
}