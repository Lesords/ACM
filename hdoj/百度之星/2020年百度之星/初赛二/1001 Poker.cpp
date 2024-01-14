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
const int MAXN = 1e5+5;
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m,p,cnt = 0;
		cin>>n>>m>>p;
		while(n>=m) {
			n -= m;
			cnt++;//计算回合数
			n += m*(100-p)/100;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
