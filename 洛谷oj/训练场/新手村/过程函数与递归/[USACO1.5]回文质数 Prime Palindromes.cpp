#include<iostream>//ac
using namespace std;//1111111�ɱ�11����Ҳ���ų�
const int MAXN = 1e7 + 5;//ż��һ����Ϊ��������ֻ��Ҫ1e7
int prime[MAXN];
bool is_pand(int x) {
	int tmp = x,y = 0;
	while(tmp) {//������
		y = y*10+tmp%10;
		tmp /= 10;
	}
	return x == y;//�жϴ�С
}
int main() {
	for(int i = 2;i < MAXN;i++) {//��ʽɸ��
		if(prime[i]) continue;
		for(int j = i+i;j < MAXN;j += i) prime[j] = 1;
	}
	int a,b;
	cin>>a>>b;
	for(int i = a;i <= b;i++) {
		if(i>=MAXN-5) break;//Խ��ֱ���˳�
		if(!prime[i]&&is_pand(i)) cout<<i<<endl;
	}
	return 0;
}
