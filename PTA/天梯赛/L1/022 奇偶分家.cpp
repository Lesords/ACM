#include<iostream>//ac
using namespace std;
int main() {
    int n,odd = 0,even = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;cin>>tmp;
        if(tmp%2) odd++;//ֱ�Ӽ�¼��ż��
        else even++;
    }
    cout<<odd<<" "<<even;
    return 0;
}
