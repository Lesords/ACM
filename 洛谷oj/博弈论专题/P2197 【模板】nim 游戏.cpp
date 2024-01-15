#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：当所有数都被取走时，为必败态
//即 a[0]^a[1]^a[2]^···^a[n] = 0
//那么只有异或结果不为0即为必胜态

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = 0;//初始化为0，不影响异或结果
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            ans ^= tmp;//与所有值异或
        }
        //若结果不为0，则为必胜态，否则为必败态
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
