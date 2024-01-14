#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+6;
int a[MAXN];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= k;i++) {
        stack<int> sta;
        for(int j = 1;j <= m;j++) cin>>a[j];
        int pos = 1,num = 1,flag = 0;
        while(pos<=m) {
            if(sta.empty()) sta.push(num++);
            else {
                if(sta.top()==a[pos]) sta.pop(),pos++;
                else sta.push(num++);
            }
            if(sta.size()>n) {
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
