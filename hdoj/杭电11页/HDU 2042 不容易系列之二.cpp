#include<iostream>//ac
using namespace std;
int main() {
	int N,tmp;
	cin>>N;
	while(N--) {
		cin>>tmp;
		int ans = 3;
		for(int i=1;i<=tmp;i++) {
			ans = (ans-1) *2;//ÉÙ1³Ë2
		}
		cout<<ans<<endl; 
	}
	return 0;
}
