#include<iostream>
#include<string>
using namespace std;
struct Tree{
	int left;
	int right;
}T[10];
void printLeave(int root){
	int queue[10]={0};
	int front = 0;
	int rear = 0;
	int flag = 0;
	queue[rear++] = root;
	while(front != rear){
		++front;
		if(T[queue[front-1]].left == -1
		&& T[queue[front-1]].right == -1){
			if(flag == 0){
				flag = 1;
				cout<<queue[front-1];
			}else cout<<" "<<queue[front-1];
		}
		if(T[queue[front-1]].left != -1)
			queue[rear++] = T[queue[front-1]].left;
		if(T[queue[front-1]].right != -1)
			queue[rear++] = T[queue[front-1]].right;	
	}
	cout<<endl;
	return;
}
int buildTree(Tree* T){
	int n;
	cin>>n;
	int root = -1;
	string tree;
	getline(cin,tree);
	int visited[10] = {0};
	if(n){
		for(int i=0; i!=n; ++i){
			getline(cin,tree);
			if(tree[0] != '-'){
				T[i].left = tree[0] - '0';
				visited[T[i].left] = 1;
			}
			else T[i].left = -1;
			if(tree[2] != '-'){
				T[i].right = tree[2] - '0';
				visited[T[i].right] = 1;
			}
			else T[i].right = -1;
		}
		for(int i=0; i!=n; ++i){
			if(visited[i] != 1){
				root = i;
				break;
			}
		}
	}
	return root;
}
int main(){
	int root;
	root = buildTree(T);
	printLeave(root);
	return 0;
}
