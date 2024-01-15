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

//题解：由于每种数字最多只能涂k种颜色
//那么将所有数字排序，按顺序涂色，记录对应数字涂的次数
//涂了k次的，则跳过
//否则继续按照顺序涂
//注意：最后涂的可能不满足k个，所以需要倒序删除一遍，删到出现k

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int val,pos;//val为值，pos为位置
    friend bool operator < (node a,node b) {
        if(a.val==b.val) return a.pos < b.pos;//数字相同，根据位置排序
        return a.val < b.val;//否则根据数值排序
    }
}a[MAXN];
int b[MAXN],num[MAXN];//b记录每个位置涂的颜色，num记录当前颜色涂的次数
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) num[i]=0;//初始化为0，用于记录每次数字绘画的次数
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            a[i] = {tmp,i};
        }
        sort(a+1,a+1+n);//排序
        int id = 1;//初始值为1
        for(int i = 1;i <= n;i++) {
            int now = a[i].val;//当前值
            int pos = a[i].pos;//当前位置
            if(num[now]>=k) {//已经涂过k次了，不能继续涂了
                b[pos] = 0;
            }
            else {
                b[pos] = id++;//涂id，并更新id的值
                num[now]++;//对应数字涂的次数++
                if(id==k+1) id = 1;//若id超了，更新为1
            }
        }
        int p = n;//从后面一个开始找
        while(1) {
            int now = a[p].pos;//当前数的位置
            //若当前涂的为k色，则结束
            if(b[now]==k) break;//wa了，不用判断0！！！
            b[now] = 0;//否则不涂！！！
            p--;
        }
        for(int i = 1;i <= n;i++) cout<<b[i]<<" ";
        cout<<'\n';
    }
    return 0;
}
/*
3
6 3
1 2 5 5 5 6
7 3
1 2 5 5 5 5 6

1
7 3
1 2 5 5 5 6 6

1
10 3
1 2 5 5 5 5 6 6 6 6
*/
