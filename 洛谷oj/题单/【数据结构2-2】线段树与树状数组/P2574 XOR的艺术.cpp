#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//题解：由于与1异或相当于取反
//所以可以用lazy标记需要取反的区间
//lazy为0表示不需要取反，lazy为1表示需要取反

const int MAXN = 2e5+5;
struct node{
    int l,r,val,chg;//val记录1的数量，chg表示是否需要取反
}tree[MAXN<<2];
int a[MAXN];//原数据
void build(int pos,int l,int r) {//建树
    tree[pos].l = l,tree[pos].r = r;//记录当前节点的左右边界
    if(l==r) {//叶子节点，则更新值
        tree[pos].val = a[l];
        return ;
    }
    int mid = (l+r)/2;
    build(pos*2, l, mid);//左右两个子树
    build(pos*2+1, mid+1, r);
    tree[pos].val = tree[pos*2].val + tree[pos*2+1].val;//取和
}
void push_down(int pos,int len) {//当前节点为pos，并且宽度为len
    if(tree[pos].chg) {//若当前有标记
        tree[pos*2].chg ^= 1;//将标记移向两个子树
        tree[pos*2+1].chg ^= 1;
        tree[pos].chg = 0;//并清除当前标记
        //更新左右子树的数量
        // len>>1为右子树的数量，则 (len - (len>>1) ) 为左子树的数量
        tree[pos*2].val = (len-(len>>1))-tree[pos*2].val;//取反后的数量
        tree[pos*2+1].val = (len>>1) - tree[pos*2+1].val;
    }
}
void change(int pos,int l,int r) {// [l,r]为操作区间
    if(l<=tree[pos].l&&tree[pos].r<=r) {
        //整个区间都需要操作时，只修改当前位置，并添加一个lazy标记
        tree[pos].chg ^= 1;
        tree[pos].val = (tree[pos].r-tree[pos].l+1) - tree[pos].val;
        return;
    }
    //传递标记的时候，记得长度用的不是l和r！！！
    push_down(pos, tree[pos].r-tree[pos].l+1);
    int mid = (tree[pos].l+tree[pos].r)/2;
    if(l<=mid) {//左子树有相交部分
        change(pos*2, l, r);
    }
    //记住左子树判断点为 mid+1 ！！！
    if(r>=mid+1) {//右子树有相交部分
        change(pos*2+1, l, r);
    }
    //修改后，记得更新当前节点的值！！！
    tree[pos].val = tree[pos*2].val + tree[pos*2+1].val;
}
int query(int pos, int l,int r) {// [l,r] 为查询区间
    //若包括了当前节点的整个区间，则直接返回
    if(l<=tree[pos].l&&tree[pos].r<=r) {
        return tree[pos].val;
    }
    push_down(pos, tree[pos].r-tree[pos].l+1);//向下传递lazy标记
    int mid = (tree[pos].l+tree[pos].r)/2;
    int ans = 0;//统计结果
    if(l<=mid) ans += query(pos*2, l, r);//统计左子树
    //注意 右子树 起点为 mid+1 ！！！
    if(r>=mid+1) ans += query(pos*2+1, l, r);//统计右子树
    return ans;//返回结果
}
int main() {
    int n,m;
    string s;
    cin>>n>>m>>s;
    for(int i = 0;i < s.size();i++) a[i+1] = s[i]=='1';//记录原数组
    build(1,1,n);//建树
    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==0) {
            change(1,l,r);//修改区间 [l,r]
        }
        else {
            //查询区间 [l,r] 的结果
            cout<<query(1,l,r)<<"\n";
        }
    }
    return 0;
}
