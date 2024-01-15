#include<iostream>//ac
using namespace std;
int main() {
	int n,k,ans = 0;
	cin>>n>>k;
	for(int i=5,j=i;i<=240-k;j+=5,i+=j) {//i为总时间,j为每次时间
		ans++;
		if(ans>=n) break;
	}
	cout<<ans<<endl;
	return 0;
} 
