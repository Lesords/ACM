#include<iostream>//ac
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int solve(int val) {
    int ans = 0;
    while(val) {
        ans += val%10;
        val /= 10;
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,num = 0,flag = 0;
        cin>>n;
        for(int i = 2;i <= 9;i++) {
            int tmp = n*i;
            int ans = solve(tmp);
            if(i==2) {
                num = ans;
            }
            else {
                if(num!=ans) {
                    flag = 1;
                }
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<num<<"\n";
    }
    return 0;
}
