#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    void enqueue(int x) {
        if (isFull()) return;
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) return -1;
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }
};

class Graph {
private:
    int adj[MAX][MAX];
    int n;
public:
    Graph(int nodes) {
        n = nodes;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    void BFS(int start) {
        bool visited[MAX] = { false };
        Queue q;
        visited[start] = true;
        q.enqueue(start);
        while (!q.isEmpty()) {
            int u = q.dequeue();
            cout << u << " ";
            for (int v = 0; v < n; v++) {
                if (adj[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.enqueue(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "BFS starting from node 0: ";
    g.BFS(0);

    return 0;
}