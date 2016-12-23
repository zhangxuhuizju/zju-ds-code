#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct point{
	int inDegree;
	vector<int> next;
	int finishTime;
	point():inDegree(0), finishTime(0){}
}p[100];
int G[100][100];
int main(){
	int n, m;
	cin >> n >> m;
	int v1, v2;
	int num = 0, temp;
	for(int i = 0; i != m; ++i){
		cin >> v1 >> v2;
		cin >> G[v1][v2];
		++p[v2].inDegree;
		p[v1].next.push_back(v2);
	}
	queue<int> ready;
	for(int i = 0; i != n; ++i){
		if(p[i].inDegree == 0) ready.push(i);
	}
	while(ready.size()){
		temp = ready.front();
		ready.pop();
		++num;
		for(int i=0; i!=p[temp].next.size(); ++i){
			--p[p[temp].next[i]].inDegree;
			if(p[p[temp].next[i]].finishTime < p[temp].finishTime + G[temp][p[temp].next[i]])
			p[p[temp].next[i]].finishTime = p[temp].finishTime + G[temp][p[temp].next[i]];
			if(p[p[temp].next[i]].inDegree == 0){
				ready.push(p[temp].next[i]);
			}
		}
	}
	if(num != n) cout << "Impossible" << endl;
	else cout << p[temp].finishTime << endl;
	return 0;
}
