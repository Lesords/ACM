#include<iostream>//ac
using namespace std;
char code[30];//����תԭ�ģ�����ԭ�ģ�
int book[30];//������е�ԭ���ַ�
int main() {
	string a,b,c;
	cin>>a>>b>>c;//a���ģ�bԭ��
	int num = 0,flag = 1;
	for(int i = 0;i < a.size()&&flag;i++) {
		int tmp = a[i] - 'A';
		if(code[tmp]) {//������תԭ
			if(b[i]!=code[tmp]) {//����ԭ�Ĳ�һ��
				flag = 0;break;//�г�ͻ
			}
		}
		else {//�µ���תԭ 
			if(book[b[i]-'A']) {//ԭ���Ѵ���
				flag = 0;break;//ԭ�Ķ�Ӧ������ģ�����
			}
			num++;//����++
			code[tmp] = b[i];//�����Ӧ��ԭ��
			book[b[i]-'A'] = 1;//��ǵ�ǰԭ��
		}
	}//ֻ��һ��һ�����ܶ�Զ��һ�Զ�
	if(!flag||num<26) cout<<"Failed";//��26���ַ�
	else { 
		for(int i = 0;i < c.size();i++) {
			cout<<code[c[i]-'A'];//���ת�����ԭ��
		}
	}
	return 0;
}
