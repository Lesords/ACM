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
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		// 4�ı�������ͬʱ��ֱ��ƽ�еı�
		if(n%4==0) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
