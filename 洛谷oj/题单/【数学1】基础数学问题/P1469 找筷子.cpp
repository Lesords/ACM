#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���� a^a = 0, 0^a = a
//����������㽻����
//���Զ�����ͬ�߶ȵĿ��ӣ����Ľ��Ϊ0
//��ô�����п����������ֵ��Ϊ�䵥�Ŀ���
//��Ϊ��˫�Ŀ�������Ϊ0

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//����
    int n,tmp,ans = 0;//��ʼ��Ϊ0
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp;
        ans ^= tmp;//�����������
    }
    cout<<ans;
    return 0;
}
