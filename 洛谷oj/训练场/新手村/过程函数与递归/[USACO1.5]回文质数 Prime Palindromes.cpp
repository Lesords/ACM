#include<iostream>//ac
using namespace std;//1111111可被11整除也需排除
const int MAXN = 1e7 + 5;//偶数一定不为素数，则只需要1e7
int prime[MAXN];
bool is_pand(int x) {
	int tmp = x,y = 0;
	while(tmp) {//逆序构数
		y = y*10+tmp%10;
		tmp /= 10;
	}
	return x == y;//判断大小
}
int main() {
	for(int i = 2;i < MAXN;i++) {//埃式筛法
		if(prime[i]) continue;
		for(int j = i+i;j < MAXN;j += i) prime[j] = 1;
	}
	int a,b;
	cin>>a>>b;
	for(int i = a;i <= b;i++) {
		if(i>=MAXN-5) break;//越界直接退出
		if(!prime[i]&&is_pand(i)) cout<<i<<endl;
	}
	return 0;
}
