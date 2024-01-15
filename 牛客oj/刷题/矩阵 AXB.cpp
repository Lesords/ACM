#include<iostream>//ac
#define ll long long
using namespace std;
ll a[105][105],b[105][105];
int n,m,p;
ll solve(int x,int y) {
	ll ans = 0;//结果较大
	for(int i = 1;i <= m;i++) ans += a[x][i]*b[i][y];//x y!!!
	return ans;
}
int main() {
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++) cin>>a[i][j];
	cin>>p;
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= p;j++) cin>>b[i][j];
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= p;j++) {
			if(j!=1) cout<<' ';
			cout<<solve(i,j);
		}
		cout<<endl;
	}
	return 0;
}
