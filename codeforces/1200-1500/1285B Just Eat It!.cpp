#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//题解：由于选段只能删除头部或尾部
//所以可以计算前缀和 或 后缀和是否出现负数或0（删除该前缀或后缀会大于等于总和）
//若有，则为NO，否则为YES

const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,flag = 0;
        ll sum = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i < n;i++) {//计算前缀（不包括最后一位）
            sum += a[i];
            if(sum<=0) {//出现非正数
                flag = 1;break;
            }
        }
        sum = 0;
        for(int i = n;i > 1;i--) {//计算后缀（不包括第一位）
            sum += a[i];
            if(sum<=0) {//出现非正数
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";//NO为不满意
        else cout<<"YES\n";
    }
    return 0;
}
