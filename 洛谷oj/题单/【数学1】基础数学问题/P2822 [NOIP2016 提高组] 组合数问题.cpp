#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e3+5;

//题解：根据组合数学公式，C(n,m) = C(n,n-m) C(n,m) = C(n-1,m) + C(n-1,m-1)
//根据后一个公式，可知，组合数学最后的结果为杨辉三角
//由于数据范围只为2e3，所以可以利用递推预处理组合数
//然后利用二维前缀和计算区间内满足条件的数量

int c[MAXN][MAXN],ans[MAXN][MAXN+1];                //c数组存储组合数，ans为二维前缀和
int t,k;                                            //第二维需要多一个（计算值包括MAXN！！！
void init() {
    c[1][0] = c[1][1] = c[0][0] = 1;                //边界初始化（数据从0开始
    for(int i = 2;i < MAXN;i++) {                   //从2开始
        c[i][0] = 1;                                //边界点为1
        for(int j = 1;j <= i;j++) {                 //只需要计算到i
            c[i][j] = (c[i-1][j]+c[i-1][j-1])%k;    //取模，可以整除，就是余数为0
            ans[i][j] = ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];//容斥计算二维前缀和
            if(!c[i][j]) ans[i][j]++;               //若为0，结果++
        }
        ans[i][i+1] = ans[i][i];                    //继承，越界！！！
        //二维前缀和计算过程需要垂直方向上一个的值，所以需多算 一个
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t>>k;
    init();                                         //初始化
    while(t--) {
        int n,m;
        cin>>n>>m;
        if(m>n) m = n;                              //m超过n，则取n
        cout<<ans[n][m]<<"\n";
    }
    return 0;
}
