#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int a[5],book[5];
int main() {
	int ans = INF;
	for(int i = 1;i <= 4;i++) cin>>a[i];
	for(int i = 1;i < 4;i++) {
		for(int j = i+1;j <= 4;j++) {
			int tmp = 0;
			for(int k = 1;k <= 4;k++) {
				if(k!=i&&k!=j) tmp += a[k];
			}
			ans = min(ans,abs(tmp-a[i]-a[j]));
		}
	}
	cout<<ans;
	//Ð´·¨¶þ£º
    int a[5];
	for(int i = 1;i <= 4;i++) cin>>a[i];
    sort(a+1,a+5);
	cout<<abs(a[4]+a[1]-a[2]-a[3]);
    return 0;
}
