#include<iostream>//ac
using namespace std;
bool judge(int n) {
	while(n) {
		int tmp = n%10;
		if(tmp==2||tmp==0||tmp==1||tmp==9) return 1;
		n /= 10;
	}
	return 0;
}
int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		if(judge(i)) ans += i;
	}
	cout<<ans<<endl;
	return 0;
}
