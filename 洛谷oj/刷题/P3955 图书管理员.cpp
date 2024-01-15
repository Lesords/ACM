#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1005;
int a[MAXN];
int to_mod(int siz) {//10^siz
	int ans = 1;
	for(int i = 1;i <= siz;i++) ans *= 10;
	return ans;
}
int main() {
	int n,q;
	cin>>n>>q;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);//从小到大排序
	int siz,num,mod;
	for(int i = 1;i <= q;i++) {
		cin>>siz>>num;
		mod = to_mod(siz);
		int flag = 0;
		for(int i = 1;i <= n;i++) {
			if(a[i]%mod==num) {//后siz位就是 %mod
				cout<<a[i]<<endl;
				flag = 1;break;
			}
		}
		if(!flag) cout<<"-1\n";
	}
	return 0;
}
