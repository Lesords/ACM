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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：由于对于1-n里面的数在筛 sqrt(n) 的时候，会把之后所有的倍数都筛掉
//所以第一层只需要筛 1-sqrt(n) 即可
//对于第二层来说需要从 i*i 开始，因为需要获取每个数的最小质因子！！！
//对于算术基本定理来说：
// 由于结果是相乘的，所以可以先计算当前数的最小质因子，然后再乘上剩余的值的因子和
//最后从大到小记录 每个因子和 对应的值

const int MAXN = 1e7+5;
int v[MAXN],ans[MAXN];//v[i]为i的最小质因子，ans为答案
ll sum[MAXN];//sum[i]为i的因子和
void init() {
    //获取每个数的最小质因子
    for(int i = 2;i*i < MAXN;i++) {//埃式筛，需要取 sqrt(MAXN)
        if(v[i]==0) {
            v[i] = i;//v数组保存当前数的最小质因子
            for(int j = i*i;j < MAXN;j+=i) {//起点需要从i*i开始！！！
                if(v[j]==0) v[j] = i;
            }
        }
    }
    sum[1] = 1;//计算每个数的因子和
    for(int i = 2;i < MAXN;i++) {
        if(v[i]==0) {//sqrt(MAXN)之后的质数
            v[i] = i;//记录最小质因子
            sum[i] = i+1;//质数的因子只有本身+1
        }
        else {
            sum[i] = 1;//初始化
            int tmp = i;
            while(tmp%v[i]==0) {//把最小质因子全部去掉
                sum[i] = sum[i]*v[i]+1;//理解成v[i]进制来计算！！！
                tmp /= v[i];
            }
            sum[i] = sum[i]*sum[tmp];//再乘上剩余的tmp
        }
    }
    memset(ans,-1,sizeof(ans));//初始化为-1（无解输出-1
    for(int i = MAXN-1;i >= 1;i--) {//倒序计算答案
        if(sum[i]>=MAXN) continue;//越界
        ans[sum[i]] = i;//记录sum[i]值对应的数为i
    }
}
int main() {
    fast;//加速
    init();//预处理结果
    int t;
    cin>>t;
    while(t--) {
        int c;
        cin>>c;
        cout<<ans[c]<<"\n";//直接对应答案输出即可
    }
	return 0;
}
