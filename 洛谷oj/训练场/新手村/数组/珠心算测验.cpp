#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e4 + 5;
int vis[MAXN],a[105];
int main() {
	int n,ans = 0,maxx = 0,minn = INF;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		vis[a[i]] = 1;
		maxx = max(maxx,a[i]);//��С��
		minn = min(minn,a[i]);//�����
	}
	for(int i = 1;i <= n;i++) {
		for(int j = minn;j <= maxx;j++) {//��С�������
			if(j>a[i]) break;// j ����� a[i] С
			if(vis[j]&&vis[a[i]-j]&&j<a[i]-j) {//j��a[i]-j ����
				ans++;
				break;//ע�������ظ����㣡����
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
