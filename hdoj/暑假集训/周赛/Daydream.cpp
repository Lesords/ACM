#include<iostream>//尺取法 定起点与长度 
#include<cstring>//判断当前字符最近是否出现在起点前面 
using namespace std;
const int maxn = 1e7+5;
char a[maxn];
int book[150];
int main() {
	int T;
	ios::sync_with_stdio(false);//加速（1e7） 
	while(cin>>T) {
		cin>>a;
		memset(book,-1,sizeof(book));//-1小于初始长度 
		int len,st,tmp_st,tmp_len;
		len = st = tmp_st = tmp_len = 0;
		for(int i = 0;i < T;i++) {//a[i]字符出现在临时起点前面
			if(book[a[i]] < tmp_st) tmp_len++;//临时长度++
			else {
				if(tmp_len > len) {
					len = tmp_len;
					st = tmp_st;
				}
				tmp_st = book[a[i]] + 1;//更新临时起点 
				tmp_len = i - tmp_st + 1;//更新临时长度 
			}
			book[a[i]] = i;//更新a[i]字符出现的位置 
		}
		if(tmp_len > len) {//最后一次判定 
			len = tmp_len;
			st = tmp_st;
		} 
		cout<<len<<' '<<st<<' '<<len + st - 1<<endl;
	}
	return 0;
}
