#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    n += 2;
    if(n>7) n -= 7;//����7�Ĳ���ֱ�Ӽ���
    cout<<n;
    return 0;
}
