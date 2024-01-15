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

//题意：计算1之间0的个数

const int MAXN = 1e2+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        int ans = 0;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int pos = 1,last = 0;
        for(int i = 1;i <= n;) {
            if(a[i]==1) {//当前为1时
                int tmp = i+1;
                while(tmp<=n) {//找到下一个为1的位置
                    if(a[tmp]==0) tmp++;//0则继续找
                    else break;
                }
                if(tmp>n) break;//越界
                ans += tmp-i-1;//不包括首尾（计算两个1之间的间隔）
                i = tmp;//更新当前位置
            }
            else i++;//跳过0
        }
        cout<<ans<<endl;
    }
	return 0;
}
