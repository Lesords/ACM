#include<iostream>
using namespace std;
int f(int m) {
	int ans = 0;
	if(m>=100) ans += m/100,m %= 100;
	if(m>=50) ans += m/50,m %= 50;
	if(m>=10) ans += m/10,m %= 10;
	if(m>=5) ans += m/5,m %= 5;
	if(m>=2) ans += m/2,m %= 2;
	if(m>=1) ans += m;
	return ans;
}
int main() {
	int n;
	while(cin>>n&&n) {
		int ans = 0,tmp;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			ans += f(tmp);//Öğ¸ö¼ÆËã 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
