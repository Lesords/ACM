#include<iostream>//ac
using namespace std;
int main() {
    int tmp,cnt = 0,ans = 0;
    while(cin>>tmp) {
        ++cnt;
        if(ans==0&&tmp==250) {//找到第一个250的位置即可
            ans = cnt;
        }
    }
    cout<<ans<<endl;
    return 0;
}
