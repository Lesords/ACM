#include<iostream>//ac
#include<cstring>
#include<cstdio>
using namespace std;
int cycle,a,b,start;
int num[3005],book[3005];//��������Լ�λ��������3000
void solve() {
	int cnt = 1;
	while(!book[a]&&a) {//aΪ0(�ɳ���)������a�Ѵ���(ѭ����)
		book[a] = cnt;//��¼λ����aΪ������
		num[cnt++] = a*10/b;//num���鱣����
		a = a*10%b;//��������
	}
	if(!a) {//�ɳ���
		for(int i = 1;i < cnt;i++) cout<<num[i];
		cout<<"(0)"<<endl<<"   1";
	}
	else {//ѭ��С��
		for(int i = 1;i < book[a];i++) cout<<num[i];//��ѭ��
		cout<<'(';
		for(int i = book[a];i < cnt;i++) {
			if(i>50) {
				cout<<"...";//����50
				break;
			}
			cout<<num[i];
		}
		cout<<')'<<endl<<"   "<<cnt - book[a];
		//ѭ������ = ���ڽ�ֹ���� - ��ѭ�����ȣ�����
	}
}
int main() {
	while(cin>>a>>b) {
		memset(book,0,sizeof(book));
		cout<<a<<'/'<<b<<" = "<<a/b<<'.';//�������������
		a %= b;//����(ȥ������������ֵ)
		solve();
		cout<<" = number of digits in repeating cycle"<<endl<<endl;
	}
	return 0;
}
