#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������������ȡ��ʱ��Ϊ�ذ�̬
//�� a[0]^a[1]^a[2]^������^a[n] = 0
//��ôֻ���������Ϊ0��Ϊ��ʤ̬

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,ans = 0;//��ʼ��Ϊ0����Ӱ�������
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            ans ^= tmp;//������ֵ���
        }
        //�������Ϊ0����Ϊ��ʤ̬������Ϊ�ذ�̬
        if(ans) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
