#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e4 + 5;
int a[MAXN];
int main() {
	int w,n;
	cin>>w>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);//��С��������
	int l = 1,r = n,ans = 0;
	while(l<=r) {//lΪ��ָ�룬rΪ��ָ��
		ans++;//ÿ�ζ�����һ������
		if(l==r) break;//ÿ�����жϴ���ж�С
		int tmp = a[r--];//�ȴ�,�����ƶ���ָ��
		if(tmp+a[l]<=w) l++;//�ж�ʣ��ռ��Ƿ񹻷������Ʒ
	}
	cout<<ans;
	return 0;
}
