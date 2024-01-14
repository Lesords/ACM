#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<string>
using namespace std;
int main() {
	int n,m;
	while(cin>>n>>m) {
		map<string,string> map;
		map.clear();
		string str1,str2;
		for(int i=1;i<=n;i++) {
			cin>>str1>>str2;
			map[str1]=str2;
		}
		for(int i=1;i<=m;i++) {
			cin>>str1;
			string s(str1,0,str1.size()-1);
			string s1(str1,str1.size()-1);
			string s2(str1,str1.size()-2);
			if(map.find(str1)!=map.end()) {
				cout<<map[str1]<<endl;
			}
			else if(s1=="y"&&s2[0]!='a'&&s2[0]!='e'&&s2[0]!='i'&&s2[0]!='o'&&s2[0]!='u'){
				cout<<s<<"ies"<<endl;
			}
			else if(s1=="o"||s1=="s"||s1=="x"||s2=="ch"||s2=="sh") {
				cout<<str1<<"es"<<endl;
			}
			else {
				cout<<str1<<"s"<<endl;
			}
		}
	}
	return 0;
}
