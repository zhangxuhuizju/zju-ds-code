#include<stdio.h>
#include<stdlib.h>
int IsInsert(int*a, int*b, int N)
{
	int order;
	int i = 0;
	int judge=1;
	while(1)
	{
		if(a[i+1]<a[i]) break;
		i++;
	}
	order = i+1;
	for(i = order; i<N; i++)
	{
		if(a[i] != b[i])
		{
			judge = 0;
			break;
		}
	}
	if(judge==0) return 0;
	int swap=a[order];
	for(i = order; i > 0 && a[i-1]>swap; i--)
		a[i] = a[i-1];
	a[i] = swap;
	return 1;
}
void Merge(int*a,int*temp,int left,int right,int rightend)
{
	int leftend = right-1;
	int i = left;
	while(left <= leftend && right <= rightend)
	{
		if(a[left] <= a[right])
			temp[i++] = a[left++];
		else temp[i++] = a[right++];
	}
	while(left<=leftend) temp[i++] = a[left++];
	while(right<=rightend) temp[i++] = a[right++];
}
int cmp(int*a, int*b, int N)
{
	int i;
	for(i=0; i<N; i++)
	{
		if(a[i] != b[i]) return 1;
	}
	return 0;
}
int main()
{
	int N;
	int order, flag=0;
	scanf("%d",&N);
	int *oringal, *middle;
	oringal=(int*)malloc(N*sizeof(int));
	middle=(int*)malloc(N*sizeof(int));
	int i, j;
	for(i=0; i<N; i++) scanf("%d",oringal+i);
	for(i=0; i<N; i++) scanf("%d",middle+i);
	if(IsInsert(middle, oringal,N))
	{
		printf("Insertion Sort\n"); 
		printf("%d",middle[0]);
		for(i=1;i<N;i++) printf(" %d",middle[i]);
	}
	else
	{
		printf("Merge Sort\n");
		int *temp;
		temp=(int*)malloc(N*sizeof(int));
		order=1;
		while(cmp(oringal,middle,N))
		{
			for(i = 0;i < N-2*order; i += 2*order)
				Merge(oringal, temp, i, i+order, i+2*order-1);
			if(i+order < N) Merge(oringal,temp,i,i+order,N-1);
			else for(j = i ; j < N;j++) temp[j]=oringal[j];
			for(i=0;i<N;i++) oringal[i]=temp[i];
			order*=2;
		}
		for(i=0;i<N-2*order;i+=2*order)
				Merge(middle,temp,i,i+order,i+2*order-1);
			if(i+order<N) Merge(middle,temp,i,i+order,N-1);
			else for(j=i;j<N;j++) temp[j]=middle[j];
		printf("%d",temp[0]);
		for(i = 1; i<N; i++) printf(" %d",temp[i]);
		free(temp);
	}
	free(middle);
	free(oringal);
	return 0;
}
