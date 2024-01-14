#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double score[51][6],sum[6],stu[51];
int main() {
	int n,m,cnt;
	while(cin>>n>>m){//n人m课 
		cnt = 0;
		memset(sum,0,sizeof(sum));
		memset(stu,0,sizeof(stu));
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				cin>>score[i][j];
				sum[j] += score[i][j];//成绩总分 
				stu[i] += score[i][j];//学生总分
			}
		}
		for(int i=1;i<=m;i++) {
			sum[i] /= n;
		}
		for(int i=1;i<=n;i++) {
			stu[i] /= m;
		}
		for(int i=1;i<=n;i++) {//学生遍历 
			int flag=1;
			for(int j=1;j<=m;j++) {//课程遍历 
				if(score[i][j]<sum[j]) {
					flag = 0;
					break;
				}
			}
			if(flag) cnt++;
		}
		for(int i=1;i<=n;i++) {//人
			printf("%.2f",stu[i]);
			if(i!=n) cout<<' ';
			else cout<<endl;
		}
		for(int i=1;i<=m;i++) {//成绩 
			printf("%.2f",sum[i]);
			if(i!=m) cout<<' ';
			else cout<<endl;
		}
		cout<<cnt<<endl<<endl;
	}
	return 0;
}
