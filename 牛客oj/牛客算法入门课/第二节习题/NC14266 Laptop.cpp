#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
	int x,y;//�ڴ���ٶ�
	friend bool operator < (node a,node b) {
		if(a.x!=b.x) return a.x < b.x;//�Ȱ��ڴ�����
		return a.y < b.y;//���ٶ�����
	}
}a[MAXN];
int suf[MAXN];//��׺ ����ٶ�
int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1);
	suf[n] = a[n].y;//���һ���ٶ����ʼ��
	for(int i = n-1;i >= 1;i--) {
		suf[i] = max(suf[i+1],a[i].y);//���º�׺����ٶ�
	}
	for(int i = 1;i < n;i++) {
		//ֻ��Ҫ�ж� i+1 �ĺ�׺����ٶ��Ƿ���ڵ��ڵ�ǰֵ����
		//ӦΪ�ڴ��Ѿ��ź�����
		if(suf[i+1]>=a[i].y) ans++;
	}
	cout<<ans;
	return 0;
}
