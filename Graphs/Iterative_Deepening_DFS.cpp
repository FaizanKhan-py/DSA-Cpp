#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

struct Graph {
    int n;
    Node** adj;
};

Graph* createGraph(int n) {
    Graph* g = new Graph;
    g->n = n;
    g->adj = new Node * [n];
    for (int i = 0; i < n; i++)
        g->adj[i] = nullptr;
    return g;
}

void addEdge(Graph* g, int u, int v) {
    Node* node = new Node{ v, g->adj[u] };
    g->adj[u] = node;
    node = new Node{ u, g->adj[v] };
    g->adj[v] = node;
}

bool DLS(Graph* g, int current, int target, int limit, bool visited[]) {
    if (current == target) return true;
    if (limit <= 0) return false;
    visited[current] = true;
    Node* temp = g->adj[current];
    while (temp != nullptr) {
        if (!visited[temp->vertex] && DLS(g, temp->vertex, target, limit - 1, visited))
            return true;
        temp = temp->next;
    }
    visited[current] = false;
    return false;
}

void IDDFS(Graph* g, int start, int target, int maxDepth) {
    for (int depth = 0; depth <= maxDepth; depth++) {
        bool visited[g->n] = { false };
        if (DLS(g, start, target, depth, visited)) {
            cout << "Found at depth " << depth << endl;
            return;
        }
    }
    cout << "Not found\n";
}

int main() {

    int n = 5;
    Graph* g = createGraph(n);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    int start = 0, target = 4, maxDepth = 3;
    IDDFS(g, start, target, maxDepth);
    return 0;
}