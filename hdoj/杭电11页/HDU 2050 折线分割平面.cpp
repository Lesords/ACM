#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e4 + 5;
ll a[MAXN]={1};
int main() {
	int t,tmp;
	for(int i = 1;i < MAXN;i++)
		a[i] = a[i-1] + 4*(i-1)+1;
	//����yһ����һ���̶���1���������ҹ��������2
	//���ߴ���������������Ϊ2(n-1)��
	//����ÿ�ζ�����������СΪ��4*(n-1)+1
	cin>>t;
	while(t--) {
		cin>>tmp;
		cout<<a[tmp]<<endl;
	}
	return 0;
}
