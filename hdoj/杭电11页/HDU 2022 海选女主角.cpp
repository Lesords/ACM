#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n,m;
	while(cin>>m>>n) {
		int ans=0,ans_m,ans_n,tmp;
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				cin>>tmp;
				if(abs(tmp)>abs(ans)) {
					ans = tmp;//分数 
					ans_m = i,ans_n = j;//行和列 
				}
			}
		}
		cout<<ans_m<<' '<<ans_n<<' '<<ans<<endl;
	}
	return 0;
}
