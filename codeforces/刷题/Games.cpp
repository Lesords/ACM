#include<iostream>//ac
using namespace std;
struct team{
	int h,g;//h������ɫ��g�ͳ���ɫ
}a[35];
int main() {
	int T,ans = 0;
	cin>>T;
	for(int i=1;i<=T;i++) cin>>a[i].h>>a[i].g;
	for(int i=1;i<=T;i++) {
		for(int j=1;j<=T;j++) {
			if(i==j) continue;//ͬһֻ����
			if(a[i].h==a[j].g) ans++;//������ɫ��ͳ���ɫ��ͬ
		}
	}
	cout<<ans<<endl;
	return 0;
}
