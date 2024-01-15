#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;

//题解：根据二元函数，当a大于0的时候开口向上
//由于a和b和c都为正整数，所以对称轴为 x = -b/2a，为负数
//即对称轴在y轴的左侧，那么对于右侧的值来说，为单调递增且大于0
//由于值域从1开始，所以将所有函数的值放入队列中
//优先值小的，选择完之后移动该函数的值域并再次放入队列中

const int MAXN = 1e4+5;
struct fun{//记录函数项
    int a,b,c;
}f[MAXN];
struct node{
    int val,id;
    friend bool operator < (node a, node b) {
        return a.val > b.val;//优先值小的
    }
};
int pos[MAXN];//记录每个函数当前的值域
int cal(int id) {//计算id函数的值
    return f[id].a*pos[id]*pos[id]+f[id].b*pos[id]+f[id].c;
}
int main() {
    int n,m;
    priority_queue<node> q;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>f[i].a>>f[i].b>>f[i].c;
        pos[i] = 1;//初始化值域都为1
        q.push({cal(i), i});
    }
    for(int i = 1;i <= m;i++) {//总共取m个数
        node tmp = q.top();
        q.pop();
        cout<<tmp.val<<" ";
        pos[tmp.id]++;//值域++
        q.push({cal(tmp.id), tmp.id});//更新函数值，并再次放入队列中
    }
    return 0;
}
