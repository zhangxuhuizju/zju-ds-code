#include<iostream>
using namespace std;
struct huffmanT{
	char body;
	int weight;
	huffmanT* left;
	huffmanT* right;
	int height;
}T[63];
void insert(int n, huffmanT** heap, huffmanT* T){
	for(; heap[n/2]->weight > T->weight; n /= 2){
		heap[n] = heap[n/2]; 
	}
	heap[n] = T;
	return;
}
huffmanT* delMin(huffmanT** heap, int n){
	huffmanT* max = heap[1];
	huffmanT* temp = heap[n];
	int parent, child;
	for(parent = 1; parent*2 <= n-1; parent = child){
		child = parent*2;
		if( (child!=n-1) && (heap[child]->weight > heap[child+1]->weight) )
            ++child;
        if( temp->weight <= heap[child]->weight ) break; 
        else  
            heap[parent] = heap[child];
	}
	heap[parent] = temp;
	return max;
}
huffmanT* buildHuffmanTree(huffmanT** heap,int n){
	while( 1 ){
		huffmanT* T = new huffmanT;
		T->body = '?';
		T->left = delMin(heap, n); n--;
		T->right = delMin(heap, n); n--;
		T->weight = T->left->weight + T->right->weight;
		T->height = 0;
		if( !n ) return T;
		n++;
		insert(n, heap, T);
	}	
}
int code = 0;
void getcode(huffmanT* T){
	if( !T ) return;
	if (T->left) T->left->height = T->height + 1;
	if (T->right) T->right->height = T->height + 1;
	if(T->body != '?') code += (T->weight)*(T->height);
	getcode(T->left);
	getcode(T->right);
}
int judge(string* num, int n){
	for(int i = 0; i != n ;++i){
		for(int j =0; j !=n; ++j){
			if(i==j) continue;
			if( num[i].find(num[j]) == 0 ) return 0;
		}
	}
	return 1;
}
int main(){
	int n, m;
	cin >> n;
	char body;
	string* num = new string[n];
	huffmanT** heap = new huffmanT*[n+1];
	T[0].weight = -1;
	heap[0] = &T[0];
	for(int i = 1; i <= n; ++i){
		cin >> T[i].body >> T[i].weight;
		T[i].left = 0;
		T[i].right = 0;
		T[i].height = 0;
		insert(i, heap, &T[i]);
	}
	huffmanT* huffman = buildHuffmanTree(heap, n);
	huffman->height = 0;
	getcode(huffman);
	cin >> m;
	int code_ = 0;
	for(int i = 0; i != m; ++i){
		code_ = 0;
		for(int j = 0; j !=n; ++j){
			cin >> body >> num[j];
			code_ += num[j].length() * T[j+1].weight;
		}
		if(code_ == code && judge(num, n)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
