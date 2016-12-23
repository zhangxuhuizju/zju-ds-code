#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
struct point{
	int x;
	int y;
}p[100];
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
void BFS(int n, int d){
	queue<point> q;
	point f;
	for(int i = 0; i != n; ++i){
		if(first[i]){
			meet[i] = 1;
			q.push(p[i]);
		}
	}
	while(q.size()){
		f = q.front();
		if(canEscape(f.x, f.y, d)){
			cout << "Yes" << endl;
			return;
		}
		q.pop();
		for(int i = 0; i != n; ++i){
			if(meet[i] == 0 && canjump(f.x, f.y, p[i].x, p[i].y, d)){
				q.push(p[i]);
				meet[i] = 1;
			}
		}
	}
	cout << "No" << endl;
	return;
}
int main(){
	int n, d;
	cin >> n >> d;
	for(int i = 0; i != n; ++i){
		cin >> p[i].x >> p[i].y;
		if(canfirst(p[i].x, p[i].y, d)) first[i] = 1;
	}
	BFS(n, d);
	return 0;
}
