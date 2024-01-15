#include<iostream>//ac
#include<cstring>
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
const int MAXN = 2e5+5;
int pre[MAXN],suf[MAXN],a[MAXN];
//pre[i]：以1-i为结尾的 k长 平台可以放的点，取最大值
//suf[i]：以i-n为起点的 k长 平台可以放的点，取最大值
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,tmp;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+1+n);//升序排列
        for(int i = 1;i <= n;i++) cin>>tmp;//y坐标无用，忽略
        int pos = 1;//初始化为1
        for(int i = 1;i <= n;i++) {//从前到后判断前缀最值
            while(a[i]-a[pos]>k) pos++;//不能超过k长
            pre[i] = i-pos+1;//pos为左点，i为右点
            if(i>1) pre[i] = max(pre[i],pre[i-1]);//不为初始点
        }
        pos = n;
        for(int i = n;i >= 1;i--) {//从后到前判断后缀最值
            while(a[pos]-a[i]>k) pos--;//不能超过k长
            suf[i] = pos-i+1;//pos为右点，i为左点
            if(i<n) suf[i] = max(suf[i],suf[i+1]);//不为终点
        }
        int ans = 0;//初始化结果为0
        //遍历所有点，计算 前k+后k 的最值，可一起初始化pre和suf数组
        for(int i = 1;i <= n;i++) ans = max(ans,pre[i]+suf[i+1]),pre[i]=suf[i]=0;
        cout<<ans<<endl;
    }
	return 0;
}
