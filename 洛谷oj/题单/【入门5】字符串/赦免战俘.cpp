#include<iostream>//ac
#include<cmath>
using namespace std;

//��⣺����ģ�⽨����Ϊ���¼�������
//1 2
//3 4
//1Ϊ��ʼ����4Ϊȫ�㣨��������ֻ��Ҫ��ֵ2��3������

//�����ҹ��ɣ����� ��ǰֵΪ �Ϸ������Ϸ� �����ֵ
//�������������

int a[1050][1050] = {{},{0,1,1},{0,1,0}};//��ʼ��
void solve() {
	for(int i = 2;i <= 10;i++) {
		int r = pow(2,i);//�ܳ�
		int l = r/2 + 1;//2����ά������ʼ��
		for(int j = 1;j < l;j++) {//��2��Ϊ��
			for(int k = l;k <= r;k++) {
				a[j][k] = a[j+l-1][k-l+1] = a[j][k-l+1];
			}//3�������2��
		}
	}
}
int main() {
	int n,maxx;
	solve();
	cin>>n;
	maxx = pow(2,n);
	for(int i = maxx;i >= 1;i--) {//�������
		for(int j = maxx;j >= 1;j--) {//�������
			if(j!=maxx) cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
