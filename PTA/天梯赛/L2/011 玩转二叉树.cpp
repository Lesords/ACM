#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 33;

//题解：直接在利用中序遍历和前序遍历建树的时候交换左右儿子的编号
//然后利用bfs输出层次序列

int a[MAXN], b[MAXN],tree[MAXN],l[MAXN],r[MAXN],cnt;
void solve(int rt,int left,int right,int L,int R) {
    //rt为当前根节点，left、right为中序遍历的范围，L、R为前序遍历的范围
    tree[rt] = b[L];//根节点
    int pos = 0;//记录根节点的位置
    for(int i = left;i <= right;i++) {//寻找根节点在中序遍历的位置
        if(a[i]==b[L]) {
            pos = i;break;
        }
    }
    int Lnum = pos-left;//计算左子树的数量
    int Rnum = right-pos;//计算右子树的数量
    if(pos>left) {//如果有左子树
        ++cnt;
        r[rt] = cnt;//交换左右子树编号
        solve(cnt,left,pos-1,L+1,L+Lnum);//继续递归
    }
    if(pos<right) {//如果有右子树
        ++cnt;
        l[rt] = cnt;//交换左右子树编号
        solve(cnt,pos+1,right,R-Rnum+1,R);//继续递归
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) cin>>b[i];
    cnt = 1;//初始化
    solve(1,1,n,1,n);
    queue<int> q;
    int flag = 0;
    q.push(1);//初始化起点
    while(!q.empty()) {//bfs输出层次遍历
        int now = q.front();
        q.pop();
        if(flag) cout<<" ";
        else flag = 1;
        cout<<tree[now];
        if(l[now]) q.push(l[now]);//如果有左儿子
        if(r[now]) q.push(r[now]);//如果有右儿子
    }
    return 0;
}
