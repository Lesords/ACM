#include<iostream>//ac
#include<algorithm>
using namespace std;
//n = x + 2y
//m = 2x + y
//=> n + m = 3(x+y)
//��n��m����Ҫ��3����
//min(n,m) >= (n + m) / 3
//��minn * 2 >= maxx
//��������������������������
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		int maxx = max(n,m);
		int minn = min(n,m);
		int mod = (maxx+minn)%3;
		if(!mod&&minn*2>=maxx) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
