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

//题解：从最小位开始加到最高位，每次都判断数位和是否满足条件

int judge(ll a) {//计算数位和
    int ans = 0;
    while(a) {
        ans += a%10;
        a /= 10;
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,s,ans = 0,pos = 1;//pos记录对应位置的值
        cin>>n>>s;
        while(judge(n)>s) {//判断数位和是否超过要求
            if(n/pos%10==0) {//当前位值为0
                //位置的值需要更新！！！
                pos *= 10;continue;
            }
            // n/pos%10 为pos位的数值
            ll tmp = pos*(10-n/pos%10);//计算当前位缺多少可进位
            ans += tmp;//增加的操作
            n += tmp;//原数增加
            pos *= 10;//更新位置的值
        }
        cout<<ans<<endl;
    }
	return 0;
}
