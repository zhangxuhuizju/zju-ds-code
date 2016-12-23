#include<iostream>
using namespace std;
int main(){
	int year[51] = {0};
	int n, num;
	cin >> n;
	for(int i = 0; i != n; ++i){
		cin >> num;
		++year[num];
	}
	for(int i = 0; i != 51; ++i){
		if(year[i]) cout << i << ":" << year[i] << endl;
	}
	return 0;
} 
