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

//题解：由于 r+c 为偶数只能向左走，为奇数只能向右走
//而题目中保证肯定有解，所以肯定时从上往下走
//所以可以先根据r来从小到大排序（记得添加起点(1,1)
//然后分类讨论：
//由于偶数只能向左走，而向左走之后，目的坐标值必为奇数！！！
//但是奇数可以向右走，所以奇数的目的坐标值也为奇数！！！
//所以对于同一侧的偶数来说，需要消耗对应的差值才能到达目的点
//
//画图可以得到：可以根据 r-c 的值来分类（r肯定>=c）
//
//1. 如果当前点和上一个点的差值相同：
//      如果起点的差值为偶数，只能消耗对应的长度来修改路径
//      如果起点的差值为奇数，那么可以直接不断向右走，不消耗
//2. 如果当前点和上一个点的差值不相同：
//      根据差值来分类，两两组合，计算起点和终点的分类差值即可
//      如果起点的差值为奇数，向上取整
//      如果起点的差值为偶数，向下取整

//注意：画图可以帮助理解，多画图，找规律！！！

const int MAXN = 2e5+5;
struct node{
    int r,c;
    friend bool operator < (node a,node b) {
        if(a.r!=b.r) return a.r < b.r;//先根据r从小到大排序
        return a.c < b.c;//然后在根据c排序
    }
}a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i].r;
        for(int i = 1;i <= n;i++) cin>>a[i].c;
        sort(a+1,a+1+n);//排序
        ll ans = 0;
        a[0] = {1,1};//起点为 (1,1) ！！！
        for(int i = 1;i <= n;i++) {//所有点都需要考虑，因为1位置不一定都为起点！！！
            int lastd = abs(a[i-1].r-a[i-1].c);//上一点的差值
            int nowd = abs(a[i].r-a[i].c);//当前点的差值
            if(lastd==nowd) {
                //起点为偶数，只能修改路径向右走
                if(lastd%2==0) ans += (a[i].r-a[i-1].r);
            }
            else {
                if(lastd%2) {//根据差分类！！！
                    ans += (nowd-lastd+1)/2;//向上取整（起点向左多了一次！！！）
                }
                else {
                    ans += (nowd-lastd)/2;//向下取整
                }
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
