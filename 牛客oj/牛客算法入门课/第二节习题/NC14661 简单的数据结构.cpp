#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;
int main() {
	int n,m,op;
	deque<int> d;
	cin>>n>>m;
	while(m--) {
		cin>>op;
		if(op==1) {
			cin>>op;
			d.push_front(op);
		}
		else if(op==2) d.pop_front();
		else if(op==3) {
			cin>>op;
			d.push_back(op);
		}
		else if(op==4) d.pop_back();
		else if(op==5) reverse(d.begin(),d.end());
		else if(op==6) {
			cout<<d.size()<<endl;
			for(int i = 0;i < d.size();i++) {
				if(i) cout<<' ';
				cout<<d.at(i);//at函数可以获取i位置的值
			}
			cout<<endl;
		}
		else sort(d.begin(),d.end());
	}
	return 0;
}
