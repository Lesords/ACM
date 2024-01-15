#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	int n;
	cin>>n;//n = 364x+1092k
	for(int i = 100;i >= 0;i--) {//xÓÐ·¶Î§
		if((n-i*364)%1092==0&&(n-i*364)>0) {
			cout<<i<<endl<<((n-i*364)/1092);
			break;
		}
	}
	return 0;
}
