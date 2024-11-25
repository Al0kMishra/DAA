//Implement Kruskal algorithms to find out the Minimum Spanning Tree 
#include <stdio.h>

struct Edge {
    int u, v, weight;
};

int findParent(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskal(int n, int m, struct Edge edges[]) {
    qsort(edges, m, sizeof(struct Edge), compare);

    int parent[n];
    for (int i = 0; i < n; i++)
        parent[i] = -1;

    printf("Edges in MST:\n");

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV) {
            printf("%d - %d : %d\n", u, v, edges[i].weight);
            unionSets(parent, parentU, parentV);
        }
    }
}

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];
    for (int i = 0; i < m; i++) {
        printf("Enter edge (u, v, weight) for edge %d: ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal(n, m, edges);

    return 0;
}
