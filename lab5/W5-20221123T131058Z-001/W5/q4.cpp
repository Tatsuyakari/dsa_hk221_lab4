// Some helping functions

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX;
    int min_index;
    for (int v = 0; v < n; v++) {
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int Dijkstra(int** graph, int src, int dst) {
    // TODO: return the length of shortest path from src to dst.
    // If there is no path, return -1.
    // STUDENT ANSWER
    int n = sizeof(graph) / sizeof(graph[0]);
    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist[dst];
}


