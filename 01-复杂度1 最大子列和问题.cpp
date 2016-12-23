#include<iostream>
using namespace std;
int main(){
	int n,max=0,sum=0;
	cin>>n;
	int* num=new int[n];
	for(int i=0;i!=n;++i){
		cin>>num[i];
		sum+=num[i];
		if(sum<0) sum=0;
		if(sum>max) max=sum;
	}
	cout<<max;
	return 0;
} 
