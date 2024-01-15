#include<iostream>//ac
#include<algorithm>
using namespace std;
int p[105], c[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int flag = 0,pp,cc;
        for(int i = 1;i <= n;i++) {
            cin>>p[i]>>c[i];
            if(flag) continue;
            if(i==1) {//初始成功人数不能大于尝试人数
                if(c[i]>p[i]) flag = 1;
            }
            pp = p[i]-p[i-1], cc = c[i]-c[i-1];
            //后面的尝试人数和成功人数都不能小于前面的
            //成功人数的差值也不能大于尝试人数的差值
            if(p[i]<p[i-1]||c[i]<c[i-1]||pp<cc) flag = 1;
        }
        cout<<(flag?"NO\n":"YES\n");
    }
    return 0;
}
