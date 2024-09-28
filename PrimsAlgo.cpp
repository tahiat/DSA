// Date: 2024-09-23
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<set>
#include<unordered_set>
using namespace std;

void insertEdge(int source, int des, vector<vector<pair<int,int>>>& adj, int val){
    adj[source].push_back({des, val});
    adj[des].push_back({source, val});

    // cost[source].push_back(val);
    // cost[des].push_back(val)
}

struct Edge {
    int source;
    int dest;
    int val;
    Edge(int s, int d, int v): source(s), dest(d), val(v){}
};

int main() {
    vector<vector<pair<int,int>>> adjacency_list(9);
    insertEdge(1, 5, adjacency_list, 2);
    insertEdge(1, 4, adjacency_list, 10);
    insertEdge(1, 2, adjacency_list, 4);
    

    insertEdge(2, 4, adjacency_list, 8);
    insertEdge(2, 3, adjacency_list, 18);
    insertEdge(3, 4, adjacency_list, 11);
    insertEdge(4, 5, adjacency_list, 5);

    insertEdge(4, 7, adjacency_list, 11);
    insertEdge(4, 8, adjacency_list, 9);
    insertEdge(7, 6, adjacency_list, 1);
    insertEdge(8, 6, adjacency_list, 2);


    unordered_set<int> vertex;
    vertex.insert(0); // just to add
    auto cmp = [](Edge& a, Edge& b) {
        return a.val > b.val;
    };
    priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);

    vertex.insert(1);
    for (int i = 0; i < adjacency_list[1].size(); i++){
        pq.push(Edge(1, adjacency_list[1][i].first,adjacency_list[1][i].second));
    }

    vector<pair<int,int>> edge;
    while(vertex.size() != 9){
        auto item = pq.top();
        pq.pop();
        if (vertex.find(item.dest) != vertex.end()){
            continue;
        }

        vertex.insert(item.dest);
        edge.push_back({item.source, item.dest});
        for (int i = 0; i < adjacency_list[item.dest].size(); i++){
            pq.push(Edge(item.dest, adjacency_list[item.dest][i].first,adjacency_list[item.dest][i].second));
        }
    }




    return 0;
}



// // Define an edge as a pair of (weight, destination_vertex)
// typedef std::pair<int, int> Edge;

// // Prim's Algorithm to find the Minimum Spanning Tree (MST)
// void primsMST(int n, std::vector<std::vector<Edge>>& adjList) {
//     // Priority queue to select edges with the minimum weight
//     std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

//     // To track vertices that are part of the MST
//     std::vector<bool> inMST(n, false);

//     // Vector to store the minimum cost (or weight) edges to reach each vertex
//     std::vector<int> minCost(n, INT_MAX);

//     // To store the parent of each node in the MST
//     std::vector<int> parent(n, -1);

//     // Start from vertex 0 (or any other vertex)
//     int startVertex = 0;
//     pq.push({0, startVertex});
//     minCost[startVertex] = 0;

//     while (!pq.empty()) {
//         // Extract the vertex with the minimum weight edge
//         int u = pq.top().second;
//         pq.pop();

//         // If the vertex is already in the MST, skip it
//         if (inMST[u]) continue;

//         // Mark the vertex as part of the MST
//         inMST[u] = true;

//         // Explore the adjacent vertices
//         for (auto& [weight, v] : adjList[u]) {
//             // If the vertex v is not in MST and weight of edge u-v is smaller than its current cost
//             if (!inMST[v] && weight < minCost[v]) {
//                 minCost[v] = weight;
//                 pq.push({weight, v});
//                 parent[v] = u;
//             }
//         }
//     }

//     // Output the edges of the MST
//     std::cout << "Edges in the Minimum Spanning Tree:\n";
//     for (int i = 1; i < n; ++i) {
//         std::cout << parent[i] << " - " << i << " with weight " << minCost[i] << "\n";
//     }
// }

// int main() {
//     int n = 5;  // Number of vertices

//     // Adjacency list of the graph, where each pair is {weight, destination_vertex}
//     std::vector<std::vector<Edge>> adjList(n);

//     // Example graph (undirected)
//     // Edge from vertex 0 to 1 with weight 2
//     adjList[0].push_back({2, 1});
//     adjList[1].push_back({2, 0});

//     // Edge from vertex 0 to 3 with weight 6
//     adjList[0].push_back({6, 3});
//     adjList[3].push_back({6, 0});

//     // Edge from vertex 1 to 2 with weight 3
//     adjList[1].push_back({3, 2});
//     adjList[2].push_back({3, 1});

//     // Edge from vertex 1 to 3 with weight 8
//     adjList[1].push_back({8, 3});
//     adjList[3].push_back({8, 1});

//     // Edge from vertex 1 to 4 with weight 5
//     adjList[1].push_back({5, 4});
//     adjList[4].push_back({5, 1});

//     // Edge from vertex 2 to 4 with weight 7
//     adjList[2].push_back({7, 4});
//     adjList[4].push_back({7, 2});

//     // Edge from vertex 3 to 4 with weight 9
//     adjList[3].push_back({9, 4});
//     adjList[4].push_back({9, 3});

//     // Run Prim's algorithm to find the Minimum Spanning Tree
//     primsMST(n, adjList);

//     return 0;
// }
