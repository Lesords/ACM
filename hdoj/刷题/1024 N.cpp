#include<cstdio>//ac
using namespace std;
const int MAXN = 36000;
int a[MAXN],pos;
void mult(int n) {
	int carry = 0;//��λ
	for(int i = 1;i <= pos;i++) {//��֪��λ��
		a[i] = a[i]*n+carry;
		carry = a[i]/10;
		if(i==pos&&carry) pos++;//�����λ
		a[i] %= 10;
	}
	while(a[pos]>=10) {//λ������
		a[pos+1] = a[pos]/10;
		a[pos] %= 10;
		++pos;//��λ
	}
}
int main() {
	int n;//scanf��cinû�memsetҲû��
	while(scanf("%d",&n)!=EOF) {
		pos = a[1] = 1;//��ʼ��Ϊ1��λ��ֻ��1
		for(int i = 2;i <= n;i++)//�׳�
			mult(i);
		for(int i = pos;i >= 1;i--) printf("%d",a[i]),a[i]=0;
		printf("\n");
	}
	return 0;
}
