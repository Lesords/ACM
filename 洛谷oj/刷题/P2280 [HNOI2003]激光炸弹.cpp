#include<iostream>//ac 二维前缀和
#include<algorithm>
using namespace std;

//题解：把点理解成块进行计算，二维前缀和（容斥定理计算前缀和）即可

const int MAXN = 5e3+5;
int sum[MAXN][MAXN],n,m;
int main() {
    cin>>n>>m;
    int x,y,v,maxx = m,maxy = m,ans = 0;//maxx和maxy初始化的值为m
    while(n--) {
        cin>>x>>y>>v;
        //用+=来处理目标在同一点的可能
        sum[++x][++y] += v;//原数据初始起点从0开始，整体右移
        maxx = max(maxx,x);//记录最长的x和y
        maxy = max(maxy,y);
    }
    for(int i = 1;i <= maxx;i++) {//二维前缀和（容斥定理）
        for(int j = 1;j <= maxy;j++) {
            sum[i][j] += sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];//两块-交叉处
        }
    }
    for(int i = m;i <= maxx;i++){//遍历所有的m长正方形，取最大值
        for(int j = m;j <= maxy;j++) {
            //去掉两个多余块，添加一个交叉块
            ans = max(ans,sum[i][j]-sum[i][j-m]-sum[i-m][j]+sum[i-m][j-m]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
