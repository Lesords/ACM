#include<iostream>//ac
using namespace std;

//题解：将表的数据呈金字塔形书写，可找到规律
//奇数层：从大到小 / 从小到大 (范围为 1 - lay)
//偶数层：从小到大 / 从大到小 (范围为 1 - lay)

//         1/1
//      2/1   1/2 <- 
// -> 3/1  2/2  1/3
//  4/1 3/2 2/3 1/4 <-

int main() {
	int n,cnt = 1,lay = 1;
	cin>>n;
	while(cnt<n) lay++,cnt += lay;//求出lay层数
	int rest = n - (cnt-lay);//当前层数剩余几个
	if(lay%2) cout<<lay-rest+1<<'/'<<rest;
	else cout<<rest<<'/'<<lay-rest+1;
	return 0;
} 
