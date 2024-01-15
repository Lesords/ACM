#include<iostream>//ac
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN];
int main() {
	int n,m,ans = 1,tmp = 0;//初始化为1（至少有一段）
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++) {
		if(tmp+a[i]>m) ans++,tmp = a[i];//当前段已满，更新新段和
		else tmp += a[i];//当前段的和增加
	}
	cout<<ans<<endl;
	return 0;
}
