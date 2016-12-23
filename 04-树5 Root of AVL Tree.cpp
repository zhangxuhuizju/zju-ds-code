#include<iostream>
using namespace std;
struct tree{
	int body;
	tree* left;
	tree* right;
	int height;
};
int getHeight(tree* T){
	if( !T ) return -1;
	else return T->height;
}
tree* singleRotateWithLeft(tree* T){
	tree* temp;
	temp = T->left;
	T->left = temp->right;
	temp->right = T;
	T->height = getHeight(T->left) > getHeight(T->right) ? 
				getHeight(T->left) + 1 : getHeight(T->right) + 1;
	temp->height = getHeight(temp->left) > getHeight(temp->right) ? 
				getHeight(temp->left) + 1 : getHeight(temp->right) + 1;
	return temp;
}
tree* singleRotateWithRight(tree* T){
	tree* temp;
	temp = T->right;
	T->right = temp->left;
	temp->left = T;
	T->height = getHeight(T->left) > getHeight(T->right) ? 
				getHeight(T->left) + 1 : getHeight(T->right) + 1;
	temp->height = getHeight(temp->left) > getHeight(temp->right) ? 
				getHeight(temp->left) + 1 : getHeight(temp->right) + 1;
	return temp;
}
tree* DoubleRotateWithLeft(tree* T){
	T->left = singleRotateWithRight(T->left);
	return singleRotateWithLeft(T);
}
tree* DoubleRotateWithRight(tree* T){
	T->right = singleRotateWithLeft(T->right);
	return singleRotateWithRight(T);
}
tree* AVLInsert(int n, tree* T){
	if( !T ){
		T = new tree;
		T->body = n;
		T->left = 0;
		T->right = 0;
		T->height = 0;
	}
	else if(n < T->body){
		T->left = AVLInsert(n, T->left);
		if( getHeight(T->left) - getHeight(T->right) == 2){
			if( n < T->left->body )
				T = singleRotateWithLeft(T);
			else T = DoubleRotateWithLeft(T);
		}
		
	}
	else if(n > T->body){
		T->right = AVLInsert(n, T->right);
		if( getHeight(T->right) - getHeight(T->left) == 2){
			if( n > T->right->body )
				T = singleRotateWithRight(T);
			else T = DoubleRotateWithRight(T);
		}
	}
	T->height = getHeight(T->left) > getHeight(T->right) ? 
				getHeight(T->left) + 1 : getHeight(T->right) + 1;
	return T;
}
int main(){
	int n, num;
	tree* T = 0;
	cin >> n;
	for(int i = 0; i != n; ++i){
		cin >> num;
		T = AVLInsert(num, T);
	}
	cout << T->body <<endl;
	return 0;	
}
