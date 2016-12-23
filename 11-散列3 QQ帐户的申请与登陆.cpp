#include<iostream>
#include<map>
using namespace std;
int main(){
	int n;
	cin >> n;
	char judge;
	long long num;
	string pass;
	map<long long, string> m;
	for(int i = 0; i !=n; ++i){
		cin >> judge >> num >> pass;
		if(judge == 'N'){
			if(m.find(num) == m.end()){
				m[num] = pass;
				cout << "New: OK" << endl;
			}else cout << "ERROR: Exist" << endl;
		}else if(judge == 'L'){
			if(m.find(num) == m.end()) cout << "ERROR: Not Exist" << endl;
			else if(m[num] != pass) cout << "ERROR: Wrong PW" << endl;
			else cout << "Login: OK" << endl;
		}
	}
	return 0;
}
