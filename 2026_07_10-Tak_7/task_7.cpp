// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;

// vector<int> dijkstra(vector<vector<pair<int,int>>>& adj, int src) {

//     int V = adj.size();

//     // Min-heap (priority queue) storing pairs of (distance, node)
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     vector<int> dist(V, INT_MAX);

//     // Distance from source to itself is 0
//     dist[src] = 0;
//     pq.emplace(0, src);

//     // Process the queue until all reachable vertices are finalized
//     while (!pq.empty()) {
//         auto top = pq.top();
//         pq.pop();

//         int d = top.first;  
//         int u = top.second; 

//         // If this distance not the latest shortest one, skip it
//         if (d > dist[u])
//             continue;

//         // Explore all neighbors of the current vertex
//         for (auto &p : adj[u]) {
//             int v = p.first; 
//             int w = p.second; 

//             // If we found a shorter path to v through u, update it
//             if (dist[u] + w < dist[v]) {
//                 dist[v] = dist[u] + w;   
//                 pq.emplace(dist[v], v);
//             }
//         }
//     }

//     // Return the final shortest distances from the source
//     return dist;
// }


// int main() {
//     int src = 0;

//     vector<vector<pair<int,int>>> adj(5);
//     adj[0] = {{1,4}, {2,8}};
//     adj[1] = {{0,4}, {4,6}, {2,3}};
//     adj[2] = {{0,8}, {3,2}, {1,3}};
//     adj[3] = {{2,2}, {4,10}};
//     adj[4] = {{1,6}, {3,10}};

//     vector<int> result = dijkstra(adj, src);

//     for (int d : result)
//         cout << d << " ";
//     cout << " ";

//     return 0;
// }

// #include <iostream>
// #include <list>
// #include <queue>
// #include <climits>

// using namespace std;

// const int V = 5;

// void dijkstra(list<pair<int, int>> adj[], int src)
// {
//     priority_queue<pair<int, int>,
//                    vector<pair<int, int>>,
//                    greater<pair<int, int>>> pq;

//     int dist[V];

//     for (int i = 0; i < V; i++)
//         dist[i] = INT_MAX;

//     dist[src] = 0;
//     pq.push({0, src});

//     while (!pq.empty())
//     {
//         int d = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();

//         if (d > dist[u])
//             continue;

//         // Traverse linked list
//         for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
//         {
//             int v = it->first;
//             int w = it->second;

//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }

//     cout << "Shortest distances from source " << src << ":\n";

//     for (int i = 0; i < V; i++)
//         cout << "Vertex " << i << " : " << dist[i] << endl;
// }

// int main()
// {
//     list<pair<int, int>> adj[V];

//     // Add edges
//     adj[0].push_back({1, 4});
//     adj[0].push_back({2, 8});

//     adj[1].push_back({0, 4});
//     adj[1].push_back({4, 6});
//     adj[1].push_back({2, 3});

//     adj[2].push_back({0, 8});
//     adj[2].push_back({3, 2});
//     adj[2].push_back({1, 3});

//     adj[3].push_back({2, 2});
//     adj[3].push_back({4, 10});

//     adj[4].push_back({1, 6});
//     adj[4].push_back({3, 10});

//     dijkstra(adj, 0);

//     return 0;
// }

// #include <iostream>
// #include <queue>
// #include <climits>

// using namespace std;

// const int V = 5;

// // Node for adjacency list
// struct Node
// {
//     int vertex;
//     int weight;
//     Node *next;
// };

// // Function to add an edge to the linked list
// void addEdge(Node* adj[], int src, int dest, int weight)
// {
//     Node* newNode = new Node();
//     newNode->vertex = dest;
//     newNode->weight = weight;
//     newNode->next = adj[src];
//     adj[src] = newNode;
// }

// // Dijkstra Algorithm
// void dijkstra(Node* adj[], int src)
// {
//     int dist[V];

//     for (int i = 0; i < V; i++)
//         dist[i] = INT_MAX;

