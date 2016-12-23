#include<iostream>
#include<queue>
#define MAX 999999
using namespace std;
int city[500][500] = {0};
int money[500][500] = {0};
int findMin(int s, int n, int* meet){
	int min = MAX;
	int flag = -1;
	for(int i = 0; i != n; ++i){
		if(city[s][i] < min && meet[i] == 0){
			min = city[s][i];
			flag = i;
		}
	}
	return flag;
}
void Dijkstra(int s, int d, int n){
	int* meet = new int[n]();
	int temp, min;
	queue<int> q;
	q.push(s);
	meet[s] = 1;
	while(q.size()){
		temp = q.front();
		q.pop();
		min = findMin(s, n, meet);
		if(min != -1){
			q.push(min);
			meet[min] = 1;
			for(int i = 0; i !=n; ++i){
				if(meet[i] == 0){
					if(city[s][min] + city[min][i] < city[s][i]){
						city[s][i] = city[s][min] + city[min][i];
						money[s][i] = money[s][min] + money[min][i];
					}else if(city[s][min] + city[min][i] == city[s][i]){
						if(money[s][i] > money[s][min] + money[min][i]){
							money[s][i] = money[s][min] + money[min][i];
						}
					}
				}
			}
		}
		if(min == d) break;
	}
	cout << city[s][d] << ' ' << money[s][d] << endl;
	return;
}
int main(){
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	for(int i = 0; i != n; ++i){
		for(int j = 0 ; j != n; ++j){
			city[i][j] = money[i][j] = MAX;
		}
	}
	int v1, v2; 
	for(int i = 0; i != m; ++i){
		cin >> v1 >> v2;
		cin >> city[v1][v2] >> money[v1][v2];
		city[v2][v1] = city[v1][v2];
		money[v2][v1] = money[v1][v2];
	}
	Dijkstra(s, d, n);
	return 0;
}
