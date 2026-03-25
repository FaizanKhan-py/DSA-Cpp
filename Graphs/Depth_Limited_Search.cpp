#include <iostream>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

class Graph {
    int V;
    Node** adj;
    int* visited;

public:
    Graph(int V) {
        this->V = V;
        adj = new Node * [V];
        visited = new int[V];
        for (int i = 0; i < V; i++) {
            adj[i] = nullptr;
            visited[i] = 0;
        }
    }

    void addEdge(int u, int v) {
        Node* node = new Node{ v, adj[u] };
        adj[u] = node;

        node = new Node{ u, adj[v] };
        adj[v] = node;
    }

    void DLSUtil(int v, int depth, int limit) {
        if (depth > limit) return;
        visited[v] = 1;
        cout << v << " ";
        Node* temp = adj[v];
        while (temp != nullptr) {
            if (!visited[temp->vertex])
                DLSUtil(temp->vertex, depth + 1, limit);
            temp = temp->next;
        }
    }

    void DLS(int start, int limit) {
        for (int i = 0; i < V; i++)
            visited[i] = 0;
        DLSUtil(start, 0, limit);
        cout << endl;
    }

    ~Graph() {
        for (int i = 0; i < V; i++) {
            Node* temp = adj[i];
            while (temp) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] adj;
        delete[] visited;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    int limit = 1;
    g.DLS(0, limit); 

    return 0;
}