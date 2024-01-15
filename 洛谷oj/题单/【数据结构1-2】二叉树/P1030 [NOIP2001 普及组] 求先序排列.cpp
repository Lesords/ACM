#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
char a[MAXN],b[MAXN],tree[MAXN];//a是中序遍历数组，b是后序遍历数组，tree存储节点的字符
int len,cnt,l[MAXN],r[MAXN];//cnt为节点的编号，l存左儿子的编号，r存右儿子的编号
//id为当前节点编号，left、right为后序遍历区间，L、R为中序遍历区间
void solve(int id,int left,int right,int L,int R) {
    if(left>right) return;
    char rt = b[right];//存储根节点字符
    tree[id] = rt;
    int pos = 0;//记录中序遍历中根节点字符的位置
    for(int i = L;i <= R;i++) {//寻找根节点字符的位置
        if(a[i]==rt) {
            pos = i;break;
        }
    }
    int lnum = pos-L;//计算左子树数量
    int rnum = R-pos;//计算右子树数量
    if(lnum) {//如果存在左子树
        l[id] = ++cnt;//记录当前节点的左儿子
        //以left为左边界，lnum为区间长度
        solve(cnt, left,left+lnum-1,L,pos-1);
    }
    if(rnum) {//如果存在右子树
        r[id] = ++cnt;//记录当前节点的右儿子
        //为right-1为右边界，rnum为区间长度
        solve(cnt, right-rnum,right-1,pos+1,R);
    }
}
void preorder(int rt) {//先序遍历
    cout<<tree[rt];
    if(l[rt]) {
        preorder(l[rt]);
    }
    if(r[rt]) {
        preorder(r[rt]);
    }
}
int main() {
    cin>>a+1>>b+1;
    len = strlen(a+1);//数组起点是1！！！
    cnt = 1;
    solve(1,1,len,1,len);
    preorder(1);
    return 0;
}
