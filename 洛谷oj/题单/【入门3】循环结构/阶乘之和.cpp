#include<iostream>//ac  �����׳˺ͼӷ�
#include<cstring>
using namespace std;
const int MAXN = 105;
int a[MAXN],sum[MAXN],pos;
void multi(int n) {
	int rest = 0;//������λ
	for(int i = 1;i < MAXN;i++) {
		a[i] = a[i]*n+rest;
		rest = a[i]/10;//��λΪ /10
		a[i] %= 10;//��ǰλ %10
	}
}
void add() {
	for(int i = 1;i < MAXN;i++) {
		sum[i] += a[i];
		sum[i+1] += sum[i]/10; //��һλ��ӽ�λֵ
		sum[i] %= 10;//��ǰλ %10
	}
}
int main() {
	int n;
	cin>>n;
	if(!n) {//����0
		cout<<'1'<<endl;return 0;
	}
	a[1] = 1;//�˷����ʼ��Ϊ1
	for(int i = 1;i <= n;i++) {
		multi(i);//��
		add();//�ۼ�
	}
	for(int i = MAXN-1;i >= 1;i--) if(sum[i]) {//�ҵ���ʼ��
		pos = i;break;
	}//�����������
	for(int i = pos;i >= 1;i--) cout<<sum[i];
	cout<<endl;
	return 0;
}
