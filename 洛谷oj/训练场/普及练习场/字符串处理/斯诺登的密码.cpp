#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
using namespace std;
string num[30] = {"","one","two","three","four","five","six","seven",
"eight","nine","ten","eleven","twelve","thirteen","fourteen",
"fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
"a","both","another","first","second","third"};
string a[10],cnt[10];
int uno[10] = {1,2,1,1,2,3};//非正规数字！！！
bool cmp(string a,string b) {//字符串自带比较
	return a+b < b+a;//从小到大
}
int main() {
	map<string,int> map;//保存英文转数字后的结果
	for(int i = 1;i <= 20;i++) map[num[i]] = (i*i)%100;
	for(int i = 0;i <= 5;i++) map[num[i+21]] = (uno[i]*uno[i])%100;
	int cas = 1;
	for(int i = 1;i <= 7;i++) {
		cin>>a[i];
		if(i==7) continue;//只有6个有效单词
		if(map[a[i]]) {//存在此字符串
			int tmp = map[a[i]];
			if(tmp<10) {//只有一位数
				char ch = tmp%10 + '0';//个位数
				cnt[cas] = '0';//前面补充一位0
				cnt[cas] += ch;
			}
			else {
				char left = tmp/10%10 + '0';//十位数字符
				char right = tmp%10 + '0';//个位数字符
				cnt[cas] = left;
				cnt[cas] += right;
			}
			cas++;//保存结果的指针向后移一位
		}
	}
	if(cas==1) {//不存在数字
		cout<<'0';return 0;
	}
	sort(cnt+1,cnt+cas,cmp);//自定义排序
	string ans = "";//用于保存结果
	for(int i = 1;i < cas;i++) ans += cnt[i];
	while(ans[0]=='0'&&ans.size()>1) ans.erase(0,1);//去除开头0
	cout<<ans<<endl;
	return 0;
}
