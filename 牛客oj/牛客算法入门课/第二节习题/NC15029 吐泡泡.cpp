#include<iostream>//ac
#include<string>
#include<stack>
using namespace std;
int main() {
	string s;
	while(getline(cin,s)) {//��������
		string ans = "";//��ʼ��Ϊ�ո�
		stack<char> sta;
		for(int i = 0;i < s.size();i++) {
			if(sta.empty()) sta.push(s[i]);//ջΪ��
			else {
				if(sta.top()==s[i]) {//�������
					sta.pop();
					if(s[i]=='o') {//С�����ٴ��ж�ջ��
						//ջ�з��ţ���Ϊ 'O' ʱ����ջ��
						//�������� 'O'
						if(sta.size()&&sta.top()=='O') sta.pop();
						else sta.push('O');
					}//���ֱ����ʧ��
				}
				else sta.push(s[i]);
			}
		}
		while(!sta.empty()) {
			//�ȳ��������ұ�
			ans = sta.top() + ans;
			sta.pop();
		}
		cout<<ans<<'\n';//�س���������
	}
	return 0;
}
