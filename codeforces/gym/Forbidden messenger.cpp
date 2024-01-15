#include<iostream>//ac
#include<cmath>//c++14必须用cmath，c++11也可(algorithm)
using namespace std;
int main() {
	double x,a,b;//a是写的时间，b是发的时间
	int ans = 0;//初始化结果为0
	cin>>x>>a>>b;
	double minute = x*60;//分钟数
	if(minute>=a+b) {//时间够的情况，否则为0
		ans++,minute -= a+b;//第一个信息
		ans += floor(minute/(a<b?b:a));
	}
	//如果发的时间比写长，则可在第一次发的时间内写第二信息
	//所以第二次及以后只需要判断发的时间（b）即可
	
	//如果写的时间比发的时间长(发的时间也写)
	//则第二次 写和发 的时间为 a+b - b(扣除第一次发的时间)
	//所以第二次及以后只需要判断写的时间（a）即可
	cout<<ans;
	return 0;
}
