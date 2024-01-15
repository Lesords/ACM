#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],b[MAXN];

//题解：对于每个学生寻找差值最小的学校即可

int main() {
	int n,m;
	ll ans = 0;//初始化为0
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i <= m;i++) cin>>b[i];
	sort(b+1,b+m+1);
	for(int i = 1;i <= m;i++) {
		int pos = lower_bound(a+1,a+n+1,b[i])-a;//找位置
		if(pos==1) ans += llabs(a[pos]-b[i]);//没有左侧
		else ans += min(llabs(a[pos]-b[i]),llabs(a[pos-1]-b[i]));
		//有左侧的时候，左侧差值也需要判断！！！
	}
	cout<<ans;
	return 0;
}
