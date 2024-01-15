#include<iostream>//ac
using namespace std;
int a[2005] = {6,2,5,5,4,5,6,3,7,6};//和可能大于1000
int pos[11] = {6,2,5,5,4,5,6,3,7,6};
int main() {
	for(int i = 10;i <= 2000;i++) {//预处理
		int tmp = i;
		while(tmp) {//逐位遍历
			a[i] += pos[tmp%10];
			tmp /= 10;
		}
	}
	int n, ans = 0;
	cin>>n;
	for(int i = 0;i <= 1000;i++) {
		for(int j = 0;j <= 1000;j++) {//+和=为4个
			if(a[i]+a[j]+a[i+j]+4==n) ans++;
		}//数量符合时
	}
	cout<<ans<<endl;
	return 0;
}
