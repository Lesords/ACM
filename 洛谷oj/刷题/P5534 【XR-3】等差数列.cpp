#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	ll a,b,n,d;//���ݱ�int�ˣ�����
	cin>>a>>b>>n;
	d = b-a;//�󹫲�
	cout<<(n*a+(n*(n-1)*d/2));//��͹�ʽ
	return 0;
}
