#include<iostream>
using namespace std;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	int* p=new int[n];
	int* stack=new int[n];
	int* visited=new int[n];
	int pop,top=0;	
	int judge=1;
	for(int i=0;i!=k;++i){
		top=0;
		judge=1;
		for(int j=0;j!=m;++j){
			if(j==0) stack[j]=1;
			else stack[j]=-1;
		}
		for(int j=0;j!=n;++j){
			cin>>p[j];
			visited[j]=0;
		}
	    for(int j=0;j!=n;++j){
	    	pop=p[j];
	    	visited[p[j]]=1;
			if(stack[top]==pop){
				if(top!=0) --top;
				else ++stack[top];
			}
			else if(stack[top]<pop){
				for(int q=stack[top]+1;q<pop;++q){
					if(visited[q]==0){
						++top;
						if(top>=m-1){
							judge=0;
							break;
						}
						stack[top]=q;
						visited[q]=1;
					}
				}
			}
			else if(stack[top]>pop) judge=0;
			if(judge==0) break;
		}
		if(judge==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}
	
