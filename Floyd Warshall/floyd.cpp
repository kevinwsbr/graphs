#include <bits/stdc++.h> 
#include <fstream>

#define INF 99999

using namespace std; 

int vert, edges;

void printSolution(int **dist) 
{ 
	cout<<"These are the shortest distances between each pair of vertices:" << endl;
	for (int i = 0; i < vert; i++) 
	{ 
		for (int j = 0; j < vert; j++) 
		{ 
            if(i != j) {
                cout << "(" << i << ", " << j << ") = ";
                
                if(dist[i][j] == INF)
                    cout << "Unreachable" << endl;
                else
                    cout << dist[i][j] << endl;
            }    
		} 
	} 
} 

void floydWarshall (int **graph) 
{ 
	int **dist=  new int*[vert];

    for (int i = 0; i < vert; i++)
        dist[i] = new int[vert];

	for (int i = 0; i < vert; i++) 
		for (int j = 0; j < vert; j++) 
			dist[i][j] = graph[i][j]; 

	for (int k = 0; k < vert; k++) 
	{ 
		for (int i = 0; i < vert; i++) 
		{ 
			for (int j = 0; j < vert; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
	printSolution(dist); 
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
        
        for (int i = 0; i < vert; i++) {
            for (int j = 0; j < vert; j++) {
                graph[i][j] = INF; 

                if (i == j)
                    graph[i][j] = 0;
            }
        }

        while(inFile >> u >> v >> w)
            graph[u][v] = w;
            
	    floydWarshall(graph); 
    }

    inFile.close();

	return 0; 
}
