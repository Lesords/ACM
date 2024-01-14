#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：可以将二维压成一维，计算每行的前缀和，可以O(1)求区间和
//每次枚举左右两个端点的位置，然后此时的区间 (l,r) 可以O(1)求出
//可以理解为一个点，那么对于被选中的区间列来说可以是一个垂直的一维状态
//也可以理解为把n列合并成一列！！！
//然后利用一维求最大子段和的方法来计算该区间列，更新答案即可

const int MAXN = 105;
int sum[MAXN][MAXN],n;
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int tmp;
            cin>>tmp;
            sum[i][j] = sum[i][j-1] + tmp;//当前行的前缀和
        }
    }
    int ans = -INF;//初始化为最小值
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {//遍历列的起点和终点
            int num = 0;//区间和初始化为0
            for(int k = 1;k <= n;k++) {//遍历所有行（相当于一维状态
                if(num<0) num = 0;//小于0，则修改为0
                num += sum[k][j]-sum[k][i-1];//添加当前行的区间和
                ans = max(ans,num);//更新答案
            }
        }
    }
    cout<<ans;
    return 0;
}
