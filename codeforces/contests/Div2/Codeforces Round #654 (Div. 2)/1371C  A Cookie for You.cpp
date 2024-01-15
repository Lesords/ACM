#include<iostream>//ac
#include<cstdio>
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
int main() {
	int t;
	ll a,b,n,m;
	cin>>t;
	while(t--) {
		cin>>a>>b>>n>>m;
		//a为一类饼干，b为二类饼干
		//n可以挑走任意种类饼干
		//m只会挑走两类中较少的一类饼干
		
		//所以a，b中的较小值需大于等于m，才能满足m都选到饼干
		//剩余的饼干数大于等于n即可满足n也都能得到饼干
		
		if(min(a,b)>=m&&a+b>=n+m) cout<<"Yes\n";
		else cout<<"NO\n";
	}
	return 0;
}
