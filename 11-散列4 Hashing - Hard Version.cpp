#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n, min, p, err, judge;
	cin >> n;
	int* hash = new int[n]();
	int* ready = new int[n](); //下一次可以插入的元素 
	int num = n;
	for(int i = 0; i != n; ++i){
		cin >> hash[i];
		if(hash[i] % n == i)
			ready[i] = 1;
		if(hash[i] < 0) --num;
	}
	int flag = num;
	while(num){
		min = 9999999;
		judge = 1;
		for(int i = 0; i != n; ++i){
			if(ready[i] == 1 && hash[i] < min){
				min = hash[i];
				p = i;
			}
		}
		ready[p] = -1;
		if(num == flag) cout << min ;
		else cout << ' ' << min;
		--num;
		for(int i = 1; i != n; ++i){
			judge = 1;
			if(ready[(p+i)%n] == 0 && hash[(p+i)%n] >= 0){
				err = hash[(p+i)%n] % n;
				if((p+i)%n > err){
					for(int j = err; j < (p+i)%n; ++j){
						if(ready[j] != -1){
							judge = 0;
							break;
						}
					}
				}else{
					for(int j = 0; j < (p+i)%n; ++j){
						if(ready[j] != -1){
							judge = 0;
							break;
						}
					}
					for(int j = err; j < n; ++j){
						if(ready[j] != -1){
							judge = 0;
							break;
						}
					}
				}
				if(!judge) continue;
				else{
					ready[(p+i)%n] = 1;
					continue;
				}
			}
		}	
	}
	return 0;
}
