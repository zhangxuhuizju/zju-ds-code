#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct student{
	int task[6] = {-2, -2, -2, -2, -2, -2};
	int fullMark = 0;
	int final = 0;
	int out = 0;
	int id;
	int rank;
}stu[10001];
bool cmp(student a, student b){
	if(a.final != b.final) return a.final > b.final;
	else if(a.fullMark != b.fullMark) return a.fullMark > b.fullMark;
	else return a.id < b.id;
}
int main(){
	int n, k, m;
	int id, num, score;
	cin >> n >> k >> m;
	int task[6];
	for(int i = 1; i <= k; ++i) cin >> task[i];
	for(int i = 1; i <= n; ++i) stu[i].id = i;
	for(int i = 0; i != m; ++i){
		scanf("%d %d %d", &id, &num, &score);
		if(score > stu[id].task[num]){
			stu[id].task[num] = score;
		}		
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if(stu[i].task[j] >= 0) {
				stu[i].final += stu[i].task[j];
				stu[i].out = 1;
				if(stu[i].task[j] == task[j]) ++stu[i].fullMark;
			}
		}
	}
	sort(stu+1, stu+n+1, cmp);
	int outNum = 1;
	for(int i = 1; i <= n; ++i){
		if(stu[i].out){
			if(stu[i].final == stu[i-1].final){
				stu[i].rank = stu[i-1].rank;
				++outNum;
			}else stu[i].rank = outNum++;
			printf("%d", stu[i].rank);
			printf(" %.5d %d", stu[i].id, stu[i].final);
			for(int j = 1; j <= k; ++j){
				if(stu[i].task[j] >= 0) printf(" %d", stu[i].task[j]);
				else if(stu[i].task[j] == -1) printf(" 0");
				else printf(" -");
			}
			printf("\n");
		}
	}
	return 0;
} 
