#include<iostream>//ac
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 100003;
int a[MAXN] = {1,1};//���ڵײ��1�׵ķ�����ֻ��һ��
int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 2;i <= n;i++) {
		int ans = 0;//ansΪ����i��ķ�����
		//�������������0���ײ�����ϣ�
		//�������֮��ܴ���k
		for(int j = i-1;j >= 0&&i-j<=k;j--) {
			ans = (ans+a[j])%MOD;//��Ͳ�ȡģ
		}
		a[i] = ans;//������
	}
	cout<<a[n];
	return 0;
}
