#include<iostream>//ac
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN],dif[MAXN];
int main() {
	int L,M,l,r,ans = 0;
	cin>>L>>M;
	//��ʼ��  1Ϊ����
	for(int i = 0;i <= L;i++) a[i] = 1;
	for(int i = 1;i <= M;i++) {
		cin>>l>>r;
		//l-r  �����ڵ�������--
		dif[l]--,dif[r+1]++;
	}
	a[0] += dif[0];//�����£�����
	for(int i = 1;i <= L;i++) {
		a[i] = a[i-1]+dif[i];//���µ�ǰλ�õ�������
		if(a[i]>=1) ans++;//������ans++
	}
	cout<<ans+a[0];//�����0λ�õ�������
	return 0;
}
