#include<iostream>//ac
#include<set>
#include<algorithm>
using namespace std;
const int MAXN = 15e4+5;
int a[MAXN];
int main() {
	int n;
	set<int> s;//保存独一无二的拳击手
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);//升序
	for(int i = 1;i <= n;i++) {
		//由于是升序，则优先将降低拳击手的体重
		//然后判断不变和升高
		if(a[i]>1&&s.count(a[i]-1)==0) s.insert(a[i]-1);
		else if(s.count(a[i])==0) s.insert(a[i]);
		else if(s.count(a[i]+1)==0) s.insert(a[i]+1);
	}
	cout<<s.size();//输出数量
	return 0;
}
