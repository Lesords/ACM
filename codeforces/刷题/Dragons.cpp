#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int x,y;
	friend bool operator < (node a, node b) {
		return a.x<b.x;
	}
}a[1005];
int main() {
	int s,n,flag=0;
	cin>>s>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		if(s>a[i].x) {
			s+=a[i].y; 
		}
		else {
			flag=1;
			break;
		}
	}
	flag?cout<<"NO"<<endl:cout<<"YES"<<endl;
	return 0;
}
