#include<iostream>//ac
using namespace std;
const int MAXN = 40005;
int a[MAXN];
int main() {
	int n,tmp,cnt = 1,op = 0;
	cin>>n;
	while(cin>>tmp) {//��֪�����ж�������
		while(tmp) {//tmp��op��
			a[cnt++] = op,tmp--;//��cnt��ʼ��ֵ
		}
		op ^= 1;//ȡ��
	}
	for(int i = 1;i <= n*n;i++) {
		cout<<a[i];
		if(i%n==0) cout<<endl;//ֻ��Ҫ�ڱ���λ������س�
	}
	return 0;
}
