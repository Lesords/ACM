#include<iostream>//ac
using namespace std;

//��⣺���� 1-n�����Ӹ����� �и�������Ϊ���ӵ�����һ��
//��ÿ��ֻ��Ҫͳ�Ƹ������ӳ��ֵĴ�������
//����i������f(i) = n / i  (nΪĿ����)  ������
 
int main() {
	int n,ans = 0;
	cin>>n;
	//1-n�и��������ֵĴ���
	for(int i = 1;i <= n;i++) ans += n/i;
	cout<<ans<<endl;
	return 0;
}
