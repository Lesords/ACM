#include<iostream>//ac
#include<string>
using namespace std;

//��⣺���������ַ�����Hashֵ��ͬ����ģΪmod
//��˵������s���ַ�����HashΪ res+mod ʱ�ֵ�����С
//��Ϊ�����ַ���Hashֵ��ֻͬ����� n*mod

string s,ans;
int mod,res;
int main() {
	while(cin>>s>>mod) {
		res = 0;//��ʼ��Ϊ0
		for(int i = 0;i < 6;i++) {//���λ���ҵ�λ
			res = res*26 + s[i]-'a';
		}//����resֵ��Hash��
		res += mod;//����ģ��
		for(int i = 5;i >= 0;i--) {//��������
			ans[i] = res%26 + 'a';
			res /= 26;
		}//�����������ڣ���resΪ0�������޽�
		if(res) cout<<"-1";
		else for(int i = 0;i < 6;i++) cout<<ans[i];
		cout<<endl;
	}
	return 0;
}
