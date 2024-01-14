#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    double a,b,ans;
    int op;
    cin>>a>>op>>b;
    if(op) {
        ans = a*1.26;
    }
    else {
        ans = a*2.455;
    }
    printf("%.2f ",ans);
    if(ans<b) cout<<"^_^";
    else cout<<"T_T";
    return 0;
}
