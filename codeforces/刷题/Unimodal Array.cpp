#include<iostream>
using namespace std;
int a[105];
int main(){
	int T,max=0,max_i,flag=0;
	cin>>T;
	for(int i=1;i<=T;i++) {
		cin>>a[i];
		if(a[i]>=max) {//max value
			max_i=i;
			max=a[i];
		}
	}
	for(int i=2;i<=max_i;i++) {//part 1 increase
		if(a[i]<a[i-1]||a[i]==a[i-1]&&a[i]!=max) {
			flag=1;
			break;
		}//don't be constant
	}
	for(int i=max_i+1;i<=T;i++) {//part 2 decrease
		if(flag) break;
		if(a[i]>a[i-1]||a[i]==a[i-1]&&a[i]!=max) {
			flag=1;
			break;
		}
	}
	flag?cout<<"NO"<<endl:cout<<"YES"<<endl;
	return 0;
}
