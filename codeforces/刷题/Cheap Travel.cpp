#include<iostream>//ac
using namespace std;
int main() {
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(b*1.0/m*1.0>=a) {//���Ʊ������
		cout<<n*a<<endl;
	}
	else {
		if(n%m) {
			if(n%m*a>b) cout<<n/m*b+b<<endl;//��Ʊ�ȵ�Ʊ����
			else cout<<n/m*b+n%m*a<<endl;
		}
		else cout<<n/m*b<<endl;//���Ʊ�պ�
	}
	return 0;
} 
