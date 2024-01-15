#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char a[200005];
int main() {
	int n,ans=0,num_a=0,num_b=0;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) {//strlen函数的复杂度过高
		cin>>a[i];
		if(a[i]=='a') num_a++;
		else num_b++;
		if(i%2) {
			if(num_a==num_b) continue;
			else if(num_a>num_b) {
				a[i] = 'b';
				num_a--,num_b++;
			}
			else {
				a[i] = 'a';
				num_a++,num_b--; 
			}
			ans++;
		}
	}
	cout<<ans<<endl<<a<<endl;
	return 0;
} 
