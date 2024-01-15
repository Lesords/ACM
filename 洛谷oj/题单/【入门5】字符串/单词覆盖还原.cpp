#include<iostream>//ac
#include<string>
using namespace std;

//题解：既然字符会被覆盖,那么连续的一个boy或girl只能算一个
//那么也就只需要判断各个位置是否出现相应的字符即可

int main() {
	string s;
	int boy = 0,girl = 0;
	cin>>s;
	for(int i = 0;i < s.size();i++) {
		//三个位置若出现一个就算一个boy
		if(s[i]=='b'||s[i+1]=='o'||s[i+2]=='y') boy++;
		//四个位置若出现一个就算一个girl
		if(s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l') girl++;
	}
	cout<<boy<<endl<<girl<<endl;
	return 0;
}
