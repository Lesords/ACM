#include<iostream>
#include<algorithm>
using namespace std;
int a[1005];
int main() {
    int n,even = 0,odd = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;cin>>tmp;
        if(tmp%2) odd++;
        else even++;
    }
    cout<<odd<<" "<<even;
    return 0;
}
