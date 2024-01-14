#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
int a[MAXN] = {1},n,c;
int solve(int pos) {
    int tmp = 0;
    for(int i = 0;i < pos;i++) {
        tmp = max(a[pos&i],tmp);
    }
    return tmp*c;
}
int main() {
    cin>>n>>c;
    for(int i = 1;i <= n;i++) {
        a[i] = solve(i);
    }
    for(int i = 1;i <= n;i++) {
        cout<<i<<" "<<a[i]<<endl;
    }
    return 0;
}
