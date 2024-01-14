#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    if(m%2) cout<<"1 "<<(n<<(m/2));
    else cout<<"0 "<<(n<<(m/2));
    return 0;
}
