#include <bits/stdc++.h> 
#include <fstream>

#define INF 99999

using namespace std;

int vert, edges;

void printSolution(int *dist, int src) {
    cout << "These are the shortest distances between source and each vertex:" << endl;
    for (int i = 0; i < vert; i++) {
        cout << "(" << src << ", " << i << ") = ";
        if(dist[i] == INF)
            cout << "Unreachable" << endl;
        else
            cout << dist[i] << endl;
    }
}

int minimum(int dist[], bool dist_set[]) {
    int min = INF, index;

    for (int v = 0; v < vert; v++) {
        if (!dist_set[v] && dist[v] <= min) {
            min = dist[v];
            index = v;
        }
    }

    return index;
}

void dijkstra(int **graph, int src) {
    int dist[vert];
    bool dist_set[vert];

    for (int i = 0; i < vert; i++) {
        dist[i] = INF;
        dist_set[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < vert; i++) {

        int u = minimum(dist, dist_set);

        dist_set[u] = true;

        for (int v = 0; v < vert; v++) {
            if (dist[u] != INF && (!dist_set[v] && graph[u][v]) && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    
    printSolution(dist, src);
}
int main() {
    int u, v, w;
    ifstream inFile;

    inFile.open("in.txt");

    if (!inFile) {
        cerr << "Ops, can't read input file!";
        exit(1);
    } else {
        inFile >> vert >> edges;

        int **graph=  new int*[vert];

        for (int i = 0; i < vert; i++)
            graph[i] = new int[vert];

        while(inFile >> u >> v >> w)
            graph[u][v] = w;

	    dijkstra(graph, 2); 
    }

    inFile.close();

	return 0; 
}
