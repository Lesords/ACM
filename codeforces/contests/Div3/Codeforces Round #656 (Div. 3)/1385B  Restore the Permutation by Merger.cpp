#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int a[55],vis[55],ans[55];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n*2;i++) cin>>a[i];
		int cnt = 1;//cnt为数量
		for(int i = 1;i <= n*2;i++) {//去重即可
			if(!vis[a[i]]) {
				ans[cnt++] = a[i];
				vis[a[i]] = 1;//标记
			}
		}
		for(int i = 1;i < cnt;i++) {//输出结果
			if(i!=1) cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
	}
	return 0;
}

