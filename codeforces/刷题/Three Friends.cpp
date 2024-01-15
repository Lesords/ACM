#include<iostream>//ac
#include<algorithm>
using namespace std;
//三个点之间的相互距离，即为（max-min）*2
//所以需要缩短最大值和最小值之间的距离
int a[5];
int main() {
	int t;
	cin>>t;
	while(t--) {
		for(int i = 1;i <= 3;i++) cin>>a[i];
		sort(a+1,a+4);
		if(a[1]!=a[2]) a[1] += 1;//左边比中间小
		else if(a[1]==a[2]&&a[2]<a[3]) a[1] += 1,a[2] += 1;
		if(a[2]!=a[3]) a[3] -= 1;//右边比中间大
		else if(a[2]==a[3]&&a[2]>a[1]) a[3] -= 1,a[2] -= 1;
		cout<<(a[3]-a[1])*2<<endl;
	}
	return 0;
}
