#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            if(tmp&1) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
