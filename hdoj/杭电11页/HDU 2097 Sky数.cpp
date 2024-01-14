#include<iostream>//ac
using namespace std;
int f(int n,int sys) {//sys为进制大小
	int ans = 0;
	while(n) {
		ans += n%sys;
		n /= sys;
	}
	return ans;
}
int main() {
	int n;
	while(cin>>n&&n) {
		if(f(n,10)==f(n,12)&&f(n,10)==f(n,16))
			cout<<n<<" is a Sky Number."<<endl;
		else cout<<n<<" is not a Sky Number."<<endl;
	}
	return 0;
} 
