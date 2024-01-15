#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	ll n;
	cin>>n;
	if(n>=0) cout<<n<<endl;
	else {
		int tmp_1 = -n%10;//个位
		int tmp_2 = -n/10%10;//十位
		if(tmp_2>tmp_1) cout<<n/10-tmp_1+tmp_2<<endl;
		else cout<<n/10<<endl;
	}
	return 0;
}
