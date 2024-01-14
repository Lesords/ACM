#include<iostream>//ac
#include<set>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
	fast;
	int l,q;
	cin>>l>>q;
	set<int> st;
	st.insert(0);
	st.insert(l);
	for(int i = 1;i <= q;i++) {
		int c, x;
		cin>>c>>x;
		if(c==1) {
			st.insert(x);
		}
		else {
			auto pos = st.lower_bound(x);//ac			
			//使用自带的二分查找函数，无需离散化即可！！！
			
			//可ac，但是会慢一点！！！
			// auto now = pos;
			// --pos;
			// cout<<*now-*pos<<"\n";
			
			// cout<<*pos-*prev(pos)<<"\n";
		}
	}
    return 0;
}