#include<iostream>//ac
#include<queue>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int a[MAXN];
vector<int> g[MAXN];
bool judge(int pos) {//判断与pos相邻的点，是否有颜色相同的
    for(int i = 0;i < g[pos].size();i++) {
        int now = g[pos][i];
        if(a[pos]==a[now]) {
            return true;//有相同的返回true
        }
    }
    return false;
}
int main() {
    int v,e,k,n;
    cin>>v>>e>>k;
    for(int i = 1;i <= e;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);//存边
        g[y].push_back(x);//无向边
    }
    cin>>n;
    for(int i = 1;i <= n;i++) {
        set<int> st;
        for(int j = 1;j <= v;j++) {
            cin>>a[j];
            st.insert(a[j]);//统计颜色的种数
        }
        if(st.size()!=k) {//必须为k个！！！
            cout<<"No\n";
            continue;
        }
        int flag = 0;
        for(int j = 1;j <= v;j++) {//直接暴力判断，不需要bfs
            if(judge(j)) {
                flag = 1;break;
            }
        }
        if(!flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
