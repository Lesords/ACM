#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int vis[1005],a[1005];
int main() {
	int n,flag = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		if(i>1) vis[i-1] = abs(a[i]-a[i-1]);//��¼��ֵ
	}
	sort(vis+1,vis+n);//��������ж������յ��ֵ����
	if(vis[1]==1&&vis[n-1]==n-1) flag = 0;//����Ҫ��
	cout<<(flag?"Not jolly":"Jolly")<<endl;
	return 0;
}
