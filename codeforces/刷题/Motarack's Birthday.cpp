#include<iostream>//ac
#include<algorithm>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;


//��⣺Ҫ�����ھ��Բ��С
//��ô��Ҫ���붪ʧλ�����ڵ����ֵ����Сֵ
//Ȼ�����λ��Ϊ ���ֵ+��Сֵ ��һ��
//�������������飬�жϾ��Բ��

const int MAXN = 2e5 + 5;
int a[MAXN];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		int minn = INF,maxx = -INF,ans = 0;
		cin>>n;
		for(int i = 1;i <= n;i++) cin>>a[i];
		for(int i = 1;i <= n;i++) {
			if(a[i]==-1) continue;//������ʧλ��
			if(i>1&&a[i-1]==-1||i<n&&a[i+1]==-1) {
				//ǰ���Ϊ��ʧλ��
				minn = min(minn,a[i]);//ȡ��Сֵ
				maxx = max(maxx,a[i]);//ȡ�ϴ�ֵ
			}
		}
		for(int i = 1;i <= n;i++) {//���ʧλ����
			if(a[i]==-1) a[i] = (maxx+minn)/2;
		}
		//ȡ���ھ��Բ�ϴ��ֵ
		for(int i = 1;i < n;i++) ans = max(ans,abs(a[i]-a[i+1]));
		cout<<ans<<' '<<(maxx+minn)/2<<endl;
	}
	return 0;
}
