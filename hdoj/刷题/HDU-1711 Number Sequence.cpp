#include<cstdio>//ac don't use cin !!!
#include<cstring>
using namespace std;
const int maxn = 1e6+5;
int nextt[10005],n[maxn],m[10005];
int num_1,num_2;
void get_next() {
	int i = 0, j = -1;
	nextt[0] = -1;
	while(i<num_2) {//目标串长度
		if(j==-1||m[i]==m[j]) nextt[++i] = ++j;
		else j = nextt[j];//自身回退
	}
}
int kmp() {
	int i = 0,j = 0;
	get_next();
	while(i<num_1&&j<num_2) {
		if(n[i]==m[j]||j==-1) i++,j++;
		else j = nextt[j];//回退
	}
	if(j==num_2) return i-j+1;//结果为个数不是下标
	return -1;
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&num_1,&num_2);
		for(int i=0;i<num_1;i++) {
			scanf("%d",&n[i]);//总串
		}
		for(int i=0;i<num_2;i++) {
			scanf("%d",&m[i]);//目标串
		}
		printf("%d\n",kmp());
	}
	return 0;
}
