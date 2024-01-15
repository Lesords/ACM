#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int n,tmp,ans = 0;
	cin>>n;//由于到达后才消耗，所以从 0 开始
	for(int i = 0;i < n;i++) {//需要的能量为 下标 + 能量参数
		cin>>tmp, ans = max(ans, tmp + i);
	}
	cout<<ans<<endl;
	return 0;
}
