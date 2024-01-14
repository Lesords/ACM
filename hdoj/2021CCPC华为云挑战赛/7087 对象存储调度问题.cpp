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

//题解；将所有数据对象从大到小排序
//然后将所有分条（有空闲的）放入优先队列中（堆顶优先大的）
//每次将堆顶的数据弹出，判断是否够放当前的数据对象
//如果不够放，则无解；
//否则更新分条剩余空间，然后再次放入队列中；
//如果所有数据对象都匹配完，直接结束。

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int a[MAXN],b[MAXN];
bool cmp(int a,int b) {//从大到小排序
    return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        priority_queue<int> q;//默认从大到小
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        sort(a+1, a+1+n, cmp);//从大到小排序
        for(int i = 1;i <= m;i++) {
            cin>>b[i];
            q.push(b[i]);//将所有分条放入队列中
        }
        bool ok = 1;
        int pos = 1;
        while(!q.empty()) {//判断当前队列是否为空，即是否有剩余分条
            int now = q.top();
            q.pop();
            if(now>=a[pos]) {//当前分条够放，则更新剩余空间，再次放入队列中
                now -= a[pos];
                pos++;//移到后一个数据对象
                if(pos>n) break;//大于n，表示n个数据对象都匹配结束
                if(now) q.push(now);//还有剩余空间，则继续放入队列中
            }
            else {//不够放，则无解
                ok = 0;break;
            }
        }
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
