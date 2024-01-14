#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
	int n,tmp,cnt = 0;
	cin>>n;
	while(cin>>tmp) {
		a[++cnt] = tmp;
	}
	sort(a+1,a+1+cnt);//排序之后找缺的和重复的
	int miss,two;
	for(int i = 2;i <= cnt;i++) {
		if(a[i-1]+1==a[i]) continue;
		if(a[i]==a[i-1]) two = a[i];
		else miss = a[i]-1;
	}
	cout<<miss<<" "<<two;
	return 0;
}
