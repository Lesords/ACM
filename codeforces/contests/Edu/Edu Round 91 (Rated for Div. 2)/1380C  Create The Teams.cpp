#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+10;
struct node{
	int val,num;
	friend bool operator < (node a,node b) {
		return a.val < b.val;
	}
}a[MAXN];
int main() {
	int t,n,x;
	cin>>t;
	while(t--) {
		cin>>n>>x;
		for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].num = ceil(x*1.0/a[i].val);
		//num是以val为最低值所需要的人数
		sort(a+1,a+n+1);
		int pos = n;//从最大的开始贪心
		int ans = 0;
		while(pos>=1) {
			if(a[pos].num==1) pos--,ans++;//只需要一个人
			else {
				int tmp = pos;//tmp为临时的位置
				while(tmp>=1) {
					//判断tmp-pos的人数是否满足条件
					if(pos-tmp+1>=a[tmp].num) {
						ans++;
						break;
					}
					else tmp--;
				}
				pos = tmp-1;//更新pos位置(tmp用过了)
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
