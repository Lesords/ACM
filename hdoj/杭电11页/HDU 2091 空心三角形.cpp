#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	char a;
	int n,flag = 0;
	while(cin>>a) {
		if(a=='@') break;
		cin>>n;
		if(flag++) cout<<endl;//��һ�������
		if(n==1) {
			cout<<a<<endl;
			continue;
		}
		int wid = 2*n - 1;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n+i-1;j++) {
				if(i==1&&j==n) cout<<a;//��һ��
				else if(i==n) cout<<a;//���һ��
				else if(j==(n-i+1)||j==(n+i-1)) cout<<a;
				else cout<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
