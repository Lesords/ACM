#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//题解：利用拓扑排序来更新到达某点所需的最大时间
//最后取所有点的最大值即为答案

const int MAXN = 1e4+5;
int in[MAXN],out[MAXN],tim[MAXN],to[MAXN],n;
//in存储入度，out存储出度，tim记录该点本身所需时间，to记录到达该点所需的时间
vector<int> g[MAXN];//存图
int main() {
    cin>>n;
    int ans = 0;//初始化为0
    for(int i = 1;i <= n;i++) {
        int tmp,len,val;
        cin>>tmp>>len;
        ans = max(ans,len);//更新到每个的时间
        tim[tmp] = len;
        while(cin>>val&&val) {//val是前置条件，val->tmp
            g[val].push_back(tmp);//记录关系
            in[tmp]++;out[val]++;//记录入度和出度
        }
    }
    queue<int> q;//拓扑排序
    for(int i = 1;i <= n;i++) if(in[i]==0) q.push(i);//入度为0的入队列
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        for(int i = 0;i < g[tmp].size();i++) {//遍历所有指向点
            int now = g[tmp][i];//记录指向点的编号
            out[tmp]--;//出度和入度对应修改
            to[now] = max(to[now],tim[tmp]);//更新到达now点的时间（起始点花费的时间）
            in[now]--;
            if(in[now]==0) {//入度为0，继续入队列
                tim[now] += to[now];//更新到达now的总时间（此时now点无前置条件）！！！
                q.push(g[tmp][i]);
            }
        }
    }
    for(int i = 1;i <= n;i++) ans = max(ans,tim[i]);//取最大值
    cout<<ans<<endl;
    return 0;
}
