#include<iostream>//ac
#include<cstring>
using namespace std;
char a[1005],b[1005];
int nextt[1005],ans,len_a,len_b;
void get_next() {//计算nextt数组
	int i = 0,j = -1;
	nextt[i] = j;
	while(i < len_b) {
		if(b[i] == b[j]||j == -1) nextt[++i] = ++j;
		else j = nextt[j];//自身回退
	}
}
void kmp() {
	get_next();
	int i = 0,j = 0;
	while(i < len_a) {
		if(a[i] == b[j]||j == -1) i++,j++;
		else j = nextt[j];
		if(j==len_b) {//模式串匹配成功
			ans++;//答案++
			j = 0;//重置
		}
	}
}
int main() {
	while(cin>>a) {
		if(a[0]=='#') break;
		ans = 0;
		cin>>b;
		len_a = strlen(a),len_b = strlen(b);
		kmp();
		cout<<ans<<endl;
	}
	return 0;
}
