#include<iostream>//ac
#include<cstring>
using namespace std;
int a[11];
int judge(int n) {
	while(n) {
		if(a[n%10]||n%10==0) return 0;//�����Ѵ��ڻ����0������
		a[n%10] = 1;//��ǳ��ֹ�������
		n /= 10;
	}
	return 1;
}
int main() {
	for(int i = 123;i*3 <= 987;i++) {//�����յ㲻�����ظ�����
		memset(a,0,sizeof(a));//��ʼ���������
		if(judge(i)&&judge(i*2)&&judge(i*3)) {
			cout<<i<<' '<<i*2<<' '<<i*3<<endl;
		}
	}
	return 0;
}
