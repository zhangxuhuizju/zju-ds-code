#include<iostream>
using namespace std;
struct tree{
	int body;
	tree* left;
	tree* right;
};
tree* buildTree(tree* T, int num){
	if( !T ){
		T = new tree;
		T->body = num;
		T->left = 0;
		T->right = 0;
	}
	else{
		if( T->body > num ){
			T->left =  buildTree(T->left, num);
		}else T->right = buildTree(T->right, num);
	}
	return T;
}
int isSame(tree* T1, tree* T2){
	if(T1 == 0 && T2 != 0) return 0;
	else if(T1 != 0 && T2 == 0) return 0;
	else if(T1 == 0 && T2 == 0) return 1;
	else if(T1->body != T2->body) return 0;
	else return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
}
int main(){
	int n, l, num;
	tree* T = 0;
	tree* C = 0;
	cin >> n;
	while( n ){
		cin >> l;
		T = 0;
		for(int i = 0; i != n; ++i){
			cin >> num;
			T = buildTree(T, num);
		}
		for(int i = 0; i != l; ++i){
			C = 0;
			for(int j =0; j != n; ++j ){
				cin >> num;
				C = buildTree(C, num);
			}
			if(isSame(T, C)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cin >> n;
	}
	return 0;
}
