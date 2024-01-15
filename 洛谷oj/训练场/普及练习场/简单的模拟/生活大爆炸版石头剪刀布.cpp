#include<iostream>//ac
using namespace std;
int rule[5][5] = {{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},
{0,0,1,0,1},{1,1,0,0,0}};//对应a->b的得分表
int a[205],b[205]; 
int main() {
	int n,na,nb,sc_a = 0,sc_b = 0;
	cin>>n>>na>>nb;
	for(int i = 1;i <= na;i++) cin>>a[i];//也可从0开始
	for(int i = 1;i <= nb;i++) cin>>b[i];//则直接%也为循环
	for(int i = 1;i <= n;i++) {//先减一 % 后加一可达循环
		sc_a += rule[a[(i-1)%na+1]][b[(i-1)%nb+1]];
		sc_b += rule[b[(i-1)%nb+1]][a[(i-1)%na+1]];
	}//两个都添加每次比赛的得分
	cout<<sc_a<<' '<<sc_b;
	return 0;
}
