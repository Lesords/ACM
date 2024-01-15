#include<iostream>//ac
using namespace std;

//题解：sqrt(i) + sqrt(j) = sqrt(k)
// => i + j + 2 * sqrt(i*j) = k
// => i * j 即 n 必须为完全平方数才能为整数

// 由于 i*j <= n，则可以遍历 1 ~ n 中所有的完全平方数
//统计这些完全平方数的所有因子数

int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i*i<=n;i++) {//遍历所有的完全平方数
		int k = i*i;//记录为当前的完全平方数
		for(int j = 1;j*j <= k;j++) {//最多遍历一半因子数
			if(k%j==0) {//相同因子只有一个三元组
				ans += (j==k/j)?1:2;
			}//不同因子，互换位置后这有两个三元组
		}
	}
	cout<<ans<<endl;
	return 0;
}
