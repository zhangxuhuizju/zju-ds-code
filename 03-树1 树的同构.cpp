#include<iostream>
#include<string>
using namespace std;
struct tree{
	char body;
	int left;
	int right;
}T1[10],T2[10];
int buildTree(tree* T){
	int n;
	cin>>n;
	int root = -1;
	string tree;
	getline(cin,tree);
	int visited[10] = {0};
	if(n){
		for(int i=0; i!=n; ++i){
			getline(cin,tree);
			T[i].body = tree[0];
			if(tree[2] != '-'){
				T[i].left = tree[2] - '0';
				visited[T[i].left] = 1;
			}
			else T[i].left = -1;
			if(tree[4] != '-'){
				T[i].right = tree[4] - '0';
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
int isRight(int nodeT1,int nodeT2){
	if(nodeT1 == -1 && nodeT2 == -1) return 1;
	if(nodeT1 == -1 && nodeT2 != -1) return 0;
	if(nodeT1 != -1 && nodeT2 == -1) return 0;
	if(T1[nodeT1].body != T2[nodeT2].body) return 0;
	if(T1[nodeT1].left == -1 && T2[nodeT2].left == -1){
		return isRight(T1[nodeT1].right,T2[nodeT2].right);
	}
	if((T1[nodeT1].left != -1 && T2[nodeT2].left != -1)
	&& (T1[T1[nodeT1].left].body == T2[T2[nodeT2].left].body)){
		return (isRight(T1[nodeT1].left, T2[nodeT2].left)
		&& isRight(T1[nodeT1].right,T2[nodeT2].right));
	}
	else return (isRight(T1[nodeT1].left, T2[nodeT2].right)
		&& isRight(T1[nodeT1].left,T2[nodeT2].right));
}
int main(){
	int nodeT1,nodeT2;
	nodeT1 = buildTree(T1);
	nodeT2 = buildTree(T2);
	if(isRight(nodeT1, nodeT2) == 1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
