#include<iostream>//ac
#include<string>
using namespace std;
int judge(char ch) {//判断数字型数字
	if(ch=='0'||ch=='2'||ch=='4'||ch=='6'||ch=='9') return 1;
	return 0;
}
string solve(string a) {
	string ans = "";
	for(int i = 0;i < a.size();i++) {
		if(a[i]>='0'&&a[i]<='9') {
			if(judge(a[i])) ans += a[i];
		}
		else {
			if(i+2 >=a.size()) continue;
			string tmp;
			tmp.assign(a,i,3);//a字符串，i为起始点，3为长度
			if(tmp == "zer"&&a[i+3] == 'o') ans += '0',i += 1;
			else if(tmp == "two") ans += '2';
			else if(tmp == "fou"&&a[i+3] == 'r') ans += '4', i += 1;
			else if(tmp == "six") ans += '6';
			else if(tmp == "nin"&&a[i+3] == 'e') ans += '9', i += 1;
			else continue;
			i += 2;
		}
	}
	return ans;
}
int main() {
	int t;
	cin>>t;
	string a;
	while(t--) {
		cin>>a;
		cout<<solve(a)<<endl;
	}
	return 0;
} 
