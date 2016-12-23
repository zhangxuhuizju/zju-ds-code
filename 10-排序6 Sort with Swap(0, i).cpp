#include<iostream>
using namespace std;
int main(){
	int n ,j;
	cin >> n;
	int* num = new int[n];
	int* meet = new int[n]();
	int circle = 0, order = 0;
	for(int i = 0; i != n; ++i){
		cin >> num[i];
	}
	for(int i = 0; i !=n; ++i){
		if(meet[i] ==0){
			if(num[i] == i) continue;
			else{
				j = i;
				meet[j] = 1;
				while(meet[num[j]] == 0){
					 j = num[j];
					 meet[j] = 1;
				}
				++circle;
			}
		}
	}
	for(int i = 0; i != n; ++i){
		if(meet[i]) ++order;
	}
	if(meet[0]) cout << order + circle -2;
	else cout << order + circle;
	return 0;
}
