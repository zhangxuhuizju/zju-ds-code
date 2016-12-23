#include<iostream>
using namespace std;
int main(){
	int k;
	cin>>k;
	int* num=new int[k];
	int sum=0,begin=0,end=0,tempbegin=0,max=-1;
	for(int i=0;i!=k;++i){
		cin>>num[i];
		sum+=num[i];
		if(sum<0){
			sum=0;
			tempbegin=i+1;
		}
		else if(sum>max){
			begin=tempbegin;
			max=sum;
			end=i;	
		}
	}
	if(max==-1) cout<<"0 "<<num[0]<<" "<<num[k-1]<<endl;
	else cout<<max<<" "<<num[begin]<<" "<<num[end]<<endl;
	delete[]num; 
	return 0;
}
