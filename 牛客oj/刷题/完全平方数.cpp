#include<iostream>//ac
#include<cmath>
#define ll long long
#define s(a) sqrt(a)
using namespace std;

//��⣺�ж�a��b����ȫƽ��������
//����ֱ���ж�a��b��sqrt(a)��sqrt(b)�Ĳ�
//�൱��sqrt(a)ӳ�䵽a��sqrt(b)ӳ�䵽b

int main() {
	ll n,a,b;
	cin>>n;
	while(n--) {
		cin>>a>>b;
		//�������ȡ����С������ȡ��
		//��Χ������+1
		cout<<floor(s(b))-ceil(s(a))+1<<endl;
	}
	return 0;
}
