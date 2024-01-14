#include<iostream>//ac
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        char op;
        double a,ans = 0;
        cin>>op>>a;
        if(op=='M') ans = a/1.09;//求女生身高
        else ans = a*1.09;//求男生身高
        printf("%.2f\n",ans);//自动四舍五入，无需处理
    }
    return 0;
}
