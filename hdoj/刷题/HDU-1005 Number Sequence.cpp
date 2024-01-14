#include<iostream>//ac
using namespace std;
struct Matrix{//���׾���
	int f[2][2];
};
Matrix mul(Matrix a,Matrix b) {//����˷�
	Matrix ans;
	for(int i = 0;i < 2;i++) {//���к���
		for(int j = 0;j < 2;j++) {//�����ĸ�λ��
			ans.f[i][j] = 0;//��ʼ��Ϊ0
			for(int k = 0;k < 2;k++) {//�����Ӧλ�õĽ��
				ans.f[i][j] += (a.f[i][k]*b.f[k][j])%7;
			}//��i * ��j
			ans.f[i][j] %= 7;//ȡ��
		}
	}
	return ans;//���ؽ��
}
int main() {
	int A,B,n;
	while(cin>>A>>B>>n&&A+B+n) {
		if(n<=2) {//С��2
			cout<<'1'<<endl;
			continue;
		}
		Matrix a,ans;
		a.f[0][0] = A, a.f[0][1] = B;
		a.f[1][0] = 1, a.f[1][1] = 0;//���ɾ���
		ans.f[0][0] = ans.f[0][1] = 1;//0�ж�Ӧ���ǽ��
		ans.f[0][1] = ans.f[1][1] = 0;
		n -= 2;//�ӵ���λ��ʼ����Ҫ��
		while(n) {//���������
			if(n&1) ans = mul(ans,a);//���˷���Ϊ����˷�
			n>>=1;
			a = mul(a,a);//ͬ��
		}
		cout<<(ans.f[0][0]+ans.f[0][1])%7<<endl;
		//f[0][0]+f[0][1] ��Ӧ���ǽ�� f(n)
	}
	return 0;
}
