#include<iostream>//ac
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

//题解：每添加一个边就进行一次拓扑排序
//拓扑序列达到n层，说明有正解（为第一种情况
//拓扑序列没有达到出现的字符数量，说明有环（第二种情况）
//其他，为第三种情况
//注意：不要用入度来判断是否为第一种情况，因为可能出现两个不相交的边
//这样的话，起点入队都为0，但是并不是有环
//所以可以用拓扑序列的深度来判断是否有拓扑序列

const int MAXN = 30;
vector<int> g[MAXN];//建图
set<int> st;//记录已经出现了几个字符
int in[MAXN],in2[MAXN],dep[MAXN];//in为拓扑计算中的入度数组
//in2为记录的原入度数组，dep为对应点的深度
int idx(char cc) {//将字符转为数字
    return cc-'A';
}
char chx(int id) {//将数字转为字符
    return id+'A';
}
int main() {
    int n,m,flag=-1;//flag为结果
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        char aa,bb,cc;
        cin>>aa>>bb>>cc;
        if(aa==cc) {
            flag = 0;
            cout<<"Inconsistency found after "<<i<<" relations.\n";
        }
        if(flag!=-1) continue;//结果已经除了，跳过后面的计算过程
        st.insert(idx(aa));//记录出现的两个字符
        st.insert(idx(cc));
        g[idx(aa)].push_back(idx(cc));//建边
        in2[idx(cc)]++;//记录入度
        memcpy(in,in2,sizeof(in2));//复制入度数据到数组in
        queue<int> q;
        vector<int> ans;//保存拓扑序列
        for(int i = 0;i < n;i++) {
            //初始深度为1
            if(in[i]==0&&st.count(i)) q.push(i),ans.push_back(i),dep[i] = 1;
        }
        int maxd = 0;//记录最大深度
        while(!q.empty()) {
            int tmp = q.front();q.pop();
            for(int i = 0;i < g[tmp].size();i++) {//遍历所有指向点
                int now = g[tmp][i];
                in[now]--;//入度--
                if(in[now]==0) {//入度为0，则重新入队
                    q.push(now);
                    dep[now] = dep[tmp]+1;//记录now位置的深度
                    maxd = max(maxd, dep[now]);//更新最大深度
                    ans.push_back(now);
                }
            }
        }
        if(ans.size()!=st.size()) {//拓扑序列数量不为出现字符的大小
            flag = 0;
            cout<<"Inconsistency found after "<<i<<" relations.\n";
        }
        else if(maxd==n) {//深度为n，说明每层有且只有一个
            flag = 1;
            cout<<"Sorted sequence determined after "<<i<<" relations: ";
            for(int i = 0;i < ans.size();i++) cout<<chx(ans[i]);
            cout<<".\n";
        }
    }
    if(flag==-1) cout<<"Sorted sequence cannot be determined.\n";
    return 0;
}
