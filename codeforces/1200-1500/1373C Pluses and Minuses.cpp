#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//题解：由于cur需要>=0才能结束
//所以如果第i个的cur<0，那么对答案的贡献就是i（i次循环）
//而对于cur来说则是 +1 (下一次大循环起点加1)

const int MAXN = 1e6+6;
char s[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>(s+1);
        int len = strlen(s+1);
        ll sum = 0,ans = len;//数据爆int
        //ans初始化为len，因为结束循环必须循环len次
        for(int i = 1;i <= len;i++) {
            sum += (s[i]=='+')?1:-1;//计算加减操作
            if(sum<0) {//小于0，则当前位置有贡献
                sum += 1;//下次起点+1，相当于当前位置+1
                ans += i;//当前位置的贡献为i（i次循环）
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
