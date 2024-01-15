#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
bool judge(int n) {
	int year = n/10000;
	int month = n/100%100;
	int day = n%100;
	int num[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%4==0&&year%100||year%400==0) num[2]++;//闰年
	if(num[month]<day) return 0;//日期不正常
	int tmp = 0,ori = n;//tmp为反串
	while(n) {
		tmp = tmp*10 + n%10;
		n /= 10;
	}
	return tmp == ori;//判断是否相同
}
int main() {
	int a,b,ans = 0;
	cin>>a>>b;
	for(int i = a;i <= b;i++) {
		if(i%100>31) continue;//不是正常的日期
		if(i/100%100>12) continue;//不是正常的月份
		if(judge(i)) ans++;//判断日期是否正常且是否为回文串
	}
	cout<<ans;
	return 0;
}
