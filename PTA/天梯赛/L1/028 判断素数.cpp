#include<iostream>//ac
#define ll long long
using namespace std;
bool check(ll n) {
    if(n==1) return 0;
    for(int i = 2;i*1LL*i <= n;i++) {//�˷���int
        if(n%i==0) return 0;//��Ϊ����
    }
    return 1;//Ϊ����
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        ll tmp;
        cin>>tmp;
        if(check(tmp)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
