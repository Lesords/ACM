#include<iostream>//ac
#include<stack>
#include<string>
using namespace std;
int main() {
	stack<int> sta;
	string s;
	cin>>s;
	for(int i = 0;i < s.size()-1;i++) {
		int tmp = 0,op1,op2;//tmpΪ����
		while(s[i]>='0'&&s[i]<='9') {//Ϊ�������͵�ʱ��
			tmp = tmp*10+s[i]-'0';
			i++;
		}
		if(s[i]=='.') sta.push(tmp);//.ʱ��������
		else {//�����������ͷ����������
			op1 = sta.top(),sta.pop();
			op2 = sta.top(),sta.pop();
		}//���ж�Ӧ������ע��op2��op1��˳�򣡣���
		if(s[i]=='-') sta.push(op2-op1);
		else if(s[i]=='+') sta.push(op1+op2);
		else if(s[i]=='*') sta.push(op1*op2);
		else if(s[i]=='/') sta.push(op2/op1);
	}
	cout<<sta.top();
	return 0;
}
