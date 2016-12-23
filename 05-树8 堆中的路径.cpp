#include<iostream>
using namespace std;
#define min -100000;
void MinHeap(int* heap, int n){
	int parent = n / 2;
	int temp;
	int child;
	if( n % 2 == 1 ){
		child = heap[n-1] > heap[n] ? n : n-1;
	}else child = n;
	while(parent){	
		if(heap[parent] > heap[child]){
			temp = heap[parent];
			heap[parent] = heap[child];
			heap[child] = temp;
			child = parent;
		}else break;
		parent /= 2;
	}
	return;
}
int main(){
	int n, m, flag = 0;
	cin >> n >> m;
	int num;
	int* heap = new int[n+1];
	heap[0] = min;
	for(int i = 1; i <= n; ++i){


		cin >> heap[i];
		MinHeap(heap, i);
	}
	for(int i = 0; i != m; ++i){
		cin >> num;
		flag = 0;
		while(num != 0){
			if(!flag){
				flag = 1;
				cout << heap[num];
			}else cout << " " << heap[num];
			num /= 2;	
		}
		cout << endl;
	}
	return 0;
} 
