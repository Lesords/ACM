#include<iostream>//ac
//��������������ͣ���ô���Էֽ��n��2��3�ĺ�
//ż����Ϊn��2�ĺ�
//�����Ļ�Ϊ(����-1)/2��2��һ��3�ĺ�
using namespace std;
int main() {
	int n;
	cin>>n;
	if(n%2==0) {
		cout<<n/2<<endl;
		for(int i = 1;i <= n/2;i++) {
			if(i!=1) cout<<' ';
			cout<<'2';
		}
		cout<<endl;
	}
	else {
		cout<<(n-1)/2<<endl;
		for(int i = 1;i < (n-1)/2;i++) {
			if(i!=1) cout<<' ';
			cout<<'2';
		}
		cout<<' '<<'3'<<endl;
	}
	return 0;
}
