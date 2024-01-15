#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：dfs计算每个边所需计算的次数，然后贪心修改边值即可

const int MAXN = 1e5+5;
struct node{
    int v,num;//点和边号
};
struct node2{
    ll num,val;
    friend bool operator < (node2 a,node2 b) {
        //根据可以删除的大小排序
        return a.num*(a.val-a.val/2) < b.num*(b.val-b.val/2);
    }
};
ll num[MAXN],w[MAXN],book[MAXN];//num[i]表示i号边计算的次数，w[i]为i号边的值
vector<node> G[MAXN];//book用来标记dfs时是否访问过该店，G为存储 目的点 和 对应边
ll dfs(int u) {
    node tmp;
    ll ans = 0;//当前边为所有子节点（叶子）的总数
    if(G[u].size()==1) return 1;//叶子节点只需要计算一次边
    for(int i = 0;i < G[u].size();i++) {//遍历所有子节点
        tmp = G[u][i];
        if(book[tmp.v]) continue;//已访问跳过
        book[tmp.v] = 1;//标记
        ans += num[tmp.num] = dfs(tmp.v);
        //当前点的次数需累加，目的点需再次dfs
    }
    return ans;//返回结果
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,s,v,u,sum = 0,cnt = 0;
        cin>>n>>s;
        for(int i = 1;i < n;i++) {
            book[i+1] = 0;
            cin>>v>>u>>w[i];
            G[v].push_back(node{u,i});//指向的点，边的号码
            G[u].push_back(node{v,i});
        }
        book[1] = 1;//标记根
        for(int i = 0;i < G[1].size();i++) {//从根开始dfs计算num
            node tmp = G[1][i];
            book[tmp.v] = 1;//先标记指向点！！！
            num[tmp.num] = dfs(tmp.v);//计算当前边所需计算的次数
        }//num[tmp.num] 为tmp.num（末点）上方的边计算次数
        priority_queue<node2> q;
        for(int i = 1;i < n;i++) {
            sum += num[i]*w[i];//总和
            q.push(node2{num[i],w[i]});
        }
        node2 tmp;
        while(sum>s) {//总和大于s时
            tmp = q.top();
            q.pop();
            ll res = tmp.val/2;//剩余一半
            q.push(node2{tmp.num,res});
            sum -= (tmp.val-res)*tmp.num;//扣除对应值
            cnt++;
        }
        cout<<cnt<<endl;
        for(int i = 1;i <= n;i++) G[i].clear();//清空G
    }
	return 0;
}
