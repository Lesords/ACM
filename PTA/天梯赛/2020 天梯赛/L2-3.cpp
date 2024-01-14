#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//题解：由于完美二叉树的性质
//任何一个遍历方式都可以确定一颗完美二叉树！！！
//也就是说，直接后序遍历一颗虚的完美二叉树，a数组中对应的位置即为节点值

const int MAXN = 1e4+5;
int n,a[MAXN],tree[MAXN],cnt;//cnt为当前遍历的位置
void solve(int dot) {
    if(dot>n) return;//树总大小为n
    solve(dot<<1);
    solve(dot<<1|1);
    tree[dot] = a[++cnt];//记录值即可
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    solve(1);
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        cout<<tree[i];
    }
    return 0;
}
