#include<iostream>
#include<map>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	map<long long, int> m;
	int n;
	cin >> n;
	long long num, min, max = 0, same = 0;
	for(int i = 0; i < 2*n; ++i){
		cin >> num;
		++m[num];
	}
	for(auto i = m.begin(); i != m.end(); ++i){
		if(i->second > max){
			max = i->second;
			min = i->first;
			same = 1;
		}else if(i->second == max){
			min = (i->first > min) ? min : i->first;
			++same;
		}
	}
	cout << min << ' ' << max;
	if(same != 1) cout << ' ' << same << endl;
	return 0;
} 
