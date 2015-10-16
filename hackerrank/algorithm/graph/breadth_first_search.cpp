// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define INF 65535




class Dijkstra {
public:
	static void debug(int u) {

	}

	static void dijkstra(int** graph, int numNodes, int start) {
		// vector<int> dist(numNodes, INF);
		int *dist = new int[numNodes];        
		bool *s = new bool[numNodes];

		memset(s, false, numNodes);
		memset(dist, INF, numNodes);

		int min, v;
		for (int i = 0; i < numNodes; i++){
			dist[i] = graph[start][i];
		}
		dist[start] = 0;
		s[start] = true;

		while (true){
			min = INF;
			v = -1;  //CLRS = u

			//�ҵ���С��dist 
			for (int i = 0; i < numNodes; i++){
				if (!s[i]){
					if (dist[i] < min) {
						min = dist[i];
						v = i;
					}
				}
			}

			if (v == -1)
				break;//�Ҳ������̵�·���� 

			//�������·�� 
			s[v] = true;

			// Relax
			for (int i = 0; i < numNodes; i++){
				if (!s[i] &&
					graph[v][i] != INF &&
					(dist[v] + graph[v][i]) < dist[i]) {
					dist[i] = dist[v] + graph[v][i];					
				}
			}
		}
		for (int i = 0; i < numNodes; i++) {
			if (i != start) {
				if (dist[i] == INF)
					cout << -1;
				else
					cout << dist[i] * 6;
				if (i != numNodes - 1)
					cout << " ";
			}
		}
		cout << std::endl;
		// return dist; 
	}
};

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	/*int[][] W = {
		{ 0, 1, 4, inf, inf, inf },
		{ 1, 0, 2, 7, 5, inf },
		{ 4, 2, 0, inf, 1, inf },
		{ inf, 7, inf, 0, 3, 2 },
		{ inf, 5, 1, 3, 0, 6 },
		{ inf, inf, inf, 2, 6, 0 } };
	*/
	int numt;
	cin >> numt;
	for (int i = 0; i < numt; i++) {
		int numNodes, numEdges, startPoint;
		cin >> numNodes;
		cin >> numEdges;
		// create 2d array
		//int **matrix = new int[numNodes][numNodes];
		//auto matrix = new int[numNodes][numNodes];

		int **matrix = new int*[numNodes];
		//int i,j;
		for (int i = 0; i < numNodes; ++i) {
			matrix[i] = new int[numNodes];
			for (int j = 0; j < numNodes; ++j) {
				matrix[i][j] = INF;
			}
		}

		for (int j = 0; j < numEdges; j++) {
			int s, e;
			cin >> s >> e;
			s = s - 1;
			e = e - 1;
			matrix[s][e] = 1;
			matrix[e][s] = 1;
		}
		cin >> startPoint;
		Dijkstra::dijkstra(matrix, numNodes, startPoint - 1);
	}
	return 0;
}



