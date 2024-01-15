#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：对于 a/b/c 来说，a一定是分子，b一定是分母
//因为 (a/b)/c = a/(b*c), a/(b/c) = (a*c)/b
//所以对于原题来说，要使结果为整数，必须使分母尽量少，分子尽量多
//也就是说对于第二位后面的数来说，尽量成为分子
//那么有 a1/a2/a3/a4/a5 = a1/(a2/a3/a4/a5) = a1/(a2/(a3*a4*a5))
// = a1*((a3*a4*a5)/a2)) = (a1*a3*a4*a5)/a2
//也就是a2为分母，其他数都为分子
//那么将a2与其他数约分，结果为1即为整数，否则不是

const int MAXN = 1e4+5;
int a[MAXN];
int gcd(int a,int b) {//最大公约数
    return b==0?a:gcd(b,a%b);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        a[2] = a[2]/gcd(a[2],a[1]);//a2与a1约分
        if(a[2]==1) {//为整数
            cout<<"Yes\n";
            continue;
        }
        for(int i = 3;i <= n;i++) {//剩余所有数，逐个约分
            a[2] /= gcd(a[2],a[i]);
            if(a[2]==1) break;//为1直接结束
        }
        if(a[2]==1) cout<<"Yes\n";//为1说明为整数（无需flag标记
        else cout<<"No\n";
    }
    return 0;
}
