#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：并查集+拓扑排序
//利用并查集将所有相等的点缩成一个点，然后计算剩余多少点（res）
//接着在剩余的点进行拓扑排序，判断的时候不是判断原数量而是剩余的点数（res）

const int MAXN = 1e4+5;
int n,m,fa[MAXN],in[MAXN];//fa记录并查集过程中的祖先，in为入度
vector<int> g[MAXN];//存边（高的指向低的）
vector<pii> a;//记录边的数据
set<int> st;//拓扑过程记录已经历的点
int getf(int x) {//路径压缩
    return x==fa[x]?x:fa[x] = getf(fa[x]);
}
int main() {
    while(scanf("%d%d",&n,&m)==2) {
        memset(in,0,sizeof(in));
        st.clear(), a.clear();
        for(int i = 0;i < n;i++) g[i].clear(),fa[i] = i;//初始化
        for(int i = 1;i <= m;i++) {
            int x,y;
            char op;
            scanf("%d%*c%c%*c%d",&x,&op,&y);
            x = getf(x),y = getf(y);
            if(op=='=') {
                if(x!=y) fa[y] = x;//向左合并
            }
            else if(op=='<') a.push_back(make_pair(y,x));
            else a.push_back(make_pair(x,y));//记录边（高->低）
        }
        for(int i = 0;i < a.size();i++) {
            int x = getf(a[i].fi);
            int y = getf(a[i].se);//存图用祖先点
            g[x].push_back(y);//不需要处理重复边（遍历边的时候会一个个删掉）
            in[y]++;//入度++
        }
        priority_queue<int> q;
        int flag = 0,num = 0,res = 0;
        for(int i = 0;i < n;i++) res += fa[i]==i;//res为剩余的点数
        for(int i = 0;i < n;i++) {
            if(getf(i)!=i) continue;//跳过不是代表的点
            if(in[getf(i)]==0) q.push(getf(i));//指向点一致
        }//push可以不用找祖先值，后面拓扑的时候会修改对应的指向点入度
        while(!q.empty()) {
            int tmp = q.top();q.pop();
            if(st.count(tmp)) continue;//跳过已标记的
            else st.insert(tmp);//否则继续标记
            if(!q.empty()) {//可选择点不为1个，则为信息不完全
                flag = 1;
            }
            num++;//拓扑序列的数量++
            for(int i = 0;i < g[tmp].size();i++) {//遍历所有边（可处理重复边）
                int dot = g[tmp][i];
                --in[dot];//对应点的入度--
                if(in[dot]==0) q.push(dot);//若入度为0，则入队列
            }
        }//冲突实际上就是有环
        if(num<res) cout<<"CONFLICT\n";//包含冲突就需要输出了！！！
        else {//只不过冲突的优先级高！！！
            if(flag) cout<<"UNCERTAIN\n";
            else cout<<"OK\n";
        }
    }
    return 0;
}
