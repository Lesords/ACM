#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：统计所有数字的出现次数，利用埃式法的思想
//将每个数，向后翻倍累加数量（注意本身需-1）
//注意：边界需要相等，例:边界为12，原数为5，12/5 = 2
//若不计算 2*5 的话，那么对于10来说忽略了一种情况


const int MAXN = 1e5+5;
const int MAXV = 1e6;
int num[MAXV+1],ans[MAXV+1],a[MAXN];//a为原数组
//num记录数字出现次数，ans为每个数的因子数量
void solve() {
    for(int i = 1;i <= MAXV;i++) {              //遍历所有数字
        if(num[i]==0) continue;                 //跳过未出现的数字
        //倍数从1开始，因为需要包括本身
        for(int j = 1;j <= MAXV/i;j++) {        //需要相等！！！
            ans[i*j] += num[i];                 //累加 i*j 有因子i
            if(i*j==i) ans[i]--;                //本身需-1
        }
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        num[a[i]]++;                            //统计数字的出现次数
    }
    solve();
    for(int i = 1;i <= n;i++) cout<<ans[a[i]]<<"\n";
    return 0;
}
