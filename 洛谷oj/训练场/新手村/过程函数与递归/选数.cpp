#include<iostream>//ac
using namespace std;
int a[25],n,k,ans;
void dfs(int pos, int sum, int start) {//����start������ʼ��
	if(pos==k) {
		for(int i = 2;i*i <= sum;i++) {
			if(sum%i==0) return;
		}
		ans++;
		return;
	}//Ҳ����ÿ�β�ѡȡ֮ǰ������
	for(int i = start;i <= n;i++) {//����ѡȡ�������ظ�
		dfs(pos+1,sum+a[i],i+1);
	}//ѡȡk�������ظ���Ҳ���ǵ�ǰ��ȡҲ������
}
int main() {
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i];
	dfs(0,0,1);
	cout<<ans<<endl;
	return 0;
}
