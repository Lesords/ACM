#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
char a[MAXN],b[MAXN],val[MAXN];//a存中序遍历数组，b前序遍历数组，val存当前节点的字符
int len,cnt,Left[MAXN],Right[MAXN];//cnt为节点编号，Left为左二子，Right为右儿子
int idx(char ch) {//字符转数字
    return ch-'A';
}
//id为当前节点编号，l、r为前序遍历区间，L、R为中序遍历区间
void solve(int id,int l,int r,int L,int R) {
    if(l>r) return;
    char rt = b[l];//根的字符
    val[id] = rt;//存储当前节点的字符
    int pos = 0;//存储根在中序遍历数组的位置
    for(int i = L;i <= R;i++) {//寻找根在中序遍历数组的位置
        if(a[i]==rt) {
            pos = i;break;
        }
    }
    int lnum = pos-L;//左子树的数量
    int rnum = R-pos;//右子树的数量
    if(lnum) {//如果存在左子树
        ++cnt;
        Left[id] = cnt;//记录当前节点的左儿子
        //以l为边界+lnum
        solve(cnt,l+1,l+lnum,L,pos-1);
    }
    if(rnum) {//如果存在右子树
        ++cnt;
        Right[id] = cnt;//记录当前节点的右儿子
        //以r为边界-rnum+1
        solve(cnt,r-rnum+1,r,pos+1,R);
    }
}
void postorder(int rt) {//后序遍历
    if(Left[rt]) {
        postorder(Left[rt]);
    }
    if(Right[rt]) {
        postorder(Right[rt]);
    }
    cout<<val[rt];
}
int main() {
    cin>>a+1>>b+1;
    len = strlen(a+1);
    cnt = 1;//初始化为1！！！
    solve(1,1,len,1,len);
    postorder(1);
    return 0;
}
