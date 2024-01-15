#include<iostream>//ac
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int main() {
	int n,ans = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	int tmp = 1;
	for(int i = 2;i <= n;i++) {
		if(a[i]>a[i-1]) tmp++;
		else {
			if(tmp>ans) ans = tmp;//取较大值
			tmp = 1;//置1
		}
        if(tmp>ans) ans = tmp;//实时更新答案！！！
	}
	cout<<ans<<endl;
	return 0;
}
