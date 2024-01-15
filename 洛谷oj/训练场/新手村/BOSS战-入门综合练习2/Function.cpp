#include<iostream>//ac

//#define f(a,b,c) (book[a][b][c]?book[a][b][c]:book[a][b][c]=w(a,b,c))

#define ll long long
using namespace std;
ll book[22][22][22];
ll w(ll a, ll b, ll c) {
	if(a<=0||b<=0||c<=0) return 1;
	if(a>20||b>20||c>20) return w(20,20,20);
	if(book[a][b][c]) return book[a][b][c];//已计算过，直接返回
	if(a<b&&b<c) {//保存每次处理的值即可！！！
		ll sum = book[a][b][c-1] = w(a,b,c-1);
		sum += book[a][b-1][c-1] = w(a,b-1,c-1);
		sum -= book[a][b-1][c] = w(a,b-1,c);
		return sum;//可用sum变量代替长式子！
	}
	ll sum = book[a-1][b][c] = w(a-1,b,c);
	sum += book[a-1][b-1][c] = w(a-1,b-1,c);
	sum += book[a-1][b][c-1] = w(a-1,b,c-1);
	sum -= book[a-1][b-1][c-1] = w(a-1,b-1,c-1);//最后一个是减
	return sum;
}
int main() {
	ll a,b,c;
	while(cin>>a>>b>>c) {
		if(a==-1&&b==-1&&c==-1) break;
		ll ans = w(a,b,c);
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<endl;
	}//注意格式！！！
	return 0;
}
