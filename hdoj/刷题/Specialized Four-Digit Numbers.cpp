#include<iostream>//ac
using namespace std;
int f(int i,int pos) {//pos为进制数
	int ans = 0;
	while(i) {
		ans += i%pos;
		i /= pos;
	}
	return ans;
} 
int main() {
	for(int i = 2992;i <= 9999;i++) {
		//三种进制的数字和相等时输出
		if(f(i,10)==f(i,16)&&f(i,10)==f(i,12))
			cout<<i<<endl;
	}
	return 0;
} 
