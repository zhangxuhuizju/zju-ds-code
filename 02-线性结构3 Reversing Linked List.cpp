#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct link{
	int next;
	int data;
	int add;
}s[100001];
int main(){
	int first,num,reserve,add;
	link temp;
	vector<link> v;
	cin>>first>>num>>reserve;
	for(int i=0;i!=num;++i){
		cin>>add;
		s[add].add=add;
		cin>>s[add].data>>s[add].next;
	}
	temp=s[first];
	num=0;
	while(temp.next!=-1){
		v.push_back(temp);
		++num;
		temp=s[temp.next];
	}
	v.push_back(temp);
	++num;
	if(reserve==1){
		for(int i=0;i!=v.size();++i){
			if(v[i].next!=-1){
				printf("%.5d %d %.5d\n",v[i].add,v[i].data,v[i].next);
			}else printf("%.5d %d -1\n",v[i].add,v[i].data);
			
		}
	}else if(reserve==num){
		for(int i=v.size()-1;i>=0;--i){
			if(i==0) printf("%.5d %d -1\n",v[i].add,v[i].data);
			else printf("%.5d %d %.5d\n",v[i].add,v[i].data,v[i-1].add);
		}
	}else{
		int i;
		for(i=reserve-1;i<v.size();i+=reserve){
			for(int j=0;j!=reserve;++j){
				if(j!=reserve-1)
					printf("%.5d %d %.5d\n",v[i-j].add,v[i-j].data,v[i-j-1].add);
				else{
					if(i==v.size()-1) printf("%.5d %d -1\n",v[i-j].add,v[i-j].data);
					else if(i+reserve<v.size())
						printf("%.5d %d %.5d\n",v[i-j].add,v[i-j].data,v[i+reserve].add);
					else printf("%.5d %d %.5d\n",v[i-j].add,v[i-j].data,v[i+1].add);
				}
			}
		}
		i-=reserve;
		for(i=i+1;i!=v.size();++i){
			if(v[i].next!=-1){
				printf("%.5d %d %.5d\n",v[i].add,v[i].data,v[i].next);
			}else printf("%.5d %d -1\n",v[i].add,v[i].data);
		}
	}
	return 0;
}
