#include<iostream>//ac
#define ll long long
using namespace std;

//题解：由于土豆的值为 3^0 3^1 3^2 ··· 3^(n-1)
//那么也就是说组成的土豆的质量值可以相当于为3进制的值
//那么第k小的值即为 k 对应的二进制数组成的 三进制值

int main() {
	int t,k;
	cin>>t;
	for(int i = 1;i <= t;i++){
		cin>>k;
		ll ans = 0,tmp = 1;//初始化
		while(k) {
			if(k&1) ans += tmp;//当前二进制位为1
			tmp *= 3;//更新对应进制位的值
			k >>= 1;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
	return 0;
}
