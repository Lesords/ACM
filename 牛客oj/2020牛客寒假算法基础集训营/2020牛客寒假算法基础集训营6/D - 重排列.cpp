#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：由于只要满足a数组一对一小于b数组即可
//则可以将a和b数组都升序排列
//然后用双指针判断，每个位置可以有几个数字可选，累乘即可

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int a[MAXN], b[MAXN];
int main() {
	int n,ans = 1;//ans初始化为1（乘法）
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",a+i);
	for(int i = 1;i <= n;i++) scanf("%d",b+i);
	sort(a+1,a+n+1);//升序
	sort(b+1,b+n+1);
	for(int i = 1,j = 0;i <= n;i++) {//遍历所有数（b数组为准）
		while(j<n&&a[j+1]<=b[i]) j++;//a的下一位不大于b的当前位
		//可选数字个数为 总数（j） - 已用数量（i-1）
		ans = (ans*max(0LL,j-i+1LL))%MOD;//取模
	}
	cout<<ans<<endl;
	return 0;
}
