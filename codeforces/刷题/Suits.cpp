#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int a,b,c,d,e,f,ans = 0,minn;
	cin>>a>>b>>c>>d>>e>>f;
	if(f>e) {//������һ�ף����ж�ʣ��d�Ƿ�����������һ��
		minn = min(b,min(c,d));
		ans += minn * f;
		d -= minn;
		ans += min(a,d) * e;
	}
	else {
		minn = min(a,d);
		ans += minn * e;
		d -= minn;
		ans += min(b,min(c,d)) * f; 
	}
	cout<<ans<<endl; 
	return 0;
}
