#include<iostream>//ac
#include<string>
#include<stack>
using namespace std;
int book[105];//��Ƕ�Ӧλ���Ƿ���Ҫ��ȫ��1Ϊ��Ҫ��ȫ
int main() {
	stack<int> sta;//�����ַ�������
	string s;
	cin>>s;
	for(int i = 0;i < s.size();i++) {
		if(s[i]==')'||s[i]==']') {//����������
			if(sta.empty()) {//û�ж�Ӧ��������
				book[i] = 1;continue;//�貹ȫ������
			}
			//ջ�������뵱ǰ���ſ���ƥ��ʱ������ջ������
			if(s[i]==')'&&s[sta.top()]=='(') sta.pop();
			else if(s[i]==']'&&s[sta.top()]=='[') sta.pop();
			else book[i] = 1;//������Ҫ��ȫ
		}
		else sta.push(i);//����������ջ
	}
	while(!sta.empty()) {//����ʣ���������
		book[sta.top()] = 1;//�貹ȫ��������ջ������
		sta.pop();
	}
	for(int i = 0;i < s.size();i++) {
		if(!book[i]) cout<<s[i];//0Ϊ����Ҫ��ȫ
		else if(s[i]=='('||s[i]==')') cout<<"()";
		else cout<<"[]";
	}
	return 0;
}
