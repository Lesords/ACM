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

//题解：移动k次，可以向左或向右，向左最多z次，获得当前位置值对应的分数，求最大得分
//题解：只向右移动k次后处的位置为1+k，若向左移动一次，则对应的末尾位置-2
//例：1->2->3->4可以为：1->2->3->2或 1->2->1->2
//由于不能连续向左移动，所以每次向左移动可以理解为取两个相邻数的总和（可重复）
//那么对于向右移动的值可以取前缀和，向左移动的位置可以为 相邻两数和最大处

const int MAXN = 1e5+5;
int a[MAXN],pre[MAXN],maxx[MAXN];//pre[i]为1-i的和，maxx为1-i为末尾位置相邻两数和最大值
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k,z;
        cin>>n>>k>>z;
        for(int i = 1;i <= n;i++) cin>>a[i],pre[i] = pre[i-1]+a[i];//读入+前缀和
        for(int i = 1;i < n;i++) {//i为末尾，相邻两数最大值
            maxx[i] = max(maxx[i-1],a[i]+a[i+1]);
        }
        int ans = 0;
        for(int i = 0;i <= z;i++) {
            if(k-2*i<1) break;//如果末尾位置小于1（向左的次数可能会多）
            ans = max(ans,pre[k+1-2*i]+maxx[k+1-2*i]*i);//maxx取值位置可以为末尾位置（先右在左）
            //i次向左，对应末尾位置为 k+1-2*i
        }
        cout<<ans<<endl;
    }
	return 0;
}
/*
样例：
1
18 11 4
11 19 18 19 19 5 14 15 17 4 10 9 8 17 9 2 15 10
219
*/
