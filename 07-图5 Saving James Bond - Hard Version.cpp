#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
	int x;
	int y;
}p[100];
bool cmp(int a, int b){
	return p[a].x*p[a].x + p[a].y*p[a].y < p[b].x*p[b].x + p[b].y*p[b].y;
}
int meet[100] = {0};
int first[100] = {0};
int canfirst(int x, int y, int d){
	if(x*x + y*y <= (7.5 + d)*(7.5 + d)) return 1;
	return 0;
}
int canEscape(int x, int y, int d){
	if(50 - abs(x) <= d || 50 - abs(y) <= d) return 1;
	return 0;
}
int canjump(int x1, int y1, int x2, int y2, int d){
	if((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= d*d) return 1;
	return 0;
}
void printRoad(int f, int* road, int n){
	int jumpNum = 0;
	int *path = new int[n];
	while(f != -1){
		path[jumpNum++] = f;
		f = road[f];
	}
	cout << jumpNum+1 << endl;
	for(int i = jumpNum-1; i >= 0; --i){
		cout << p[path[i]].x << ' ' <<p[path[i]].y << endl;
	}
	return;
}
void BFS(int n, int d){
	queue<int> q;
	int f;
	int* first_ = new int[n]();
	int* road = new int[n]();
	int fNum = 0;
	for(int i = 0; i != n; ++i){
		if(first[i]){
			meet[i] = 1;
			road[i] = -1;
			first_[fNum++] = i;
		}
	}
	sort(first_, first_+fNum, cmp);
	for(int i = 0; i != fNum; ++i) q.push(first_[i]);
	while(q.size()){
		f = q.front();
		if(canEscape(p[f].x, p[f].y, d)){
			printRoad(f, road, n);
			return;
		}
		q.pop();
		for(int i = 0; i != n; ++i){
			if(meet[i] == 0 && canjump(p[f].x, p[f].y, p[i].x, p[i].y, d)){
				q.push(i);
				meet[i] = 1;
				road[i] = f;
			}
		}
	}
	cout << 0 << endl;
	return;
}
int main(){
	int n, d;
	cin >> n >> d;
	if( d + 7.5 >= 50 ){
		cout << 1 << endl;
		return 0;
	}
	for(int i = 0; i != n; ++i){
		cin >> p[i].x >> p[i].y;
		if(canfirst(p[i].x, p[i].y, d)) first[i] = 1;
	}
	BFS(n, d);
	return 0;
}
