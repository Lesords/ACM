#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题意：由于是往下挖，所以是单向边
//题解：dfs暴力搜索，到达底的时候计算地雷数，更新地雷数和顺序

int val[25],n,ans;//val保存地窖的地雷数，ans为挖的地雷数
vector<int> g[25],ord,num;//g保存路径图，ord为中间顺序，num为最后顺序
void dfs(int dot) {//dot为当前点
    if(g[dot].empty()) {//到底了
        int tmp = 0;//tmp保存当前挖出的地雷数
        for(int i = 0;i < ord.size();i++) tmp += val[ord[i]];//ord保存的是点
        if(tmp>ans) {//更新较大值
            num = ord,ans = tmp;
        }
        return;
    }
    for(int i = 0;i < g[dot].size();i++) {//遍历所有指向的点
        ord.push_back(g[dot][i]);//添加指向点
        dfs(g[dot][i]);//继续dfs此点
        ord.pop_back();//去掉此点
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>val[i];//输入对应地窖的地雷数
    for(int i = 1;i < n;i++) {
        int op;
        for(int j = i+1;j <= n;j++) {
            cin>>op;
            if(op) g[i].push_back(j);//1为有连接
        }
    }
    for(int i = 1;i < n;i++) {//所有的点为起点进行dfs！！！
        ord.push_back(i);//添加当前点
        dfs(i);
        ord.pop_back();//删除当前点
    }
    for(int i = 0;i < num.size();i++) cout<<num[i]<<' ';//输出顺序
    cout<<endl<<ans<<endl;
    return 0;
}
