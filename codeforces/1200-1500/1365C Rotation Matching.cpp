#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：由于是全排列，所以每个数字移动多少步有贡献值是固定的
//所以可以计算所有数字需要移动的步数
//然后统计某个步数可以获得的最大贡献值

const int MAXN = 2e5+5;
int a[MAXN],num[MAXN],pos[MAXN];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],pos[a[i]] = i;//记录a[i]的位置
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        int p = pos[tmp],dis = 0;//p为tmp需要移动到的位置,dis为步数
        if(i>=p) dis = i-p;//可以直接移动
        else dis = i+n-p;//需要移到n点，再移动到p
        num[dis]++;//记录dis步数的贡献值
        ans = max(ans, num[dis]);//取最大贡献值
    }
    cout<<ans<<"\n";
    return 0;
}
