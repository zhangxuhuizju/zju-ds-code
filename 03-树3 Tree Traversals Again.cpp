#include<iostream>
#include<string>
#include<stack>
using namespace std;

int front[30]={0};
int mid[30]={0};
int back[30]={0};

void read(int fb, int mb, int bb, int n){
	if(n == 0) return ;
	if(n == 1){
		back[bb] = front[fb];
		return;
	}
	int root = front[fb];
	back[bb+n-1] = root;
	int i;
	for(i=0; i<n; ++i){
		if(root == mid[mb+i])
			break;
	}
	int l = i;
	int r = n - l - 1;
	read(fb+1, mb, bb, l);
	read(fb+i+1, mb+i+1, bb+i, r);
}

int main(){
	int n;
	int num;
	string node;
	stack<int> s;
	int f=0,m=0;
	cin>>n;
	for(int i=0; i!=2*n; ++i){
		cin>>node;
		if(node == "Push"){
			cin>>front[f++];
			s.push(front[f-1]);
		}else{
			mid[m++] = s.top();
			s.pop();
		}
	}
	read(0,0,0,n);
	int flag=0;
	for(int i=0; i!=n; ++i){
		if(!flag){
			cout<<back[i];
			flag = 1;
		}else cout<<" "<<back[i];
	}
	cout<<endl;
	return 0;
}
