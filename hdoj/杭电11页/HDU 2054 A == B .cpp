#include<iostream>//ac
#include<string> 
using namespace std;
int f_head(string a) {//�жϷ���
	if(a[0]!='-') return 1;//1�� 0��
	return 0;
}
bool have_dot(string a) {//�Ƿ���С����
	for(int i = 0;i < a.length();i++)
		if(a[i]=='.') return true;
	return false;
}
void del_last(string &a) {//ɾ��С����ĩβ������
	for(int i = a.length()-1;i>=0;i--) {//�Ӻ�ʼ����
		if(a[i]!='0') {//���Ƕ�����
			a[i]=='.'?a.erase(i):a.erase(i+1);
			//��λ����С������С����һ��ɾ
			break;
		}
	}
}
bool isequal(string a,string b) {
	int a_head,b_head;
	a_head = f_head(a);//�жϷ���
	b_head = f_head(b); 
	if(a[0]=='+'||a[0]=='-') a.erase(0,1);//ȥ������
	if(b[0]=='+'||b[0]=='-') b.erase(0,1);
	//ɾ���������ֵĶ�����
	//��ֻ��һλ������Ҫ����һ����
	//����С�����֣���Ҫ�������С����
	while(a[0]=='0'&&a.length()!=1&&a[1]!='.') a.erase(0,1);
	while(b[0]=='0'&&b.length()!=1&&b[1]!='.') b.erase(0,1);
	if(have_dot(a)) del_last(a);//����С������ɾ������Ķ�����
	if(have_dot(b)) del_last(b);
	if(a==b&&a_head==b_head) return true;
	if(a==b&&a[0]=='0') return true;
	return false;
}
int main() {
	string a,b;
	while(cin>>a>>b) {
		if(isequal(a,b)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
