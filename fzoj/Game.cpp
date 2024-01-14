#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1e5+5;
char a[maxn],b[maxn];
int nextt[maxn],len_a,len_b;
void get_next() {//求next数组 
	int i = 0,j = -1;
	nextt[i] = j;
	while(i<len_b) {
		if(b[i]==b[j]||j==-1) nextt[++i] = ++j;
		else j = nextt[j];
	}
}
bool kmp() {//kmp算法 
	int i = 0,j = 0;
	get_next();
	while(i<len_a&&j<len_b) {
		if(a[i]==b[j]||j==-1) i++,j++;
		else j = nextt[j];
	}
	if(j==len_b) return true;//匹配成功 
	return false;
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		len_a = strlen(a);
		len_b = strlen(b);
		if(b[0]=='0') {//b为0的情况
			cout<<"Alice"<<endl;
			continue;
		}
		if(len_a<len_b) cout<<"Bob"<<endl;
		//a的字符串比b小的话，b可以一直翻转，则游戏会一直继续
		else {//只需判断b是不是a的子串即可
			if(kmp()) cout<<"Alice"<<endl;
			else {
				reverse(a,a+len_a);//翻转之后 
				if(kmp()) cout<<"Alice"<<endl;
				else cout<<"Bob"<<endl;
			}
		}
	}
	return 0;
} 
