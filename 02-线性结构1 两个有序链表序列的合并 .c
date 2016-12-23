#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Read(){
	int n,i;
	scanf("%d",&n);
	List link = (List)malloc(sizeof(struct Node));
	List temp;
	List L=(List)malloc(sizeof(struct Node));
	L->Next=link;
	for(i=0;i!=n;++i){
		scanf("%d",&link->Data);
		link->Next=NULL;
		if(i!=0) temp->Next=link;
		temp=link;
		link = (List)malloc(sizeof(struct Node));
	}
	if(n==0) L->Next=NULL; 
	return L;
}
List Merge( List L1, List L2 ){
	int s=0;
	List L = (List)malloc(sizeof(struct Node));
	List link = (List)malloc(sizeof(struct Node));
	List temp,tem;
	L->Next=link;
	int judge=0;
	if(L1->Next==NULL && L2->Next==NULL){
		L->Next==NULL;
	}
	else{
		while(L1->Next!=NULL&&L2->Next!=NULL){
			if(L1->Next->Data >= L2->Next->Data){
				link->Data=L2->Next->Data;
				link->Next=NULL;
				temp=L2->Next->Next;
				L2->Next = temp;
				if(judge!=0) tem->Next=link;
				tem=link;
				link = (List)malloc(sizeof(struct Node));
				judge=1;
			}else if(L1->Next->Data <= L2->Next->Data){
				link->Data=L1->Next->Data;
				link->Next=NULL;
				temp=L1->Next->Next;
				L1->Next = temp;
				if(judge!=0) tem->Next=link;
				tem=link;
				link = (List)malloc(sizeof(struct Node));
				judge=1;
			}
		}
		if(L1->Next!=NULL){
			tem->Next=L1->Next;
			L1->Next=NULL;
		}else{
			tem->Next=L2->Next;
			L2->Next=NULL;
		}	
	}
	if(L->Next==NULL) printf("godai");
	return L;
}
void Print( List L ){
	List link;
	int judge=0;
	if(L->Next==NULL){
		printf("NULL\n");
	}else{
		link=L->Next;
		while(link!=NULL){
			if(judge==0){
				printf("%d",link->Data);
				judge=1;
			}else printf(" %d",link->Data);
			link=link->Next;
		}
		printf("\n");
	}
	return;
}
