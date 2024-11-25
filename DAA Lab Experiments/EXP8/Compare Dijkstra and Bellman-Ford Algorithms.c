#include <stdio.h>
#include <limits.h>
#define V 5
void dijkstra(int graph[V][V], int src) {
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Dijkstra Distances: ");
    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
    printf("\n");
}
void bellmanFord(int graph[][3], int E, int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0], v = graph[j][1], weight = graph[j][2];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    printf("Bellman-Ford Distances: ");
    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);
    printf("\n");
}
int main() {
    int graph[V][V] = {{0, 4, 0, 0, 0}, {4, 0, 8, 0, 0}, {0, 8, 0, 7, 0}, {0, 0, 7, 0, 9}, {0, 0, 0, 9, 0}};
    dijkstra(graph, 0);
    int edges[][3] = {{0, 1, 4}, {1, 2, 8}, {2, 3, 7}, {3, 4, 9}};
    bellmanFord(edges, 4, 0);
    return 0;
}