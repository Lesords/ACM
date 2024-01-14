#include<iostream>//ac
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;

//题解：悬线法
//先记录可以向上扩张的大小
//然后根据 向上扩张的大小 为标准，来向左和向右扩张
//注意：向左和向右记录的对应位置，而不是大小
//因为会出现不满足 上一个位置 但是满足 当前位置 的情况

const int MAXN = 2e3+5;
short a[MAXN][MAXN];//卡空间，用short！！！
short l[MAXN][MAXN],r[MAXN][MAXN],u[MAXN][MAXN];//u记录向上扩张的大小
//l记录可以到达的最左位置，r记录可以到达的左右位置
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                cin>>a[i][j];
                u[i][j] = 1;//初始化向上一个
                l[i][j] = r[i][j] = j;//左右为本身
            }
        }
        //先计算向上扩张的大小
        for(int i = 2;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(a[i][j]>=a[i-1][j]) {
                    u[i][j] = u[i-1][j]+1;
                }
            }
        }
        //计算可以到达的最左位置
        for(int i = 1;i <= n;i++) {
            for(int j = 2;j <= m;j++) {
                int last = l[i][j];//记录当前可以到达的最左位置
                while(l[i][j]>1&&u[i][j]<=u[i][last-1]) {//一直查找最左位置点
                    //如果last-1满足条件，那么last-1能到达的位置一定也满足条件
                    l[i][j] = l[i][last-1];
                    last = l[i][j];//更新对应位置
                }
            }
        }
        //计算可以到达的最右位置（与上类似）
        for(int i = 1;i <= n;i++) {
            for(int j = m-1;j >= 1;j--) {
                int last = r[i][j];
                while(last<m&&u[i][j]<=u[i][last+1]) {
                    r[i][j] = r[i][last+1];
                    last = r[i][j];
                }
            }
        }
        ll ans = m;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                if(i>1&&a[i][j]>=a[i-1][j]) {
                    l[i][j] = max(l[i][j], l[i-1][j]);
                    r[i][j] = min(r[i][j], r[i-1][j]);
                }
                ll hei = u[i][j];
                ll wid = r[i][j]-l[i][j]+1;
                ans = max(ans, hei*wid);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
WA样例：
提取后：
1
3 6
2 1 2 2 2 2
1 2 1 1 1 1
2 3 2 2 2 2

原样例：
1
19 10
89  61 83 84 81 41 13 91 56 63
100 80 31 30 34 41 90 56 10 2
36  28 47 56 40 20 78 51 18 74
19  85 95 45 69 17 13 19 82 31
91  61 4  67 28 98 84 20 9 59
75  49 55 61 95 24 30 26 51 55
20  25 66 97 75 83 66 27 27 2
58  62 90 74 39 65 44 36 44 51
58  64 41 74 27 25 12 23 61 31
84  95 42 41 38 99 6  63 17 16
47  31 57 17 57 92 39 63 70 59
20  5  46 10 82 51 47 36 78 70
85  73 84 86  35 71 21 33 33 13
84  49 46 10  74 79 53 61 84 23
20  5  15 82 64 97 18 42 69 63
96  63 98 91 78 76 26 5  14 85
2   78 84 10 73 43 48 81 28 45
60  1  33 57 36 96 82 34 78 36
52  81 6  2  38 41 35 92 15 68
*/
