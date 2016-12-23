#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int num[1000];
int T[1001];
int findLeft(int left, int right){
	int i;
	for(i = 1; ; ++i){
		if( pow(2,i) - 1 > right -left +1 )
			break;
	}
	--i;
	return pow(2,i) - 1 > right - left + 1 - pow(2,i-1) ?
	right - left + 1 - pow(2,i-1) : pow(2,i) - 1 ;
}
void buildTree(int left, int right, int rootNum){
	if(right < left) return;
	int leftNum = findLeft(left, right);
	T[rootNum] = num[left + leftNum];
	int leftChild = rootNum * 2;
	int rightChild = rootNum * 2 + 1;
	buildTree(left, left+leftNum-1, leftChild);
	buildTree(left+leftNum+1, right, rightChild);
}
int main(){
	int n;
	cin >> n;
	for(int i = 0; i != n; ++i){
		cin >> num[i];
	}
	sort(num, num+n);
	buildTree(0, n-1, 1);
	cout << T[1];
	for(int i = 2; i <= n; ++i){
		cout << " " << T[i];
	}
	cout << endl;
	return 0;
} 
