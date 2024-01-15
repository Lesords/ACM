#include<iostream>//ac
using namespace std;
int matrix[505][505];
int main() {
	int t,n,q;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>q;
		for(int i = 1;i <= n;i++)//初始化
			for(int j = 1;j <= n;j++) matrix[i][j] = 0;
		int a,b,c;
		while(q--) {
			cin>>a>>b>>c;
			if(a==1) {//修改行
				for(int i = 1;i <= n;i++) matrix[b][i] = c;
			}
			else {//修改列
				for(int i = 1;i <= n;i++) matrix[i][b] = c;
			}
		}
		for(int i = 1;i <= n;i++) {
			for(int j = 1;j <= n;j++) {
				if(j!=1) cout<<" ";
				cout<<matrix[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
