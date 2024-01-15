#include<iostream>//ac
#include<algorithm>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;


//题解：要想相邻绝对差尽量小
//那么需要求与丢失位置相邻的最大值和最小值
//然后填充位置为 最大值+最小值 的一半
//最后遍历整个数组，判断绝对差即可

const int MAXN = 2e5 + 5;
int a[MAXN];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		int minn = INF,maxx = -INF,ans = 0;
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++) {
			if(a[i]==-1) continue;//跳过丢失位置
			if(i>1&&a[i-1]==-1||i<n&&a[i+1]==-1) {
				//前或后为丢失位置
				minn = min(minn,a[i]);//取较小值
				maxx = max(maxx,a[i]);//取较大值
			}
		}
		for(int i = 1;i <= n;i++) {//填补丢失位置数
			if(a[i]==-1) a[i] = (maxx+minn)/2;
		}
		//取相邻绝对差较大的值
		for(int i = 1;i < n;i++) ans = max(ans,abs(a[i]-a[i+1]));
		cout<<ans<<' '<<(maxx+minn)/2<<endl;
	}
	return 0;
}
