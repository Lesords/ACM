#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：拓扑排序计算拓扑序列即可，注意多组输入

const int MAXN = 505;
int n,m,in[MAXN],vis[MAXN];//in记录入度，vis表示是否经历过
vector<int> g[MAXN],ans;//g存边，ans存答案
int main() {
    while(cin>>n>>m) {
        for(int i = 1;i <= m;i++) {
            int x,y;
            cin>>x>>y;
            in[y]++;//处理入度和边
            g[x].push_back(y);
        }
        priority_queue<int,vector<int>,greater<int> > q;//升序
        for(int i = 1;i <= n;i++) {
            if(in[i]) continue;
            q.push(i);//把所有入度为0的放入队列
        }
        while(!q.empty()) {
            int tmp = q.top();q.pop();
            if(vis[tmp]) continue;//跳过已标记的
            else vis[tmp] = 1;//否则继续标记
            ans.push_back(tmp);//保存答案
            for(int i = 0;i < g[tmp].size();i++) {
                int dot = g[tmp][i];//所有指向点入度--
                in[dot]--;
                if(in[dot]==0) q.push(dot);//若为0则入队
            }
        }
        for(int i = 0;i < ans.size();i++) {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
        for(int i = 1;i <= n;i++) vis[i] = in[i] = 0,g[i].clear();
        ans.clear();//清空
    }
    return 0;
}
