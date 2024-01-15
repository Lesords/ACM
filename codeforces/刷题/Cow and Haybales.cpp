#include<iostream>//ac
using namespace std;
int a[105];
int main() {
	int t,n,d,ans,tmp;
	cin>>t;
	while(t--) {
		ans = 0;
		cin>>n>>d;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 2;i <= n;i++) {
			if(!a[i]) continue;//为0时跳过
			tmp = min(d/(i-1),a[i]);//取小值
			a[1] += tmp;//添加可以转移的值
			d -= tmp*(i-1);//扣除相应步数
			if(!d) break;//步数为0时结束
		}
		cout<<a[1]<<endl;
	}
	return 0;
}
