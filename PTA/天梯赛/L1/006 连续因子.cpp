#include<iostream>//ac
#include<algorithm>
using namespace std;
bool is_prime(int n) {//�ж�n�Ƿ�Ϊ����
    for(int i = 2;i*1ll*i <= n;i++) {
        if(n%i==0) return 0;
    }
    return 1;//1��ʾ������
}
int main() {
    int n,ans = 0,index = 0;
    cin>>n;
    if(is_prime(n)) {//�������Ƿ�Ϊ����������
        cout<<"1\n"<<n;//��Ϊ������ֻ��һ�������������
        return 0;
    }
    for(int i = 2;i*1LL*i <= n;i++) {//����ֱ�ӱ����������ӣ��������������
        if(n%i) continue;//�����������ӵ���
        int tmp = n,num = 0;//tmpΪ��ǰ��������numΪ��ǰ������������
        for(int j = i;j <= n;j++) {//ֱ�ӱ���
            if(tmp%j==0) tmp /= j,num++;//�ɱ�����
            else break;//�������������
        }
        if(num>ans) {//���½ϴ�ֵ
            ans = num;
            index = i;//index�����һ�����ӵĴ�С
        }
    }
    cout<<ans<<"\n";
    for(int i = 0;i < ans;i++) {//��ans������
        if(i!=0) cout<<"*";
        cout<<index+i;
    }
    return 0;
}
