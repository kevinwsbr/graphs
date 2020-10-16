#include <bits/stdc++.h> 
#include <fstream>

#define INF 99999

using namespace std; 

int vert, edges;

void printSolution(int **graph) {
    int cost = 0;

    cout << "The generated MST has the following edges:" << endl;
    for (int i = 0; i < vert; i++) {
        for (int j = 0; j < vert; j++) {
            if(graph[i][j] != INF) {
                cout << i << " - " << j <<" with weight "<< graph[i][j] << endl; 
                cost += graph[i][j];
            }
        }
    } 
    cout << "With total cost: " << cost << endl;
}
 
int findSet(int i, int *parent) 
{ 
	while (parent[i] != i) 
		i = parent[i]; 
	return i; 
} 

void unite(int i, int j, int *parent) 
{ 
	int a = findSet(i, parent); 
	int b = findSet(j, parent); 
	parent[a] = b; 
} 

void kruskal(int **cost, int *parent) 
{ 
    int **MST=  new int*[vert];
        
    for (int i = 0; i < vert; i++)
        MST[i] = new int[vert];

    for (int i = 0; i < vert; i++) {
        parent[i] = i; 
        for (int j = 0; j < vert; j++)
            MST[i][j] = INF; 
    }

    for (int i = 0; i < vert-1; i++)
    {
        int dist = INF, a = -1, b = -1; 
		for (int i = 0; i < vert; i++) { 
			for (int j = 0; j < vert; j++) { 
				if (findSet(i, parent) != findSet(j, parent) && cost[i][j] < dist) { 
					dist = cost[i][j]; 
					a = i; 
					b = j; 
				} 
			} 
		} 

		unite(a, b, parent); 

        MST[a][b] = dist;
    }
    printSolution(MST);
} 

int main() 
{ 
    int u, v, w;
    ifstream inFile;

    inFile.open("in.txt");
    
    if (!inFile) {
        cerr << "Ops, can't read input file!";
        exit(1);
    } else {
        inFile >> vert >> edges;
        
        int *parent, **graph;

        parent = new int[vert];
        graph =  new int*[vert];
        
        for (int i = 0; i < vert; i++)
            graph[i] = new int[vert];
        
        for (int i = 0; i < vert; i++)
            for (int j = 0; j < vert; j++)
                graph[i][j] = INF;

        while(inFile >> u >> v >> w)
            graph[u][v] = graph[v][u] = w;
            
	    kruskal(graph, parent); 
    }

    inFile.close();

	return 0; 
} 
