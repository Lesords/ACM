#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;
int dp[MAXN],a[MAXN];
//dp[i] ��ʾΪi��������װ�������
int main() {
	int R,n;
	cin>>R>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= n;i++) {
		for(int j = R;j >= a[i];j--) {
			//Ŀ������ - ��ֹ����
			dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
		}//Ҫôװ��Ҫô��װ��ȡ��ֵ
	}
	cout<<R-dp[R]<<endl;
	//��ʣ�����٣���Ϊ ����R-װ���������
	return 0;
}
