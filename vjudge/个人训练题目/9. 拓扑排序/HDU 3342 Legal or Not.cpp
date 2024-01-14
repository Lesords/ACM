#include<iostream>//ac
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

//题解：建图跑拓扑排序即可，判断是否有环
//有环则违法，否则合法

const int MAXN = 105;
int n,m,in[MAXN];//in为入度
set<int> st;//st判断是否访问过
vector<int> g[MAXN];//存图
void init() {//初始化
    memset(in,0,sizeof(in));
    st.clear();
    for(int i = 0;i < n;i++) g[i].clear();
}
bool topo() {//判断是否有环
    int num = 0;
    priority_queue<int> q;//初始化时所有入度为0的入队列
    for(int i = 0;i < n;i++) if(in[i]==0) q.push(i);
    while(!q.empty()) {
        int tmp = q.top();q.pop();
        if(st.count(tmp)) continue;//跳过已标记的
        else st.insert(tmp);//否则继续标记
        num++;//记录数量
        for(int i = 0;i < g[tmp].size();i++) {//遍历所有边
            int dot = g[tmp][i];
            in[dot]--;
            if(in[dot]==0) q.push(dot);//入度为0，则继续入队列
        }
    }
    return num == n;//判断数量是否为n
}
int main() {
    while(cin>>n>>m&&n+m) {
        init();
        for(int i = 1;i <= m;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);//建图
            in[y]++;
        }
        if(topo()) cout<<"YES\n";//判断是否有环即可
        else cout<<"NO\n";
    }
    return 0;
}
