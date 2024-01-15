#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解；所有相邻数的差的和 - 修改一个中间数避免的最大值（峰值差）

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int t;cin>>t;
    while(t--) {
        int n;cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        ll sum = 0,maxx = 0;
        int last = a[n];
        maxx = max(abs(a[1]-a[2]),abs(a[n-1]-a[n]));//maxx为修改一个数减少的最多操作！！！
        for(int i = 2;i < n;i++) {
            //中间大两边小 或者 中间小两边大
            if(a[i]>a[i-1]&&a[i]>a[i+1]||a[i]<a[i-1]&&a[i]<a[i+1]) {
                //tmp为修改i的值，减少的操作次数！！！
                ll tmp = abs(a[i-1]-a[i])+abs(a[i]-a[i+1])-abs(a[i-1]-a[i+1]);
                //原先的操作次数 - 修改后的操作次数
                maxx = max(tmp,maxx);
            }
        }
        for(int i = n-1;i >= 1;i--) {//所有相邻数的差的和
            ll tmp = abs(a[i]-last);
            sum += tmp;
            last = a[i];
        }
        cout<<sum-maxx<<"\n";
    }
	return 0;
}
