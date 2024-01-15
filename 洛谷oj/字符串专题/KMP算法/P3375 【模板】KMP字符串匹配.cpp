#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;

//题解：kmp
//记录所有出现的位置，匹配成功的时候再重头匹配一次，直到所有位置都匹配完成
//对于border的值，其实就是nextt数组的值
//只不过由于匹配成功会后移，所以对应位置也需要后移！！！

int len_n,len_m,nextt[MAXN];
char n[MAXN],m[MAXN];//n为长串，m为短串
void get_nextt() {
	int i = 0,j = -1;
	nextt[i] = j;
	while(i<len_m) {//目标串长度
		if(m[i] == m[j]||j == -1) nextt[++i] = ++j;
		else j = nextt[j];//自身回退
	}
}
bool kmp() {
	int i = 0, j = 0;
	get_nextt();
	while(i<len_n&&j<len_m) {
		if(n[i]==m[j]||j==-1) i++,j++;
		else j = nextt[j];//回退
		if(j == len_m) {
            //i后移一位，所以直接 -len_m即为左边界
            //并且由于结果从1开始所以+1
            cout<<i-len_m+1<<"\n";
            j = nextt[j];//重新再匹配
		}
	}
	if(j == len_m) return true;
	return false;
}

int main() {
    cin>>n>>m;
    len_n = strlen(n);//先记录字符串的长度！！！
    len_m = strlen(m);
    get_nextt();
    kmp();
    //原串从0开始，但是nextt记录会后移，所以从1开始
    for(int i = 1;i <= len_m;i++) cout<<nextt[i]<<" ";
    return 0;
}
