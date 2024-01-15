#include<iostream>//ac  二维前缀和
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：预处理二维前缀和，然后根据容斥定理更新c长的正方形的最大值

const int MAXN = 1e3+5;
int a[MAXN][MAXN],pre[MAXN][MAXN];//pre记录二维前缀和
int main() {
    int n,m,c;
    cin>>n>>m>>c;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
            //容斥定理更新二维前缀和 三个部分 - 重复部分
            pre[i][j] = pre[i][j-1]+pre[i-1][j]+a[i][j]-pre[i-1][j-1];
        }
    }
    int ans = -INF,ansx = 0,ansy = 0;//ans为大小，ansx和ansy存坐标
    for(int i = c;i <= n;i++) {//i和j都从c开始遍历（满足c长）
        for(int j = c;j <= m;j++) {
            //容斥定理求面积
            int tmp = pre[i][j]-pre[i-c][j]-pre[i][j-c]+pre[i-c][j-c];
            if(tmp>ans) {//更新较大值和对应坐标
                ansx = i,ansy = j;
                ans = tmp;
            }
        }
    }
    //ansx，ansy保存的是右下角，需修改成左上角
    cout<<ansx-c+1<<' '<<ansy-c+1<<endl;
    return 0;
}
