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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：二分答案+贪心
//如果结果不好计算，但是解的范围在一定的范围内
//并且对应结果支持判定的话，那么可以考虑二分答案

//由于计算的是变换代价的最大值，并且给定数据的范围最大为 1e6
//并且给定数据数量只有 1e5，小于数据范围大小
//也就是每个值 一一对应 一个位置即可满足条件
//那么最大的情况是，最大值(1e6)处于当前位置，最小值(1)处于后一个位置
//那么需要将最大值修改为 最小值-1，即 1e6-1e6 = 1-1 = 0
//则最大结果为1e6

//由于交换代价不为负数，所以最小值为0
//即可以二分区间 [0, 1e6]
//那么每次判定val，可以从前往后逐位计算（优先当前位置尽量小）
//1. 第一个位置的值可以尽量小
//2. 如果当前位置大于前一个位置，则将当前位置的值尽量缩小
//（满足对应操作次数，并且需要大于前一个位置的值）
//3. 如果当前位置小于前一个位置，那么需要修改（加操作）
//如果当前位置和前一个位置的差值大于val，则无解！！！
//否则修改为 前一个位置的值 - 1（此时满足条件，且尽量较小）

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[MAXN],b[MAXN];//a为原数组，b为判定时的操作数组
int n;
bool judge(int val) {//判定val代价是否可以满足条件
    for(int i = 1;i <= n;i++) {
        if(i==1) b[i] = a[i] - val;//初始位置值尽量小
        else {
            //当前位置大于前一个位置值
            //b[i-1]+1：满足条件（大于前一个位置的值）
            //a[i]-val：在给定代价内的最小值
            if(a[i]>b[i-1]) b[i] = max(b[i-1]+1, a[i]-val);//两者都满足，则取max
            else {//否则需要+操作
                //在给定代价内可以满足条件，则取 上一个数+1
                if(a[i]+val>b[i-1]) b[i] = b[i-1]+1;
                else return false;//否则无解
            }
        }
    }
    return true;
}
int main() {
    fast;
    int t;
    cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        //[0, 1e6]范围内二分答案
        int l = 0, r = int(1e6+5), ans = 0;//ans为结果
        while(l<=r) {
            int mid = (l+r)>>1;
            //如果当前满足条件，则缩小右边界（结果尽量小）
            if(judge(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }
        cout<<"Case #"<<cas<<":\n";
        cout<<ans<<"\n";
    }
	return 0;
}
