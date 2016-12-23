#include<iostream>
#include<algorithm>
#define max 10000000
using namespace std;

long long animal[100][100];

int main(){
	int n, m, v1, v2;
	long long num;
	cin >> n >> m;
	for(int i = 0; i != n; ++i){
		for(int j = 0; j != n; ++j){
			if( i == j )  animal[i][j] = 0;
			else animal[i][j] = max;
		}
	}
	for(int i = 0; i != m; ++i){
		cin >> v1 >> v2;
		cin >> num;
		if(num < animal[v1-1][v2-1])
		animal[v2-1][v1-1] = animal[v1-1][v2-1] = num;
	}
	for(int i = 0; i != n; ++i){
		for(int j = 0; j != n; ++j){
			for(int k = 0; k != n; ++k){
				if(animal[i][j] + animal[j][k] < animal[i][k]){	
					animal[i][k] = animal[i][j] + animal[j][k];
					animal[k][i] = animal[i][k]; 
				} 
				
			}
		}
	}
	long long min = max, flag = 0;
	for(int i = 0; i != n; ++i){
		sort(animal[i], animal[i]+n);
		if(animal[i][n-1] < min){
			min = animal[i][n-1];
			flag = i + 1;
		}
	}
	if(!flag) cout << 0 << endl;
	else cout <<  flag  << ' ' << min << endl;
	return 0;
}
