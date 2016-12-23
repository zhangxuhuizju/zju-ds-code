#include<iostream>
#define MAX 65536
using namespace std;
int G[1001][1001];
void prim(int n){
	int cost = 0, collected = 1;
	int* dist = new int[n+1];
	int minDist, min;
	for(int i = 1; i<=n; ++i){
		if(G[1][i] != MAX) dist[i] = G[1][i];
		else dist[i] = MAX;
	}
	dist[1] = 0;
	while(1){
		min = MAX;
		for(int i = 1; i <= n; ++i){
			if(dist[i] < min && dist[i] != 0){
				min = dist[i];
				minDist = i;
			}
		}
		if(min == MAX) break;
		cost += min;  
		dist[minDist] = 0;
		++collected;
		for(int i = 1; i <= n; ++i){
			if(G[minDist][i] != MAX){
				if(dist[i] != 0 && dist[i] > G[minDist][i]){
					dist[i] = G[minDist][i];
				}
			}
		}
	}
	if(collected != n) cout << -1 << endl;
	else cout << cost << endl;
	return;
}
int main(){
	int n, m;
	cin >> n >> m;
	int v1, v2;
	for(int i=1; i<=1000; ++i){
		for(int j=1; j<=1000; ++j){
			G[i][j] = MAX;
		}
	}
	for(int i=0; i != m; ++i){
		cin >> v1 >> v2;
		cin >> G[v1][v2];
		G[v2][v1] = G[v1][v2];
	}
	prim(n);
	return 0;
}
