#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int n,ans = 0,tmp = 1;//ans�����ܺͣ�tmp���㵱ǰ�׳�ֵ
    cin>>n;
    for(int i = 1;i <= n;i++) {
        tmp *= i;//��
        ans += tmp;//�ۼ�
    }
    cout<<ans;
    return 0;
}
