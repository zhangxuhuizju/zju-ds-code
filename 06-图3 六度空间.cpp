#include<cstdio>
#include<queue>
using namespace std;
int G[10001][10001] = {0};
int BFS(int i, int n){
	int num = 0;
	int temp, flag = 0;
	int* meet = new int[n+1]();
	queue<int> q;
	q.push(i);
	meet[i] = 1;
	++num;
	while(q.size()){
		temp = q.front();
		q.pop();
		for(int j = 1 ; j <= n; ++j){
			if(meet[j]==0&&G[temp][j]){
				q.push(j);
				meet[j] = meet[temp]+1;
				if(meet[j]==8){
					delete[] meet;
					return num; 	
				}
				++num;
			}
		}
		
	}
	delete[] meet;
	return num;
}
int main(){
	int n, m, num1, num2, num;
	scanf("%d %d", &n, &m);
	for(int i=0; i!=m; ++i){
		scanf("%d %d", &num1, &num2);
		G[num1][num2] = G[num2][num1] = 1;
	}
	for(int i = 1; i <= n; ++i){
		num = BFS(i, n);
		printf("%d: %.2f%%\n", i, double(num)/n*100 );
	}
	return 0;
}
