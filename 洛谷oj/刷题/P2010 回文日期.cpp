#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
bool judge(int n) {
	int year = n/10000;
	int month = n/100%100;
	int day = n%100;
	int num[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%4==0&&year%100||year%400==0) num[2]++;//����
	if(num[month]<day) return 0;//���ڲ�����
	int tmp = 0,ori = n;//tmpΪ����
	while(n) {
		tmp = tmp*10 + n%10;
		n /= 10;
	}
	return tmp == ori;//�ж��Ƿ���ͬ
}
int main() {
	int a,b,ans = 0;
	cin>>a>>b;
	for(int i = a;i <= b;i++) {
		if(i%100>31) continue;//��������������
		if(i/100%100>12) continue;//�����������·�
		if(judge(i)) ans++;//�ж������Ƿ��������Ƿ�Ϊ���Ĵ�
	}
	cout<<ans;
	return 0;
}
