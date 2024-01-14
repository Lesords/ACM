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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

//题解：Cx,y计算公式其实是从 (x,y) 开始，最多扩大3个位置
//然后两个矩阵对应位置相乘，取和即为结果

//由于计算次数接近无限大，并且最后的结果保证为整数
//那么我们知道对于每个位置 (x,y) 而言，如果k矩阵都为分数
//那么一直乘之后，每个位置都会趋向于0，即最后结果为0
//因为 分数*分数 ，最后的结果会越来越小

//又由于k矩阵的结果总和为1
//那么要想当前位置有贡献，那么 k1,1 必须为1
//因为每个位置 本身 都是和 k1,1 相乘的
//所以，只要 k1,1 为1，那么最后结果即为原来的矩阵

const int MAXN = 1e3+5;
int a[MAXN][MAXN],k[5][5];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                cin>>a[i][j];
            }
        }
        int cnt = 0;
        for(int i = 1;i <= 3;i++) {
            for(int j = 1;j <= 3;j++) {
                cin>>k[i][j];
                if(k[i][j]) cnt++;
            }
        }
        //如果只有一个位置有值，并且在位置(1,1)，那么说明k1,1值为1
        int flag = cnt==1&&k[1][1];
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(j!=1) cout<<" ";
                cout<<(flag?a[i][j]:0);//值为1则为原来数组，否则为0
            }
            cout<<"\n";
        }
    }
	return 0;
}
