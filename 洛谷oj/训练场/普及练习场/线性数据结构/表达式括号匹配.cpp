#include<iostream>//ac
#include<stack>//ջ
#include<string>
using namespace std;
int main() {
	string a;
	stack<char> s;
	cin>>a;
	for(int i = 0;i < a.size();i++) {
		if(a[i] == '@') break;//��������
		if(a[i] == '(') s.push(a[i]);//����������
		else if(a[i] == ')') {
			if(s.size()==0) {//��ջ��û��������
				s.push(a[i]);break;
			}
			else s.pop();//����ջ����������
		}
	}//ջ��Ϊ�գ���˵������ȫ��ƥ��ɹ�
	cout<<(s.size()?"NO":"YES")<<endl;
	return 0;
} 
