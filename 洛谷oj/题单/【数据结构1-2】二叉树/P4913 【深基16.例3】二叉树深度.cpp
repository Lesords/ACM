#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：vector建图，然后跑bfs计算深度即可

const int MAXN = 1e6+5;
struct node{
    int dot,dep;
    friend bool operator < (node a,node b) {
        if(a.dep!=b.dep) return a.dep > b.dep;//优先深度小的
        return a.dot > b.dot;
    }
};
vector<int> g[MAXN];                    //存图
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int a,b;
        cin>>a>>b;
        g[i].push_back(a);              //建边
        g[i].push_back(b);
    }
    int rt = 1,dep = 0;                 //起点状态
    priority_queue<node> q;
    q.push({rt,0});                     //将起点入队
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        for(int i = 0;i < g[tmp.dot].size();i++) {//遍历两个指向点
            int now = g[tmp.dot][i];
            dep = max(dep,tmp.dep+1);   //更新深度
            q.push({now,tmp.dep+1});    //子节点入队
        }
    }
    cout<<dep;
    return 0;
}
