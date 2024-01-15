#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[6];
int main() {
	for(int i=1;i<=4;i++) cin>>a[i];
	sort(a+1,a+5);
	if(a[4]==a[1]+a[2]+a[3]||a[4]+a[1]==a[2]+a[3])
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
} 
