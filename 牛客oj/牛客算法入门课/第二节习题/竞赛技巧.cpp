#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 5e3+5;
struct node{
	int x,y,z;
	bool operator < (node a) {
		if(x!=a.x) return x < a.x;//Ê±
		if(y!=a.y) return y < a.y;//·Ö
		return z < a.z;//Ãë
	}
}a[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++) {
		cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<"\n";
	}
	return 0;
}
