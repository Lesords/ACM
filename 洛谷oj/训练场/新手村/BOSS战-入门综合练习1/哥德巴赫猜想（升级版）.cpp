#include<iostream>//ac
using namespace std;
const int MAXN = 2e4 + 5;
int a[MAXN] = {1,1},num[3000];//ֻ����ǧ���
int main() {//0��1���⴦��
	int cnt = 0;
	for(int i = 2;i < MAXN;i++) {
		if(a[i]) continue;
		num[cnt++] = i;//����ÿ������
		for(int j = i+i;j < MAXN;j+=i) a[j] = 1;
	}
	int n,flag = 0;
	cin>>n;
	for(int i = 0;i < cnt&&!flag;i++) {//������������
		if(num[i]>n) break;//��������n
		for(int j = 0;j < cnt&&!flag;j++) {//��ֹ����λ���� 0
			if(num[j]+num[i]>=n) break;//��λ���Ͳ��ܴ��� ���� n ������
			if(!a[n-num[i]-num[j]]) {//��������Ϊ����
				cout<<num[i]<<' '<<num[j]<<' '<<n-num[i]-num[j]<<endl;
				flag = 1;
				break;//���Բ���
			}
		}
	}
	return 0;
}
