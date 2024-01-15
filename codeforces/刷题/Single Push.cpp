#include<iostream>//ac
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
	int t,n,tmp;
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		int sub = 0,flag = 0,book = 0;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			if(tmp!=a[i]) {
				if(book == 2) flag = 1;//第二部分不相等
				if(flag) continue;
				if(book) {//第一部分不相等
					if((tmp-a[i])!=sub) flag = 1;
				}
				else {//还没修改过
					sub = tmp - a[i],book = 1;
					if(sub < 0) flag = 1;//a组数大于b组数
				}
			}
			else if(book==1) book++;//已经修改过
		}
		flag?cout<<"NO\n":cout<<"YES\n";
	}
	return 0;
}
