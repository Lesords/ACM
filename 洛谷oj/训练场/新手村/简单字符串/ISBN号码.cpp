#include<iostream>//ac
#include<cstdio>
using namespace std;
char judge(int a, int b,int c) {
	int ans = 0,cnt = 9;
	while(c) {
		ans += cnt*(c%10);//注意优先级！！！
		c /= 10;
		cnt--;
	}
	while(b) {
		ans += cnt*(b%10);
		b /= 10;
		cnt--;
	}
	ans = (ans+a)%11;
	if(ans == 10) return 'X';
	return ans + '0';
}
int main() {
	int a,b,c;
	char d;
	scanf("%d-%d-%d-%c",&a,&b,&c,&d);
	char jud = judge(a,b,c);
	if(d==jud) cout<<"Right"<<endl;
	else cout<<a<<'-'<<b<<'-'<<c<<'-'<<jud<<endl;
	return 0;
}
