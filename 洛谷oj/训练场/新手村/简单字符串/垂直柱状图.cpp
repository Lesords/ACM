#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int book[30];
char row[500];//�ַ����ֻ��400��������������400��
int main() {
	string a;
	int maxx = 0;
	for(int i = 1;i <= 4;i++) {//������ֻ������
		getline(cin,a);
		for(int i = 0;i < a.size();i++) {
			if(a[i]>='A'&&a[i]<='Z')//��¼�ַ������³��ִ������ֵ
				book[a[i]-'A']++,maxx = max(maxx,book[a[i]-'A']);
		}
	}
	for(int i = 1;i <= maxx;i++) {//�ܹ�maxx��
		for(char c = 'Z';c >= 'A';c--) {
			if(book[c-'A']>=i) {//�ж�ÿ��ĩβ
				row[i] = c;break;
			}
		}
	}
	for(int i = maxx;i >= 1;i--) {
		for(char c = 'A'; c <= 'Z';c++) {
			if(book[c-'A']>=i) cout<<"* ";//��ǰ�ַ�����i�μ�����ʱ
			else cout<<"  ";
			if(row[i]==c) {//������ĩ
				cout<<endl;break;
			}
		}
	}
	for(char i = 'A';i <= 'Z';i++) cout<<i<<' ';
	return 0;
}
