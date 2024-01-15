#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e4 + 5;
int vis[MAXN],a[105];
int main() {
	int n,ans = 0,maxx = 0,minn = INF;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		vis[a[i]] = 1;
		maxx = max(maxx,a[i]);//最小数
		minn = min(minn,a[i]);//最大数
	}
	for(int i = 1;i <= n;i++) {
		for(int j = minn;j <= maxx;j++) {//从小到大遍历
			if(j>a[i]) break;// j 必须比 a[i] 小
			if(vis[j]&&vis[a[i]-j]&&j<a[i]-j) {//j和a[i]-j 存在
				ans++;
				break;//注：不能重复计算！！！
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
