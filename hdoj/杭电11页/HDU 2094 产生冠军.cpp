#include<iostream>//ac
#include<string>
#include<map>
using namespace std;
int main() {
	int n;
	while(cin>>n&&n) {
		map<string,int> win;
		map<string,int> los;
		map<string,int>::iterator it;
		string tmp1,tmp2;
		while(n--) {
			cin>>tmp1>>tmp2;
			win[tmp1] = 1;
			los[tmp2] = 1;
		}
		int cnt = 0;
		//win出现的，los没有出现过，且只有一个
		for(it = win.begin();it != win.end();it++)
			if(!los[it->first]) cnt++;
		if(cnt==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
