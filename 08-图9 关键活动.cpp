#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct point{
	int inDegree;
	int outDegree;
	vector<int> next;
	vector<int> front;
	int finishTime;
	int latestTime;
	point():inDegree(0), finishTime(0), outDegree(0), latestTime(65536){}
}p[101];
int G[101][101];
int main(){
	int n, m;
	cin >> n >> m;
	int v1, v2;
	int num = 0, temp;
	int max = 0;
	for(int i = 0; i != m; ++i){
		cin >> v1 >> v2;
		cin >> G[v1][v2];
		++p[v2].inDegree;
		++p[v1].outDegree;
		p[v1].next.push_back(v2);
		p[v2].front.push_back(v1);
	}
	queue<int> ready;
	for(int i = 1; i <= n; ++i){
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
	if(num != n){
		cout << 0 << endl;
		return 0;	
	}
	else{
		
		for(int i = 1 ; i <= n; ++i){
			if(p[i].outDegree == 0 && p[i].finishTime > max){
				max = p[i].finishTime;
			}
		}
		cout << max << endl;
	}
	for(int i =1; i<=n; ++i){
		if(p[i].outDegree == 0){
			p[i].latestTime = max;
			ready.push(i);
		}	
	}	
	while(ready.size()){
		temp = ready.front();
		ready.pop();
		for(int i = 0; i != p[temp].front.size(); ++i){
			--p[p[temp].front[i]].outDegree;
			if(p[p[temp].front[i]].latestTime > p[temp].latestTime - G[p[temp].front[i]][temp])
				p[p[temp].front[i]].latestTime = p[temp].latestTime - G[p[temp].front[i]][temp];
			if(p[p[temp].front[i]].outDegree == 0){
				ready.push(p[temp].front[i]);
			}	
		}	
	}
//	for(int i =1; i<=n ;++i){
//		cout << p[i].finishTime <<" "<< p[i].latestTime << endl;
//	}
	for(int i = 1; i <= n; ++i){
		for(int j = p[i].next.size()-1; j >= 0; --j){
			if(p[i].finishTime + G[i][p[i].next[j]] == p[p[i].next[j]].latestTime){
				cout << i << "->" << p[i].next[j] << endl;
			}
		}
	}
	return 0;
}
