// Problem: D. Secret Santa
// Contest: Codeforces - Codeforces Round #733 (Div. 1 + Div. 2, based on VK Cup 2021 - Elimination (Engine))
// URL: https://codeforces.ml/problemset/problem/1530/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-12 23:56:40

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题意：有n个人每个人都有想要的礼物，但是自己不能收到自己给出的礼物
//求有多少人可以获得自己想要的礼物
//题解：首先，将所有可以直接给的礼物，直接给了
//然后对于还未给的部分，倒序 未给过的礼物
//由于倒序给礼物最多只会有一个为 自己给自己礼物
//所以在判断一个即可，如果出现自己给自己礼物的情况
//那么满足自己的想要的礼物，然后将 自己想要的礼物原先给定的人 的礼物改为自己给出的礼物

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN], vis[MAXN], mp[MAXN], ans[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n, num = 0;					//num为满足要求的人数
    	cin >> n;
    	//初始化都为0
    	for(int i = 1;i <= n;i++) vis[i] = mp[i] = 0;
    	for(int i = 1;i <= n;i++) {
    		cin >> a[i];
    		if(mp[a[i]]==0) {			//如果该礼物还未给人
    			num++;					//结果++
    			mp[a[i]] = i;			//mp记录对应礼物给的人
    			ans[i] = a[i];			//ans记录i的礼物
    			vis[i] = 1;				//vis记录i已经有礼物
    		}
    	}
    	int val = n;					//从n开始，倒序安排礼物
    	for(int i = 1;i <= n;i++) {
    		if(vis[i]) continue;		//跳过有礼物的
    		while(mp[val]) val--;		//如果礼物val已经给人了，则判断礼物val-1
    		ans[i] = val;				//当前i的礼物为val
    		mp[val] = i;				//记录val礼物给的人
    	}
    	//寻找自己给自己礼物的人
    	for(int i = 1;i <= n;i++) {
    		if(ans[i]==i) {
    			ans[i] = a[i];			//满足自己的要求
    			ans[mp[a[i]]] = i;		//将自己想要的礼物a[i]原先的 人 mp[a[i]] 的礼物改为 自己给出的礼物
    			break;
    		}
    	}
    	cout << num << "\n";
    	for(int i = 1;i <= n;i++) cout << ans[i] << " ";
    	cout << "\n";
    }
    return 0;
}
