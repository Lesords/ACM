#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    n += 2;
    if(n>7) n -= 7;//超过7的部分直接减掉
    cout<<n;
    return 0;
}
