#include<iostream>//ac
using namespace std;

//题解：dfs遍历所有情况
//指定为从 1-n 开始选值
//当选择了 n 个时，输出对应结果并返回

int a[15],vis[15];
int n;
void dfs(int pos) {//当前选了pos个
    if(pos==n) {//已选了n个，则输出对应结果并返回
        for(int i = 1;i <= n;i++) cout<<a[i]<<" ";
        cout<<"\n";
        return ;
    }
    for(int i = 1;i <= n;i++) {//遍历所有数字
        if(vis[i]) continue;//跳过已选择的
        a[pos+1] = i;
        vis[i] = 1;//标记
        dfs(pos+1);
        vis[i] = 0;//取消标记
    }
}
int main() {
    cin>>n;
    dfs(0);
    return 0;
}
