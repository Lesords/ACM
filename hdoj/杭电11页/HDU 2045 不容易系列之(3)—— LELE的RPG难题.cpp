#include<iostream>
#define ll long long
using namespace std;
ll a[55]={0,3,6,6};
int main() {
	for(int i = 4 ;i <= 50;i++) 
		a[i] = a[i-1] + a[i-2] * 2;
	//��n-1����ɫ���1����ɫ����ͬ (a[i-1])
	/*��n-2����ɫ���1����ɫ����ͬ (a[i-2])
	��ô��n-1����ɫ�������1����ͬ
	���Ե�n������������ɫѡ��*/ 
	int n;
	while(cin>>n) cout<<a[n]<<endl;
	return 0;
}
