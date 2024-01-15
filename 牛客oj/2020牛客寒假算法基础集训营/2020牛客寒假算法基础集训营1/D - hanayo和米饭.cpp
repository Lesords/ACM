#include<iostream>//ac
using namespace std;
const int MAXN = 1e5+5;
int book[MAXN];
int main() {
	int n,tmp,ans = 0;
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i <= n-1;i++) cin>>tmp,book[tmp] = 1;
	//标记所有出现过的数字
	//然后再遍历一次寻找一个未标记的数字即为答案
	for(int i = 1;i <= n;i++) if(!book[i]) {//未标记
		ans = i;break;
	}
	cout<<ans<<endl;
	return 0;
}
