#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于需要有k个棉花糖，即分成k块
//那么对于生成树来说，点为n个，边有n-1条，那么要想有k个生成树，需要减去(k-1)条边
//即所需要的边为：(n-1)-(k-1) = n-k
//也就是对原图进行Kruskal且只连接 n-k 条较小边即可

const int MAXN = 1e3+5;
const int MAXM = 1e4+5;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b) {
        return a.z < b.z;//优先边权小的
    }
}a[MAXM];
int dis[MAXN];//记录祖先
int getf(int p) {//寻找p的祖先，路径压缩
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) dis[i] = i;//初始化祖先为本身！！！
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};//存边
    }
    if(k>n) {//棉花糖数量比云朵数量多，无解
        cout<<"No Answer\n";
        return 0;
    }
    sort(a+1,a+1+m);//排序
    int ans = 0,num = 0;//ans为结果，num为当前选择的边数
    for(int i = 1;i <= m;i++) {
        node tmp = a[i];
        if(getf(tmp.x)!=getf(tmp.y)) {//还未在生成树中，则连接
            ans += tmp.z;//添加边权值
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//向左合并
            num++;//数量++
        }
        if(num==n-k) break;//只需要n-k条边
    }
    if(num!=n-k) cout<<"No Answer\n";//不到n-k条，说明无解
    else cout<<ans;
    return 0;
}
