#include<iostream>//ac
using namespace std;
int main() {
    int tmp,cnt = 0,ans = 0;
    while(cin>>tmp) {
        ++cnt;
        if(ans==0&&tmp==250) {//�ҵ���һ��250��λ�ü���
            ans = cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}
