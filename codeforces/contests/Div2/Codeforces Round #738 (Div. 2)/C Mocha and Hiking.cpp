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

//题解：由于前面 n-1 个点都可以直达后面一个点
//那么要想遍历所有点，且只遍历一次
//肯定得遍历这前面的 n-1 条边 （1->2->3->···->n）
//剩余的话，只差一个 n+1 位置的点
//也就是说要么n+1在开头，要么在末尾
//要么中间有个点可以到达 n+1 点，并且能从 n+1 点返回到下一个点

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        if(a[n]==0) {//n能到达 n+1，也就是说 n+1 为末尾
            for(int i = 1;i <= n+1;i++) cout<<i<<" ";
            cout<<"\n";
            continue;
        }
        int ok = 0;
        if(a[1]==1) {//n+1能到达 1，也就是说 n+1 为开头
            cout<<n+1;
            for(int i = 1;i <= n;i++) cout<<" "<<i;
            cout<<"\n";
            continue;
        }
        for(int i = 1;i < n;i++) {//不包括n
            //当前点能到达 n+1，并且还能从 n+1 返回到下一个点 i+1
            if(a[i]==0&&a[i+1]) {
                for(int j = 1;j <= i;j++) cout<<j<<" ";
                cout<<n+1;//n+1在中间位置！！！
                for(int j = i+1;j <= n;j++) cout<<" "<<j;
                cout<<"\n";
                ok = 1;//存在结果，结束
                break;
            }
        }
        //没找到结果则输出-1
        if(ok==0) cout<<"-1\n";
    }
	return 0;
}
