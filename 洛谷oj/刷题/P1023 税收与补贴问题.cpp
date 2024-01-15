#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
	int val,num;
	friend bool operator < (node a,node b) {
		if(a.val!=b.val) return a.val<b.val;
		return a.num>b.num;
	}
}a[MAXN];
int except,num,cnt,cost;
int solve(int money) {
	int maxx = 0,tmp,mon = 0;
	for(int i = 1;i <= cnt;i++) {
		tmp = (a[i].val-cost+money)*a[i].num;
		if(tmp>=maxx) {//可能有多个最大利润
			maxx = tmp;
			mon = a[i].val;
		}
	}
	return mon;
}
int main() {
	cin>>except;
	while(1) {
		++cnt;
		cin>>a[cnt].val>>a[cnt].num;
		if(a[cnt].val==-1&&a[cnt].num==-1) {
			cnt--;break;
		}
	}
	cin>>num;
	sort(a+1,a+cnt+1);
	int siz = cnt,tval,tnum,tend,pos = 1;
	cost = a[1].val;
	tval = a[1].val+1;
	tnum = a[1].num-num;
	tend = a[2].val;
	while(pos<siz) {
		while(tval<tend) {
			if(tnum<0) break;
			++cnt;
			a[cnt].val = tval;
			a[cnt].num = tnum;
			tval++,tnum -= num;
		}
		if(tnum<=a[pos+1].num) {
			tval = a[pos+1].val+1;
			tnum = a[pos+1].num-num;
			tend = a[pos+2].val;
			pos++;
		}
		else {
			tend = a[pos+2].val;
			++pos;
		}
	}
	while(tnum>0) {
		++cnt;
		a[cnt].val = tval;
		a[cnt].num = tnum;
		tnum -= num;
		tval++;
	}
	sort(a+1,a+cnt+1);
	for(int i = 1;i <= MAXN;i++) {//遍历所有结果
		if(solve(i)==except) {//补贴
			cout<<i;return 0;
		}
		if(solve(i*-1)==except) {//税金
			cout<<i*-1;return 0;
		}
	}
	cout<<"NO SOLUTION";
	return 0;
}
