#include<iostream>//ac
#include<map>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;

//���⣻�����䳤Ϊ����͵���������ô��ÿ�������ֵ-1�����԰�����ת��Ϊ
//�������Ϊ0������
//����ǰ׺�ͼ��㵱ǰ������ͣ���������Ϊ0������++
//�����䲻Ϊ0������Ϊk����ô��ȥǰ�������Ϊk�� ��ʣ�������Ҳ��Ϊ0
//���Ե�ǰ������Ϊ ǰ׺��Ϊk��������������map����¼����

map<int,int> mp;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        mp.clear();//���
        ll sum = 0,ans = 0;//��ʼ��Ϊ0
        cin>>n>>s;
        for(int i = 0;i < s.size();i++) {//��������λ��
            sum += s[i]-'1';//��ǰ��-1
            if(sum==0) ans++;//���Ϊ0�Ļ�����ǰλ����Ҫ���1
            ans += mp[sum]++;//ans��ӵ��� ǰ�������Ϊsum ��ֵ������
            //����Ӻ�����
        }
        cout<<ans<<"\n";
    }
    return 0;
}
