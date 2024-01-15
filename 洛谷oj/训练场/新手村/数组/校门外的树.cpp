#include<iostream>//ac
using namespace std;
const int MAXN = 1e4 + 5;
int vis[MAXN];
int main() {
	int L,M,begin,end,ans = 0;
	cin>>L>>M;
	while(M--) {
		cin>>begin>>end;
		for(int i = begin;i <= end;i++) vis[i] = 1;//标记移出区域
	}
	for(int i = 0;i <= L;i++) if(!vis[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
