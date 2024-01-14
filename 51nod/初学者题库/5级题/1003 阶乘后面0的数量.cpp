#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int n, sum = 0;
	cin>>n;
	while(n) {//有5必有0，只需要记录5的次数
		sum += n/5;// 5 25 125等
		n /= 5;
	}
	cout<<sum<<endl;
	return 0;
}
