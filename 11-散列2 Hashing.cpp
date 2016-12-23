#include<iostream>
#include<cmath>
using namespace std;
int isPrime(int n){
	if(n == 1) return 0;
	if(n == 2) return 1;
	for(int i = 2; i <= sqrt(n); ++i){
		if(n%i == 0) return 0;
	}
	return 1;
}
int main(){
	int m, n, num, prob, move1, move2;
	cin >> m >> n;
	if(!isPrime(m)){
		do{
			++m;
		}while(!isPrime(m));
	}
	int* hash = new int[m]();
	for(int i = 0; i != n; ++i){
		cin >> num;
		if(i == 0){
			cout << num%m;
			hash[num%m] = num;
		}else if(hash[num%m] == 0){
			cout << ' ' << num%m;
			hash[num%m] = num;
		}else{
			prob = 1;
			while(prob <= m){
				move1 = (num%m + prob*prob)%m;
//				move2 = (m%num - prob*prob)%m;
//				if(move2 < 0)  move2 += m;
				if(hash[move1] == 0){
					hash[move1] = num;
					cout << ' ' << move1;
					break;
				}
//				}else if(hash[move2] == 0){
//					hash[move2] = num;
//					cout << ' ' << move2;
//					break;
//				}
				++prob;
			}
			if(prob == m+1) cout << ' ' << "-";
		}
	}
	cout << endl;
	return 0;
}
