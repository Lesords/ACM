#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string a,b;
	int sum = 0,begin = -1;
	cin>>a;
	getchar();//���յ�һ��ĩβ�ַ���
	transform(a.begin(),a.end(),a.begin(),::tolower);//ת����Сд
	getline(cin,b);//getline������ �س��� Ϊ����������
	string tmp = "";
	int start = 0;//��ʼ��������ʼλ��
	for(int i = 0;i < b.size();i++) {
		if(b[i] == ' '||i == b.size()-1) {
			if(i == b.size()-1) tmp += b[i];
			transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
			if(tmp==a) {
				if(begin==-1) begin = start;//��û�����ʼλ��
				sum++;
			}
			tmp = "";
			start = i + 1;//���³�ʼλ��
		}
		else tmp += b[i];
	}
	if(sum) {
		cout<<sum<<' '<<begin<<endl;
	}
	else cout<<"-1"<<endl;
	return 0;
}
