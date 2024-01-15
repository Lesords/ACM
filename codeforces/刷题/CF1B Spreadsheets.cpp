#include<iostream>//ac
#include<string>
using namespace std;
string toChr(string num) {//数字改为字母
	string ans = "";
	int tmp = 0;
	for(int i = 0;i < num.size();i++) {
		tmp = tmp*10+int(num[i]-'0');
	}//先改为整型数字
	char ch;
	while(tmp) {
		ch = (tmp%26-1+26)%26+'A';//当前位
		ans = ch+ans;
		tmp /= 26;
		if(ch=='Z') tmp--;//ch为Z(26)时，则高位需减1！！！
	}
	return ans;
}
int toNum(string chr) {//字符串改为数字
	int num = 0;
	for(int i = 0;i < chr.size();i++) {
		num = num*26+int(chr[i]-'A'+1);
	}
	return num;
}
bool check(string s) {//判断是哪种格式
	if(s[0]=='R'&&s[1]>='0'&&s[1]<='9') {
		for(int i = 2;i < s.size();i++) {
			if(s[i]=='C') return 1;
			//R数字C数字格式
		}
	}
	return 0;
}
int main() {
	int n;
	string s;
	cin>>n;
	while(n--) {
		cin>>s;
		if(check(s)) {
			string row = "",col= "";
			int flag = 0;
			for(int i = 1;i < s.size();i++) {
				if(s[i]=='C') {//C为分割线，跳过
					flag = 1;continue;
				}
				if(!flag) row += s[i];//先行后列
				else col += s[i];
			}
			//字母加数字为先列后行
			cout<<toChr(col)<<row<<"\n";
		}
		else {
			string row = "",col = "";
			int flag = 0;
			for(int i = 0;i < s.size();i++) {
				if(s[i]>='0'&&s[i]<='9') flag = 1;//数字类型即为分割
				if(!flag) col += s[i];
				else row += s[i];
			}
			cout<<"R"<<row<<"C"<<toNum(col)<<"\n";
		}
	}
	return 0;
}
