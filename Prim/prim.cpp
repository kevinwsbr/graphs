#include <bits/stdc++.h> 
#include <fstream>

#define INF 99999

using namespace std; 

int vert, edges;

void printSolution(int parent[], int **graph) 
{ 
	int cost = 0;
	cout << "The generated MST has the following edges:" << endl;
	for (int i = 1; i < vert; i++) {
		cout << parent[i] << " - " << i <<" with weight "<< graph[i][parent[i]] << endl; 
		cost += graph[i][parent[i]];
	}
	cout << "With total cost: " << cost << endl;
} 

int minimum(int key[], bool mst_set[]) 
{ 
	int min = INF, min_index; 

	for (int v = 0; v < vert; v++) 
		if (mst_set[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void prim(int **graph) 
{ 
	int parent[vert], key[vert]; 
	
	bool mst_set[vert]; 

	for (int i = 0; i < vert; i++) 
		key[i] = INF, mst_set[i] = false; 

	key[0] = 0; 
	parent[0] = -1; 

	for (int count = 0; count < vert - 1; count++) 
	{ 
		int u = minimum(key, mst_set); 

		mst_set[u] = true; 

		for (int v = 0; v < vert; v++) 
			if (graph[u][v] && mst_set[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 
 
	printSolution(parent, graph); 
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

        int **graph=  new int*[vert];
        
        for (int i = 0; i < vert; i++)
            graph[i] = new int[vert];

        while(inFile >> u >> v >> w)
            graph[u][v] = graph[v][u] = w;
            
	    prim(graph); 
    }

    inFile.close();

	return 0; 
} 
