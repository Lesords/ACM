#include<iostream>//ac
#include<algorithm>
#define INF 2147483648
using namespace std;
int main() {
	int n;
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	int maxx = -INF, minn = INF - 1,tmp;//正数会溢出，需减 1
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		minn = min(minn, tmp);
		maxx = max(maxx, tmp);
	}
	cout<<minn<<' '<<maxx<<endl;
	return 0;
}
