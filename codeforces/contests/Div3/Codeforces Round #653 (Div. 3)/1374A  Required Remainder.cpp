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
	ll x,y,n;
	cin>>t;
	while(t--) {
		cin>>x>>y>>n;//x�ı���+y
		ll tmp = n/x;//n�ķ�Χ��k���
		if(tmp*x+y<=n) cout<<tmp*x+y<<endl;
		else cout<<(tmp-1)*x+y<<endl;//������n
	}
	return 0;
}
