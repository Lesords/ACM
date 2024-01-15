#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：计算只有k条边的最大生成树
//在选择边的时候记录边的数量，已选择k条则直接结束

const int MAXN = 1e5+5;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b) {
        return a.z > b.z;//优先选择边权大的
    }
}a[MAXN];
int dis[MAXN];//记录祖先
int getf(int p) {//寻找p的祖先
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) dis[i] = i;//初始化为本身
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};//存边
    }
    sort(a+1,a+m+1);//排序（从大到小
    int ans = 0;
    for(int i = 1;i <= m;i++) {//m为范围，而不是k，因为有些边不满足条件！！！
        node tmp = a[i];
        if(getf(tmp.x)!=getf(tmp.y)) {//若还未在生成树中，则连接
            ans += tmp.z;//添加边权值
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//向左合并
            k--;//可选择的边数--
        }
        if(k==0) break;//为0，表示没得选了，直接结束
    }
    cout<<ans;
    return 0;
}
