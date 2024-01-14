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

//题解：直接暴力预处理所有长度的区间结果
//每次枚举区间的左起点和区间的右起点
//利用set来记录区间内是否有重复的数组（.size==len）
//然后记录最大值和最小值的情况
//如果区间有数字重复，直接break（因为后面都不会有满足的情况了，此时起点固定）
//如果 最大值-最小值 等于 区间下标差，即满足条件，对应区间长度结果++
//例：a[2] = 1, a[3] = 2, a[4] = 3
//其中有 3-1 = 4-2

const int MAXN = 1e4+5;
const int MOD = 1e9+7;
int n,m;
int a[MAXN], num[int(1e3+5)];//a为原数组，num记录对应长度的区间结果
void init() {
    for(int i = 1;i <= n;i++) {//枚举所有起点
        set<int> st;
        int minn = INF;
        int maxx = -INF;
        for(int j = i;j <= n;j++) {//枚举所有终点
            st.insert(a[j]);//放入集合中，去重
            minn = min(minn, a[j]);//取最小值
            maxx = max(maxx, a[j]);//取最大值
            int len = j-i+1;//当前区间长度
            // !=len 则说明有数字重复，直接结束
            // 范围>=1000也直接结束，因为查询区间只有1000
            if(st.size()!=len||maxx-minn>=1000) break;//剪掉了很多情况
            //不能直接break，可能出现当前不满足，但是添加后面的值会满足条件
            if(maxx-minn==len-1) num[len]++;//满足条件，则对应区间长度结果++
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    init();//预处理
    printf("Case #1:\n");
    while(m--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", num[k]);
    }
	return 0;
}
