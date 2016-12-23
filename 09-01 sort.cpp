#include<cstdio>
#include<algorithm>
using namespace std; 
int main(){
    int n;
    scanf("%d", &n);
    int* num = new int[n];
    for(int i = 0; i != n; ++i){
        scanf("%d",num+i);
    }
    sort(num, num+n);
    printf("%d",num[0]);
    for(int i = 1; i != n; ++i){
        printf(" %d",num[i]);
    }
    return 0;
}
