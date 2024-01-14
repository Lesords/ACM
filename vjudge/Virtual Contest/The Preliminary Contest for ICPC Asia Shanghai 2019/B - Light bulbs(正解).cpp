#include<iostream>//ac 差分
#include<algorithm>
using namespace std;

//可行性证明：若两个差分操作区间不相交，则排序求解肯定成立
//若两个差分操作区间相交，那么第一个区间的末节点（开区间）会覆盖第二个区间，成为新的区间初结点
//第二个区间的初节点（包括）会抵消第一个区间，成为新的第一个区间的末节点（不包括）

const int MAXN = 1e6+6;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    for(int i = 1;i <= t;i++) {
        int n,m,cnt = 0;
        cin>>n>>m;
        for(int j = 1;j <= m;j++) {
            int x,y;
            cin>>x>>y;
            a[++cnt] = x;//记录为左闭右开，方便重叠时计算！！！
            a[++cnt] = y+1;//a数组记录对应差分位置
        }
        sort(a+1,a+cnt+1);//然后排序
        int ans = 0;
        //接着直接计算 每两个位置 的差值，累加即可
        for(int i = 1;i <= cnt;i+=2) {//跳两步！！！
            ans += a[i+1]-a[i];//左闭右开
        }
        cout<<"Case #"<<i<<": "<<ans<<"\n";
    }
    return 0;
}
