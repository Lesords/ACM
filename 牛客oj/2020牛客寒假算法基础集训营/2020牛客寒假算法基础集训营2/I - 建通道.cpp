#include<iostream>//ac
#include<set>
using namespace std;

//题解：已知数据范围最大为30位，则可以记录每个数的二进制位值
//只要存在一个最低位出现1和0，则可以以此为基础建通道
//答案即为（去重后的数量-1）*（该位对应的值）

//思路：两个星球的距离为异或值，则越低位出现1和0，异或值越低

bool vis[31][2];
set<int> s;//由于相同的权值距离为0，则需去重！！！
int main() {
	int n,tmp,ans;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		if(s.count(tmp)) continue;//已存在
		s.insert(tmp);
		for(int i = 0;i <= 30;i++) {//遍历所有位数
			if(tmp&1) vis[i][1] = 1;//记录到对应的二进制值
			else vis[i][0] = 1;
			tmp >>= 1;//每次右移一位
		}
	}
	for(int i = 0;i <= 30;i++) {
		if(vis[i][0]&&vis[i][1]) {//既有1又有0
			ans = i;//满足条件的最低位
			break;
		}
	}//set的大小即为去重后的数量
	cout<<(s.size()-1)*(1<<ans)<<endl;
	return 0;
}