//     priority_queue<pair<int, int>,
//                    vector<pair<int, int>>,
//                    greater<pair<int, int>>> pq;

//     dist[src] = 0;
//     pq.push({0, src});

//     while (!pq.empty())
//     {
//         int d = pq.top().first;
//         int u = pq.top().second;
//         pq.pop();

//         if (d > dist[u])
//             continue;

//         // Traverse linked list
//         Node* temp = adj[u];

//         while (temp != NULL)
//         {
//             int v = temp->vertex;
//             int w = temp->weight;

//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }

//             temp = temp->next;
//         }
//     }

//     cout << "Shortest distances from source " << src << endl;

//     for (int i = 0; i < V; i++)
//         cout << "Vertex " << i << " : " << dist[i] << endl;
// }

// int main()
// {
//     // Array of linked lists
//     Node* adj[V];

//     for (int i = 0; i < V; i++)
//         adj[i] = NULL;

//     // Same graph as your original code
//     addEdge(adj, 0, 1, 4);
//     addEdge(adj, 0, 2, 8);

//     addEdge(adj, 1, 0, 4);
//     addEdge(adj, 1, 4, 6);
//     addEdge(adj, 1, 2, 3);

//     addEdge(adj, 2, 0, 8);
//     addEdge(adj, 2, 3, 2);
//     addEdge(adj, 2, 1, 3);

//     addEdge(adj, 3, 2, 2);
//     addEdge(adj, 3, 4, 10);

//     addEdge(adj, 4, 1, 6);
//     addEdge(adj, 4, 3, 10);

//     dijkstra(adj, 0);

//     return 0;
// }

#include <iostream>
#include <queue>
#include <climits>
#include <string>

using namespace std;

const int V = 5;

// Linked list node
struct Node
{
    string vertex;
    int weight;
    Node* next;
};

// Convert vertex name to array index
int getIndex(string vertex)
{
    if (vertex == "A") return 0;
    if (vertex == "B") return 1;
    if (vertex == "C") return 2;
    if (vertex == "D") return 3;
    if (vertex == "E") return 4;

    return -1;
}

// Convert index back to vertex name
string getVertex(int index)
{
    switch(index)
    {
        case 0: return "A";
        case 1: return "B";
        case 2: return "C";
        case 3: return "D";
        case 4: return "E";
    }
    return "";
}

// Add edge to linked list
void addEdge(Node* adj[], string src, string dest, int weight)
{
    int srcIndex = getIndex(src);

    Node* newNode = new Node();
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = adj[srcIndex];
    adj[srcIndex] = newNode;
}

// Dijkstra Algorithm
void dijkstra(Node* adj[], string source)
{
    int dist[V];

    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    priority_queue<pair<int,int>,
                   vector<pair<int,int>>,
                   greater<pair<int,int>>> pq;

    int src = getIndex(source);
    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u])
            continue;

        Node* temp = adj[u];

        while(temp != NULL)
        {
            int v = getIndex(temp->vertex);
            int w = temp->weight;

            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }

            temp = temp->next;
        }
    }

    cout << "Shortest distances from vertex " << source << endl;

    for(int i = 0; i < V; i++)
    {
        cout << source << " -> " << getVertex(i)
             << " = " << dist[i] << endl;
    }
}

int main()
{
    Node* adj[V];

    for(int i = 0; i < V; i++)
        adj[i] = NULL;

    // Graph
    addEdge(adj, "A", "B", 4);
    addEdge(adj, "A", "C", 8);

    addEdge(adj, "B", "A", 4);
    addEdge(adj, "B", "E", 6);
    addEdge(adj, "B", "C", 3);

    addEdge(adj, "C", "A", 8);
    addEdge(adj, "C", "D", 2);
    addEdge(adj, "C", "B", 3);

    addEdge(adj, "D", "C", 2);
    addEdge(adj, "D", "E", 10);

    addEdge(adj, "E", "B", 6);
    addEdge(adj, "E", "D", 10);

    dijkstra(adj, "E");

    return 0;
}
   