#include<iostream>//ac
using namespace std;
int solve(int n) {
	if(n==0) return 0;//����0��1
	if(n==1) return 2;
	// n-1 �����Ƶ��յ� + �����Ƶ��м�
	// + n-1 �����Ƶ���� + �����Ƶ��յ�
	// + n-1 �����Ƶ��յ�
	return 3*solve(n-1)+2;
}
int main() {
	int n,ans;
	while(cin>>n) {//��������
		cout<<solve(n)<<'\n';
	}
	return 0;
}
