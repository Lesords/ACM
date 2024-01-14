#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t,flag = 0;
    cin>>t;
    while(t--) {
        int n,l;
        cin>>n>>l;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+n+1);//从小到大排序
        int one = 1,two = n, ans = 0;
        while(one<=two) {
            if(one==two) {//两个相等表示还剩下最后一个人！！！
                ans++;break;
            }
            if(a[one]+a[two]>l) two--;//两个太大了，则只选大的
            else one++,two--;//否则两个都选
            ans++;
        }
        if(flag) cout<<"\n";//中间空格
        flag = 1;
        cout<<ans<<"\n";
    }
    return 0;
}
