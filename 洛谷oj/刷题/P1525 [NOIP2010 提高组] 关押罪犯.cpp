#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：种类并查集
//由于只有两个监狱，那么对于任意两个罪犯而言，要么处于同一个监狱要么不处于同一个监狱
//如果a和b不在一个监狱，b和c也不在一个监狱，那么对于a和c一定在同一个监狱里
//那么记录不在一个监狱里的情况，可以用种类并查集来解决
//例：Merge(a,b+n),Merge(b,a+n); Merge(b,c+n),Merge(c,b+n);
//对于第一次合并而言：fa[b+n] = a;
//对于第二次合并而言：fa[fa[b+n]] = c  =>  fa[a] = c; 即a和c在同一监狱
//注意：合并的顺序，利用虚点向实点合并！！！
//由于需要使最后的影响力最小，也就是说两名罪犯之间的怨恨值最小
//那么可以根据怨恨值从大到小排序，尽量使怨恨值大的罪犯不在同一监狱
//如果当前两个罪犯已经在同一监狱了，那么当前罪犯的怨气值即为结果

const int MAXN = 2e4+5;
const int MAXM = 1e5+5;
struct node{
    int a,b,c;
    friend bool operator < (node x,node y) {
        return x.c > y.c;//根据怨气值从大到小排序
    }
}rel[MAXM];
int fa[MAXN*2];//记录祖先的值（两倍空间）
int getf(int pos) {//路径压缩，找祖先节点
    return fa[pos]==pos?pos:fa[pos]=getf(fa[pos]);
}
void Merge(int a,int b) {//b向a合并，即b的祖先为a
    a = getf(a);
    b = getf(b);
    if(a==b) return;
    fa[b] = a;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= 2*n;i++) fa[i] = i;//初始化祖先为本身
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        rel[i] = {a,b,c};           //记录所有关系
    }
    sort(rel+1,rel+m+1);            //排序
    for(int i = 1;i <= m;i++) {     //遍历所有关系，分配罪犯
        node tmp = rel[i];
        if(getf(tmp.a)==getf(tmp.b)) {//当前两个罪犯已经在同一监狱，则直接输出
            cout<<tmp.c<<"\n";
            return 0;
        }
        Merge(tmp.a, tmp.b+n);      //虚点向实点合并
        Merge(tmp.b, tmp.a+n);
        if(i==m) {                  //如果遍历到最后都没有怨气值，那么输出0
            cout<<"0\n";
        }
    }
    return 0;
}
