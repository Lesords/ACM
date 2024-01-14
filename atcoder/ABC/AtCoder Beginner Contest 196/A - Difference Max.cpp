#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int a,b,c,d,ans = -10000;
    cin>>a>>b>>c>>d;
    for(int i = a;i <= b;i++) {
        for(int j = c;j <= d;j++) {
            ans = max(ans, i-j);
        }
    }
    cout<<ans;
    return 0;
}
