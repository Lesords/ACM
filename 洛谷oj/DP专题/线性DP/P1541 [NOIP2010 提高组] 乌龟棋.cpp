#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：线性dp，直接暴力
//由于卡片类型只有四种，并且每种最多只有40个
//所以可以先统计每个卡片的数量
//然后以 四种卡片 为状态
//则有f[i][j][k][z]:用了i个1，j个2，k个3，z个4后获取的最大分数
//那么对于每种状态可以四种情况推出来，即四个卡片上个不选
//注意：初始位置为1，所有不用任意卡片的分数为a[1]
//并且状态转移的时候，获取的卡片分数也要从1开始累加

const int MAXM = 350;
const int MAXN = 45;
int f[MAXN][MAXN][MAXN][MAXN],num[5],a[MAXM];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++) {
        int tmp;
        cin>>tmp;
        num[tmp]++;                         //统计卡片出现的次数
    }
    f[0][0][0][0] = a[1];                   //边界，首位置的分数
    for(int i = 0;i <= num[1];i++) {        //四种卡片，可以从0开始（因为其他卡片不一定为0
        for(int j = 0;j <= num[2];j++) {
            for(int k = 0;k <= num[3];k++) {
                for(int z = 0;z <= num[4];z++) {
                    int pos = 1+i+j*2+k*3+z*4;//计算使用四种卡片之后，移动到的位置
                    //对应卡片数量存在才可以转移！！！
                    if(i) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i-1][j][k][z] + a[pos]);
                    }
                    if(j) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i][j-1][k][z] + a[pos]);
                    }
                    if(k) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i][j][k-1][z] + a[pos]);
                    }
                    if(z) {
                        f[i][j][k][z] = max(f[i][j][k][z], f[i][j][k][z-1] + a[pos]);
                    }
                }
            }
        }
    }
    cout<<f[num[1]][num[2]][num[3]][num[4]];//所有卡片都用了即为最后的结果
    return 0;
}
