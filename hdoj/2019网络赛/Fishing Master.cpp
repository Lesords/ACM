#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[100005],n,m,ans;
int main() {
	int T,cnt;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		ans=m,cnt=0;//��һ��ץ���ʱ�� 
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			ans+=a[i];//ÿһ�������ʱ�� 
			cnt+=a[i]/m;//ͳ���������ڼ䣬���Բ���Ĵ��� 
			a[i]%=m;//��������ʱ�� 
		}
		if(cnt>=n-1) {//�����ʱ�乻ץn-1����(��Ϊ��һ��ץ��ʱ�������)
			cout<<ans<<endl;
		}
		else {
			sort(a+1,a+1+n);//��С�����������Խ�������i��n��ʼ 
			for(int i=n;cnt<n-1;cnt++,i--) {//cntΪn-1ʱ����������ʱ�乻�ˣ� 
				ans+=m-a[i];//�˷ѵ�ʱ��Ϊm-a[i]
			}
			cout<<ans<<endl;
		} 
	}
	return 0;
} 
