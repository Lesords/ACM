#include<iostream>//ac python
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN]= {0,1,1};
int main() {
	int n;
	for(int i = 3;i < MAXN;i++) a[i] = a[i-1]+a[i-2];
	for(int i = 2;i < 10;i++) cout<<a[i]<<' ';
	cout<<endl;
	for(int i = 2;i < 10;i++) {//�ҹ���
		cout<<a[i+1]*a[i-1] - a[i]*a[i]<<endl;
	}
	//ż�����1   �������-1
	//������һ���ַ�����ֱ���ж����һλ�Ƿ�Ϊż��Ҳ��
	return 0;
} 
