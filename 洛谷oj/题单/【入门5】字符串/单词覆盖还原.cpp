#include<iostream>//ac
#include<string>
using namespace std;

//��⣺��Ȼ�ַ��ᱻ����,��ô������һ��boy��girlֻ����һ��
//��ôҲ��ֻ��Ҫ�жϸ���λ���Ƿ������Ӧ���ַ�����

int main() {
	string s;
	int boy = 0,girl = 0;
	cin>>s;
	for(int i = 0;i < s.size();i++) {
		//����λ��������һ������һ��boy
		if(s[i]=='b'||s[i+1]=='o'||s[i+2]=='y') boy++;
		//�ĸ�λ��������һ������һ��girl
		if(s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l') girl++;
	}
	cout<<boy<<endl<<girl<<endl;
	return 0;
}
