#include<iostream>//ac
using namespace std;
int gcd(int a,int b) {
	if(b==0) return a;
	return a%b==0?b:gcd(b,a%b);
}
int main() {
	int a,b,n,flag = 0;
	cin>>a>>b>>n;
	while(n>0) {
		/*int tmp;
		tmp = gcd(a,n);
		if(n>=tmp) n -= tmp;
		else {
			flag = 1;//AntisimonӮ��
			break;
		}
		tmp = gcd(b,n);
		if(n>=tmp) n -= tmp;
		else {
			flag = 0;//SimonӮ�� 
			break;
		}*/ 
		if(!flag) n -= gcd(a,n);//���1
		else n -= gcd(b,n);//���2
		flag ^= 1;//�������
	}
	cout<<!flag<<endl;//Ӯ������һ�����
	return 0;
}
