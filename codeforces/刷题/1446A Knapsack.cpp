#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
struct node{
    int index;
    ll val;
    friend bool operator < (node a,node b) {
        return a.val > b.val;
    }
}a[MAXN];
int main() {
    int t;cin>>t;
    while(t--) {
        ll n,m;cin>>n>>m;
        for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].index = i;
        int flag = 0;
        for(int i = 1;i <= n;i++) {
            if(a[i].val>=(m+1)/2&&a[i].val<=m) {
                cout<<"1\n"<<a[i].index<<"\n";
                flag = 1;break;
            }
        }
        if(flag) continue;
        sort(a+1,a+n+1);
        vector<int> ans;
        ll sum = 0;
        for(int i = 1;i <= n;i++) {
            if(sum+a[i].val>m) continue;
            else {
                sum += a[i].val;
                ans.push_back(a[i].index);
                if(sum>=(m+1)/2) break;
            }
        }
        //可能剩余的也不满！！！
        if(sum<(m+1)/2||ans.empty()) cout<<"-1\n";
        else {
            cout<<ans.size()<<"\n";
            for(int i = 0;i < ans.size();i++) {
                if(i!=0) cout<<" ";
                cout<<ans[i];
            }
            cout<<"\n";
        }
    }
    return 0;
}
