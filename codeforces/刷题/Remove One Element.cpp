#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN],l_r[MAXN],r_l[MAXN];
//��⣺�ȴ�����ɨһ�飬��¼ �� �������п�ĳ��ȣ�������ans
//�ٴ��ҵ���ɨһ�飬��¼ �� �������п�ĳ��ȣ�������ans
//����ж� ��һ���� ���������������Ƿ�Ϊ�������У�������ans
int main() {
	int t,ans = 1;//��ʼֵΪ1����Ϊ���ٻ���һ����
	cin>>t;
	for(int i = 1;i <= t;i++) cin>>a[i];
	l_r[1] = r_l[t] = 1;//��ʼ��
	for(int i = 2;i <= t;i++) {//ȥ����ʼλ (iΪ�յ�)
		if(a[i]>a[i-1])//����ߵ�����
			l_r[i] = l_r[i-1] + 1,ans = max(ans,l_r[i]);
		else l_r[i] = 1;
	}
	for(int i = t-1;i >= 1;i--) {//ȥ����ʼλ (iΪ���)
		if(a[i]<a[i+1])//���ұߵ���С
			r_l[i] = r_l[i+1] + 1,ans = max(ans,r_l[i]);
		else r_l[i] = 1;
	}
	for(int i = 1;i + 2 <= t;i++) {
		if(a[i] < a[i+2]) ans = max(ans,l_r[i]+r_l[i+2]);
	}
	cout<<ans<<endl;
	return 0;
}
