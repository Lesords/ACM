#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺С��5ʱֱ���������
//����5ʱ����Ҫ��5�����Ķ�����������С��
//ʣ���ǮҲ��Ҫ�������
//Ҳ���Ǵ���5ʱ���ֳ��������ּ���

const int MAXN = 1005;
int a[MAXN], dp[MAXN];
//dp[i] ��ʾi�����������ණ��
int main() {
	int t,rest;
	while(cin>>t&&t) {
		for(int i = 1;i <= t;i++) cin>>a[i];
		sort(a+1,a+t+1);//����
		memset(dp,0,sizeof(dp));
		int maxx = a[t];//���Ĳ�
		cin>>rest;
		if(rest<5) {//����С��5������
			cout<<rest<<endl;continue;
		}
		rest -= 5;
		for(int i = 1;i < t;i++) {//����Ҫ��������
			//���������ĸ���״̬
			//ÿ����С��״̬������Ͳ�������ѡ��
			for(int j = rest;j >= a[i];j--) {
				dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
				//Ҫô����Ҫô��ȡ�ϴ�ֵ
			}//��������С ���� ����ֹ��С����ǰ�˼ۣ�
		}
		//ʣ���Ǯ���۳�5�Ĳ��֣�-�������+5-���Ĳ�
		cout<<rest-dp[rest]+5-maxx<<endl;
	}
	return 0;
}
