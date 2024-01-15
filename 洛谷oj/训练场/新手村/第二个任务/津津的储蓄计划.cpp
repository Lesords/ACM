#include<iostream>//ac
using namespace std;
int a[15];
int main() {
	int flag = 0,mine = 0,mother = 0;
	for(int i = 1;i <= 12;i++) {
		cin>>a[i];
		if(flag) continue;
		if(mine+300<a[i]) flag = i;//不够用
		else {
			int rest = mine+300 - a[i];//剩下的钱
			if(rest>=100) mother += rest/100 * 100;//给母亲的
			mine = rest % 100;//自己剩下的
		}
	}
	if(flag) cout<<"-"<<flag<<endl;//不够用
	else cout<<mine + mother*1.2<<endl;
	return 0;
}
