#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
char b[3003];//gets������֧��string���� 
int main() {
	string s,a;
	map<string, string> map;
	cin>>a;//START��ʡ�ԣ�
	while(cin>>a&&a!="END") {
		cin>>b;
		map[b]=a;
	}
	cin>>a;//START��ʡ�ԣ�
	getchar();//STARTĩβ�Ļس���
	s="";//��ʼ��
	while(gets(b)&&strcmp(b,"END")) {//��������
		int len=strlen(b);
		for(int i=0;i<len;i++) {
			if(b[i]<'a'||b[i]>'z') {//������
				if(map[s]!="") cout<<map[s];//ת�����ڣ����
				else cout<<s;
				cout<<b[i];//�����ţ���ǰ��
				s="";//���
			}
			else s+=b[i];
		}
		cout<<endl;//pe�� 
		s="";//��ʼ�� 
	}
	return 0;
} 
