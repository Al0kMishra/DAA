//. Dijkstra’s Algorithm (Shortest Path)
#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < n; v++) {
        if (sptSet[v] == 0 && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[n];
    int sptSet[n];  // Shortest path tree set

    // Initialize distance array and sptSet array
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance from source to itself is always 0
    dist[start] = 0;

    // Calculate shortest path for each vertex
    for (int count = 0; count < n - 1; count++) {
        // Get vertex with the minimum distance
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;  // Add it to the shortest path tree

        // Update dist value of the adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the distance array
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start;
    printf("Enter the source vertex: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
