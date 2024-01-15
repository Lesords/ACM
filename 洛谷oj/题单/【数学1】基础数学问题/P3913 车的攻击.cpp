#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：记录所有有车的行和列，去重
//然后被攻击的格子数量即为所有行和列数量，再扣除中间重复的部分
//中间重复部分的数量 = 行数 * 列数（可画图理解
//被攻击的数量 = n*行数 + n*列数 - 行数*列数

const int MAXN = 1e6+5;
int r[MAXN],c[MAXN];//记录对应车的行和列
int main() {
    ios::sync_with_stdio(0);//加速
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= k;i++) {
        cin>>r[i]>>c[i];
    }
    sort(r+1,r+k+1);//左闭右开！！！
    sort(c+1,c+k+1);
    int posr = unique(r+1,r+k+1)-r-1;//左闭右开！！！
    int posc = unique(c+1,c+k+1)-c-1;//需-1，unique为去重后的下一个位置
    cout<<n*1ll*(posr+posc)-(posr*1ll*posc);
    return 0;
}
