#include<iostream>//ac
#include<cstdio>
#include<string>
#define ll long long
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a,b,c;
        cin>>a>>b>>c;
        if(a*a+b*b+c*c==3*a*b*c) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
