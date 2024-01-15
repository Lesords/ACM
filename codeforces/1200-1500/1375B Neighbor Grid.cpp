#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：先计算每个空格最多的邻居块，若原数据过大，则无解
//否则每个格子都输出最多的邻居块即可

const int MAXN = 303;
int a[MAXN][MAXN],num[MAXN][MAXN];//a为原数组，num为邻居块数量数组
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,flag = 0;
        cin>>n>>m;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                int cnt = 4;//最多只要4个！！！
                cin>>a[i][j];
                if(flag) continue;
                if(i==1||i==n) cnt--;//边界则-1
                if(j==1||j==m) cnt--;//边界则-1
                num[i][j] = cnt;//记录当前格子的邻居块数量
                if(a[i][j]>cnt) flag = 1;//超过了，则无解
            }
        }
        if(flag) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i = 1;i <= n;i++) {//输出最多邻居块即可
            for(int j = 1;j <= m;j++) {
                if(j!=1) cout<<" ";
                cout<<num[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}
