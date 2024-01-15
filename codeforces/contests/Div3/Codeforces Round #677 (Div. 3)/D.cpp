#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：只要有两个帮的值不同，即有解
//以这两个帮为中心，不断扩散即可

const int MAXN = 1e4+5;
struct node{
    int val,index;//值和下标
    friend operator < (node a,node b) {
        if(a.val!=b.val) return a.val < b.val;
        return a.index < b.index;
    }
}a[MAXN];
int b[MAXN],ans[MAXN],vis[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        memset(vis,0,sizeof(vis));
        set<int> s;//记录有几种帮
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>b[i];
            a[i].val = b[i],a[i].index=i;
            s.insert(a[i].val);//插入值
        }
        sort(a+1,a+n+1);//排序
        if(s.size()<2) cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
            int index = a[1].index,val = a[1].val;//最小值（第一个中心点）
            vis[index] = 1;//标记当前点！！！
            for(int i = 2;i <= n;i++) {//遍历剩余所有点
                if(b[a[i].index]!=val) {//值不同就连接
                    cout<<index<<" "<<a[i].index<<endl;
                    vis[a[i].index] = 1;//标记已连接
                }
            }
            index = a[n].index,val = a[n].val;//最大值（第二个中心点）
            for(int i = 1;i <= n;i++) {
                if(vis[a[i].index]) continue;//跳过已标记的
                cout<<index<<" "<<a[i].index<<endl;//剩余的都连第二个中心点
            }
        }
    }
	return 0;
}
