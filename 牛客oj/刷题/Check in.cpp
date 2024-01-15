#include<iostream>//ac
#include<string>
#include<set>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		string a;
		set<string> s;
		while(n--) {
			cin>>a;
			if(a.substr(0,5) == "bnu16") s.insert(a);//16ºÜ¹Ø¼ü
		}
		cout<<s.size()<<endl;
	}
	return 0;
}
