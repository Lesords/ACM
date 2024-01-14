#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005],n,m,ans;
int main() {
	int T,cnt;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		ans=m,cnt=0;//第一次抓鱼的时间 
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			ans+=a[i];//每一次煮鱼的时间 
			cnt+=a[i]/m;//统计在煮鱼期间，可以捕鱼的次数 
			a[i]%=m;//处理煮鱼时间 
		}
		if(cnt>=n-1) {//煮鱼的时间够抓n-1的鱼(因为第一条抓鱼时间必须有)
			cout<<ans<<endl;
		}
		else {
			sort(a+1,a+1+n);//从小到大排序，所以接下来的i从n开始 
			for(int i=n;cnt<n-1;cnt++,i--) {//cnt为n-1时结束（捕鱼时间够了） 
				ans+=m-a[i];//浪费的时间为m-a[i]
			}
			cout<<ans<<endl;
		} 
	}
	return 0;
} 
