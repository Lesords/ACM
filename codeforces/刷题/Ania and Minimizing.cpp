#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[200005];
int main() {
	int n,k;
	cin>>n>>k>>a;
	for(int i=0;i<n&&k;i++) {
		if(i==0&&a[i]=='1'&&n!=1) continue;//��λΪһ����λ����Ϊһ
		if(a[i]=='0') continue;//����λΪ0 
		if(!i) {//��һλ
			if(n!=1)a[i]='1';//��ֹ��һλ��
			else a[i]='0';
			k--;//��������
		}
		else {//����λ
			a[i]='0';
			k--;//��������
		}
	}
	cout<<a<<endl;
	return 0;
}
