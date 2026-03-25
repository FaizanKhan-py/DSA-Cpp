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

    void DFSUtil(int v) {
        visited[v] = 1;
        cout << v << " ";
        Node* temp = adj[v];
        while (temp != nullptr) {
            if (!visited[temp->vertex])
                DFSUtil(temp->vertex);
            temp = temp->next;
        }
    }

    void DFS(int start) {
        DFSUtil(start);
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

    g.DFS(0);

    return 0;
}