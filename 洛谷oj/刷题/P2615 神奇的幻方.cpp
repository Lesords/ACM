#include<iostream>//ac
#include<cmath>
using namespace std;
const int MAXN = 50;
int a[MAXN][MAXN];
struct node{
	int x,y;
}last;//保存上一个点的位置
int main() {
	int n,maxx;
	cin>>n;
	//2.0才有小数，很关键！！！
	a[1][(int)ceil(n/2.0)] = 1;//初始点的位置
	maxx = n*n;//总数
	last.x = 1,last.y = int(ceil(n/2.0));
	
	for(int i = 2;i <= maxx;i++) {
		//在第一行但不在最后一列
		if(last.x==1&&last.y!=n) {
			a[last.x=n][++last.y] = i;
		}
		//在最后一列但不在第一行
		else if(last.x!=1&&last.y==n) {
			a[--last.x][last.y=1] = i;
		}
		//在第一行最后一列
		else if(last.x==1&&last.y==n) {
			a[++last.x][last.y] = i;
		}
		//既不在第一行，也不在最后一列
		else if(last.x!=1&&last.y!=n) {
			if(a[last.x-1][last.y+1]==0) {
				a[--last.x][++last.y] = i;
			}
			else {
				a[++last.x][last.y] = i;
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(j!=1) cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
