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

//题解：题意描述的其实就是dfs的过程
//但当前点所有可访问点都访问完之后，回到上一个点
//这个过程其实就是回溯
//记录结果的话，只需要再对应的dfs后面 push_back 即可
//不需要另外再调用

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
vector<int> g[MAXN];//vector排序可以过！！！
vector<int> ans;//记录结果序列
void dfs(int pos,int f) {//pos为当前节点，f为父节点
    ans.push_back(pos);
    for(int i = 0;i < g[pos].size();i++) {//遍历所有指向点
        int now = g[pos][i];
        if(f==now) continue;//跳过父节点的情况
        dfs(now, pos);
        ans.push_back(pos);
        //直接回溯的时候在输入一次结果即可！！！
        //不需要再遍历一次来判断是否为空
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i < n;i++) {
        int u,v;
        scanf("%d%d", &u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    //vector排序可以过！！！
    for(int i = 1;i <= n;i++) sort(g[i].begin(), g[i].end());
    dfs(1,-1);
    for(int i = 0;i < ans.size();i++) {
        if(i!=0) printf(" ");
        printf("%d", ans[i]);
    }
	return 0;
}
