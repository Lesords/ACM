#include<iostream>//ac
#include<algorithm>
//�ȴ�С��������
//Ȼ�����ֵA = a[4] - a[1] ((a+b+c) - (a+b))
//���ڵڶ���������һ������A���������ڶ���B = a[3] - A
//���һ��ֵC��Ϊ�ܺͼ�ȥA��B����Ϊ C = a[4] - A - B 
using namespace std;
int a[5];
int main() {
	for(int i = 1;i <= 4;i++) cin>>a[i];
	sort(a+1,a+5);
	int A = a[4] - a[1];
	int B = a[3] - A;
	int C = a[4] - A - B;
	cout<<A<<' '<<B<<' '<<C<<endl; 
	return 0;
}
