#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e5+10;
int a[MAXN],n;
int main() {
	ll ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	ans = a[1];
	//��ǰ�����̣������������С��ǰ�棬��ǰ���̵�ʱ����԰Ѻ����һ������
	//����������ݴ���ǰ���ʱ����Ҫ���̲�ֵ(����-ǰ��)�Ĵ�С
	
	//��Ϊ���е�·����Ҫ�̣��̸ߵ�ʱ����԰ѵ͵�һ�����ˣ�
	//�������ǰ���ǵ͵Ļ�������ߵĲ��ֵ�����һ��
	for(int i = 2;i <= n;i++) {
		if(a[i]<=a[i-1]) continue;
		else ans += a[i]-a[i-1];//�������ǰ�棬�̲�ֵ
	}
	cout<<ans;
	return 0;
}
