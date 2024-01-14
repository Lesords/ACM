#include<iostream>//ac
using namespace std;
int solve(int n) {//¼ÆËãÖµ
    int ans = 1;
    for(int i = 1;i <= n;i++) ans *= 2;
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<"2^"<<n<<" = "<<solve(n);
    return 0;
}
