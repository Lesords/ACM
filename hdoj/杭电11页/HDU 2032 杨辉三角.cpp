#include<iostream>
#include<cstring>
using namespace std;
int a[35][35];
int main() {
	int n;
	for(int i=1;i<=31;i++) {
		for(int j=1;j<=i;j++) {
			if(j==1||j==i) {//�׺�ĩ 
				a[i][j] = 1;
				continue;
			}
			a[i][j] = a[i-1][j] + a[i-1][j-1];
		}
	}
	while(cin>>n) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=i;j++) {
				if(j!=1) cout<<' ';//����ǰ��ո� 
				cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;//pe�� 
	}
	return 0;
}
