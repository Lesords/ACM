#include<iostream>//ac  ǰ׺��
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int sum[3005],tmp;
int main() {
	int n,m,ans = INF;//��ʼ��ΪINF
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>tmp,sum[i] = sum[i-1]+tmp;
	for(int i = m;i <= n;i++) {//�ӵ�mΪ��ʼ����
		ans = min(ans,sum[i]-sum[i-m]);
	}//����m�����ĺͿ��Կ��������䳤��Ϊm�ĺ�
	//��ô������ǰ׺�����������е�m������ͣ�ȡ��Сֵ
	cout<<ans;
	return 0;
}
