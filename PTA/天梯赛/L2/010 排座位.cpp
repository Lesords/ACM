#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e2+5;

//题解：利用并查集保存朋友的间接关系，用二维数组保存朋友的直接关系！！！
//因为敌人只需要判断直接关系，且数据范围较小，故可直接用二维数组

int a[MAXN][MAXN],fa[MAXN];//a数组保存两者之间的直接关系，fa保存朋友的关系链（间接关系）
int getF(int x) {//路径压缩
    return fa[x]==x?x:fa[x] = getF(fa[x]);
}
void Merge(int x,int y) {//合并
    x = getF(x),y = getF(y);
    if(x!=y) fa[y] = x;//向左合并
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) fa[i] = i;//初始化
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y] = a[y][x] = z;//敌人只需要保存直接敌人！！！
        if(z==1) {//朋友才需要并查集
            Merge(x,y);
        }
    }
    for(int i = 1;i <= k;i++) {
        int x,y;
        cin>>x>>y;
        if(a[x][y]==1) cout<<"No problem\n";//直接朋友
        else if(a[x][y]==-1) {//直接敌人
            if(getF(x)==getF(y)) cout<<"OK but...\n";//有共同朋友
            else cout<<"No way\n";
        }
        else cout<<"OK\n";//什么都没有
    }
    return 0;
}
