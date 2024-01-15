#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int n,m,a[MAXN],l,r,ans;
bool check(int mid) {
    int tmp = 0,num = 1;
    for(int i = 1;i <= n;i++) {
        if(tmp+a[i]<=mid) tmp += a[i];
        else tmp = a[i],num++;
        if(num>m) return false;
    }
    if(num==m||num<m&&n>=m) return true;
    return false;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i],l = max(l,a[i]),r+=a[i];
    while(l<=r) {//二分答案，值取小
        int mid = (l+r)/2;
        if(check(mid)) ans = mid,r = mid-1;//取左一半（较小）
        else l = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
