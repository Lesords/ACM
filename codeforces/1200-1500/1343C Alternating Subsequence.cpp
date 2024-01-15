#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

//题解：直接遍历一遍，寻找每一段正数或者负数的最大值，然后取和即可

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        ll ans = 0;
        for(int i = 1;i <= n;) {//i的位置由每次判断决定
            if(a[i]>0) {//正数段
                ll tmp = 0;//初始化为0（对应整数来说最小）
                for(int j = i;j <= n;j++) {
                    if(a[j]<0) {//不为正数，则结束并修改i的值
                        i = j;break;
                    }
                    tmp = max(tmp, a[j]);
                    if(j==n) i = j+1;//特判最后一个数也为正数段
                }
                ans += tmp;
            }
            else {//负数段
                ll tmp = -INF;
                for(int j = i;j <= n;j++) {
                    if(a[j]>0) {//为正数，则结束并修改i的位置
                        i = j;break;
                    }
                    tmp = max(tmp, a[j]);
                    if(j==n) i = j+1;//特判最后一个位置
                }
                ans += tmp;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
