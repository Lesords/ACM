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

//题解：记忆化搜索，计算每个状态可以产生的粒子数量
//每个位置要么继续前进，要么折射，产生周期-1的方向粒子
//两个状态的和即为当前位置产生粒子数量的总和（包括初始化的两个）

const int MAXN = 1e3+5;
const int MOD = 1e9+7;
int dp[MAXN][MAXN][2],n,k;
//递归会爆栈
int solve(int pos,int val,int dir) {
    //pos为位置，val为衰变周期，dir为方向（1为向右，0为向左）
    if(val==1) {//周期为1，无法继续衰变了
        return 1;//所以只有一个
    }
    if(dp[pos][val][dir]!=-1) {//该位置的状态已经计算过了，直接返回
        return dp[pos][val][dir];
    }
    int ans = 2;//初始化为两个（自己及复制
    if(dir==1) {//向右移动
        if(pos<n) {//前面还能继续走的
            ans += solve(pos+1,val,dir) - 1;//扣除一个本身的
        }
        ans %= MOD;//取模
        if(pos>1) {//左边可以走的（可以反射的
            ans += solve(pos-1,val-1,1-dir) - 1;//扣除一个复制的
        }
        ans %= MOD;//取模
        dp[pos][val][dir] = ans;//记录当前状态的答案
    }
    else {//向左移动
        if(pos>1) {//左边可以继续移动
            ans += solve(pos-1,val,dir) - 1;//需扣除一个本身的
        }
        ans %= MOD;//取模
        if(pos<n) {//右边可以移动（可反射
            ans += solve(pos+1,val-1,1-dir) - 1;//扣除一个复制的
        }
        ans %= MOD;//取模
        dp[pos][val][dir] = ans;//记录当前状态的答案
    }
    return ans;
}
int main() {
//  本地64位，cf32位

//	int size=126<<20;//256MB
//    char*p=(char*)malloc(size)+size;
//    __asm__ __volatile__("movq %0, %%rsp\n" :: "r"(p));//64bit

	int __size__ = 126<<20;
	char *__p__ = (char *)malloc(__size__)+__size__;
	__asm__("movl %0,%%esp\n"::"r"(__p__));//32bit

    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));//初始化为-1
        cout<<solve(1,k,1)<<"\n";
    }
    exit(0);
	return 0;
}
