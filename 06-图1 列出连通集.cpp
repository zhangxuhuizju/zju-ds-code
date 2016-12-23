#include<iostream>
#include<queue>
using namespace std;
int G[10][10] = {0};
int DFS[10] = {0};
int BFS[10] = {0};
void DFS_(int v, int n){
	DFS[v] = 1;
	cout << v << " ";
	for(int i = 0; i != n; ++i){
		if(G[v][i]&&(!DFS[i])) DFS_(i, n);
	}
}
void BFS_(int v, int n){
	queue<int> q;
	BFS[v] = 1;
	int num;
	q.push(v);
	while(q.size()){
		num = q.front();
		cout << num << " ";
		q.pop();
		for(int i = 0; i != n; ++i){
			if(G[num][i]&&(!BFS[i])){
				q.push(i);
				BFS[i] = 1;
			}
		}
	}
}
int main(){
	int n, e, v1, v2;
	cin >> n >> e;
	for(int i = 0; i != e; ++i){
		cin >> v1 >> v2;
		G[v1][v2] = G[v2][v1] = 1;
	}
	for(int i = 0; i != n; ++i){
		if(!DFS[i]){
			cout << "{ ";
			DFS_(i, n);
			cout << "}" << endl;
		}
	}
	for(int i = 0; i != n; ++i){
		if(!BFS[i]){
			cout << "{ ";
			BFS_(i, n);
			cout << "}" << endl;
		}
	}
	return 0;
} 
