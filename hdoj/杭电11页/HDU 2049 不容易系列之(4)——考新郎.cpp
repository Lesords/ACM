#include<iostream>//ac
#define ll long long
using namespace std;

//��⣺��M�Է���ѡ��N�ӣ�Ȼ����N�Ӵ��ţ�����ʹ��N�����Ҵ�
//�� C(M,N) * ����[n]

ll down[25],a[25];//downΪn�Ľ׳ˣ�aΪ����n������ֵ
ll f(int a,int b) {//A(a,b)��a��ʼ���ҳ�b��
	ll ans = 1;
	for(int i=a,j=1;j<=b;j++,i--) ans *= i;
	return ans;
}
int main() {
	int T,m,n;
	down[1] = 1;//��һ��Ϊ1
	for(int i = 2;i<25;i++) down[i] = down[i-1] * i;//����׳�
	a[1] = 0;//ֻ��һ�����޷�����������
	a[2] = 1;//���������Ի��ཻ������һ��
	for(int i = 3;i<25;i++) a[i] = (i-1) * (a[i-1]+a[i-2]);
	cin>>T;
	while(T--) {
		cin>>m>>n;//��m�Է򸾣�n��ѡ����
		cout<<f(m,n)/down[n]*a[n]<<endl;
		//����� * ������
	}
	return 0;
}
