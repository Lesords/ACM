#include<iostream>
using namespace std;
int a[60];
int main() {
	int n;
	for(int i=1;i<=4;i++) a[i] = i;//ǰ���� 
	for(int i=5;i<60;i++) a[i] = a[i-1] + a[i-3];
	//���� = ȥ�� + ������ţ��������ǰ����������� 
	while(cin>>n) {
		if(n==0) break;
		cout<<a[n]<<endl;
	}
	return 0;
} 
