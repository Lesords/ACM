#include<iostream>//ac
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN= 505;
int n,m,in[MAXN],ans[MAXN];
vector<int> edge[MAXN];
int main () {
    while(cin>>n>>m) {//多组输入！！！
        int p1,p2;
        memset(in,0,sizeof(in));//初始化入度信息
        for(int i = 1;i <= m;i++) {
            cin>>p1>>p2;
            edge[p1].push_back(p2);//存边 （p1->p2）
            in[p2]++;
        }
        priority_queue<int,vector<int>,greater<int> > q;//编号小的在前
        for(int i = 1;i <= n;i++) {//将所有初始入度为0的放入队列中去
            if(in[i]==0) q.push(i);
        }
        int cnt = 0,tmp;
        while(!q.empty()) {
            tmp = q.top();q.pop();
            ans[++cnt] = tmp;//q队列中每个都需要保存
            for(int i = 0;i < edge[tmp].size();i++) {//判断当前点指向位置
                int dot = edge[tmp][i];
                in[dot]--;//指向位置的所有点入度--
                if(in[dot]==0) q.push(dot);//入度为0的放入q队列中去
            }
        }
        for(int i = 1;i <= cnt;i++) {//保证有解，所以此时cnt=n
            if(i!=1) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
        for(int i = 1;i <= n;i++) edge[i].clear();//清空边信息
    }
    return 0;
}
