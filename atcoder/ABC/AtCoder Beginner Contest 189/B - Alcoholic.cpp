#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
    int n,x,ans = -1,sum = 0;
    cin>>n>>x;
    for(int i = 1;i <= n;i++) {
        int v,p;
        cin>>v>>p;
        sum += v*p;//浮点运算会出错，所以转换为整数判断
        if(sum>x*100) {//x*100判断即可！！！
            ans = i;break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
