#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		if(n==-1) break;
		ll high = 1,low = 0;
		while(n--) {
			//高能 = 3 * 高能 + 2 * 低能
			//低能 = 高能 + 低能
			//用临时变量计算高、低能质点数,然后实时更新即可
			ll tmp_high = 3*high + 2*low;
			ll tmp_low = high + low;
			high = tmp_high;
			low = tmp_low;
		}
		cout<<high<<", "<<low<<endl;
	}
	return 0;
}
