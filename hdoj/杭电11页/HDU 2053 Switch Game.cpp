#include<iostream>//ac
#include<cstring>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int main() {
	int n;
	while(cin>>n) {
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i++) {
			for(int j = i;j <= n;j += i)//i±¶+
				a[j] = !a[j];//¿ª»ò¹Ø
		}
		cout<<a[n]<<endl;
	}
	return 0;
} 
