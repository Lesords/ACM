#include<iostream>//ac
#include<string>
using namespace std;
int main() {
    string s;
    int k;
    cin>>s>>k;
    if(k>=s.size()) {//���ɾ����������ԭ����λ��
        cout<<""<<endl;
        return 0;
    }
    while(k--) {//��ɾ��k��
        for(int i = 0;i < s.size();i++) {//ÿ�ζ���ǰ��ʼ�ң���ֻ��һ��
            if(s[i]>s[i+1]) {//�ҵ�һ��ֵ�ߵĵ�
                s.erase(i,1);break;//ɾ��������
            }
        }
    }
    while(s.size()>1&&s[0]=='0') s.erase(0,1);//ȥ��ǰ����
    cout<<s<<endl;
    return 0;
}
