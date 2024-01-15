#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：若a为n的因子，则 b = n-a，那么 max(a,b) % min(a,b) = 0
//所以lcm(a,b)的值最大为max(a,b)
//也就是说最大公倍数最大为两者间最大的那个值
//所以，可以遍历n的因子，取最大因子，则另外一个数可以相应减小

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int fac = n;//初始化为n，防止n为质数的特殊情况！！！
        for(int i = 2;i*i <= n;i++) {
            if(n%i==0) {//最小因子 -> n/fac 即为最大因子
                fac = i;break;
            }
        }
        cout<<n/fac<<" "<<(n - n/fac)<<"\n";
    }
    return 0;
}
