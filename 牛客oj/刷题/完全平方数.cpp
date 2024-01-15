#include<iostream>//ac
#include<cmath>
#define ll long long
#define s(a) sqrt(a)
using namespace std;

//题解：判断a到b的完全平方数个数
//可以直接判断a和b的sqrt(a)和sqrt(b)的差
//相当于sqrt(a)映射到a，sqrt(b)映射到b

int main() {
	ll n,a,b;
	cin>>n;
	while(n--) {
		cin>>a>>b;
		//大的向下取整，小的向上取整
		//范围数量需+1
		cout<<floor(s(b))-ceil(s(a))+1<<endl;
	}
	return 0;
}
