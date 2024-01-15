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
	int t,x,y,z;
	cin>>t;
	while(t--) {
		cin>>x>>y>>z;
		int a,b,c,flag = 0;
		//x=max(a,b), y=max(a,c), z=max(b,c)
		if(x==y) {//三种可能相等的情况
			a = x;
			b = z;
			c = z;
		}
		else if(x==z){
			b = x;
			a = c = y;
		}
		else if(y==z) {
			c = z;
			a = b = x;
		}
		else flag = 1;
		if(x!=max(a,b)||y!=max(a,c)||z!=max(b,c)) {
			flag = 1;//验证答案
		}
		if(flag) {
			cout<<"NO\n";continue;
		}
		else {
			cout<<"YES\n";
			cout<<a<<' '<<b<<' '<<c<<endl;
		}
	}
	return 0;
}
