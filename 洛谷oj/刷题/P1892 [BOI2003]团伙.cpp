#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：并查集+虚点
//由于敌人的敌人是朋友
//建立一个虚点 x+n 表示敌人
//例：x与y为敌人，那么Merge(x,y+n),Merge(y,x+n)
//    x与z为敌人，那么Merge(x,z+n),Merge(z,x+n)
//在第一个合并时，fa[x+n] = y
//在第二次合并时，fa[fa[x+n]] = z => fa[y] = z
//即 使得z和y合并，为朋友关系，满足敌人的敌人为朋友
//需要注意的是：合并的时候是把虚点向实点合并，否则只有敌人关系的时候，会漏算

const int MAXN = 2e3+5;
int fa[MAXN];
int getf(int pos) {//路径压缩
    return fa[pos]==pos?pos:fa[pos]=getf(fa[pos]);
}
void Merge(int x,int y) {//向左合并，父节点为x
    x = getf(x);
    y = getf(y);
    if(x==y) return ;
    fa[y] = x;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n*2;i++) fa[i] = i;  //初始化为本身，包括虚点初始化
    for(int i = 1;i <= m;i++) {
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        if(ch=='E') {
            Merge(x,y+n);                   //虚点向实点合并！！！
            Merge(y,x+n);
        }
        else Merge(x,y);                    //朋友则直接合并即可
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {             //统计独立的，即为团伙数量
        if(fa[i]==i) ans++;
    }
    cout<<ans;
    return 0;
}
/*
只包含敌人关系的样例
5
2
E 1 2
E 3 4
*/
