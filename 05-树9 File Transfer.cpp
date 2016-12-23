#include<iostream>
using namespace std;
int findRoot(int* set, int pc){
	int root = pc;
	while( set[pc] != -1 ){
		pc = set[pc];
	}
	if(set[root] != -1) set[root] = pc;
	return pc;
}
int check(int* set, int pc1, int pc2){
	return findRoot(set, pc1) == findRoot(set, pc2);
}
void union_(int* set, int pc1, int pc2){
	if( findRoot(set, pc1) == findRoot(set, pc2) ) return;
	else{
		int root = findRoot(set, pc2);
		set[ findRoot(set, pc1) ] = root;
		return;
	}
}
int main(){
	int n;
	char step;
	cin >> n;
	int pc1, pc2, judge;
	int* set = new int[n+1];
	for(int i = 1; i <= n; ++i) set[i] = -1;
	cin >> step;
	while( step != 'S' ){
		cin >> pc1 >> pc2;
		if(step == 'C'){
			judge = check(set, pc1, pc2);
			if( !judge ) cout << "no" << endl;
			else cout << "yes" << endl;
		}
		else union_(set, pc1, pc2);
		cin >> step;
	}
	judge = 0;
	for(int i = 1; i <= n; ++i){
		if(set[i] == -1) ++judge;
	}
	if(judge == 1) cout << "The network is connected." << endl;
	else cout << "There are " << judge << " components." << endl;
	return 0;
} 
