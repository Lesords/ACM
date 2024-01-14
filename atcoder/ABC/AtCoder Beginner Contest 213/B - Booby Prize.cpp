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

//题解：由于值越小，排名越大
//则排名小的，对应值就越大
//倒二排名即为 值第二大的
//直接结构体排序即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
struct node{
    int val,pos;//val为值，pos为对应位置
    friend bool operator < (node a, node b) {
        //从小到大排序
        if(a.val==b.val) return a.pos < b.pos;
        return a.val < b.val;
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].val;
        a[i].pos = i;//记录对应值
    }
    sort(a+1,a+1+n);
    cout<<a[n-1].pos<<"\n";//输出第二大值的位置即可
	return 0;
}
