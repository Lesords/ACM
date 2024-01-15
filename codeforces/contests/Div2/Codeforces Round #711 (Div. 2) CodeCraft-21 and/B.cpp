#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：题目中说所有的矩形的长度都为2的倍数，其实就是说矩形的类型数量不超过20
//所以可以直接统计各个大小的矩形数量
//每次从大到小开始寻找满足条件的矩形，不满足条件可更新宽度和高度

const int MAXN = 1e5+5;
int a[MAXN],num[30];//num存储对应 (1<<i) 矩形的数量
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,w;
        cin>>n>>w;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[(int)log2(a[i])]++;//统计对应矩阵的数量
        }
        ll width = w,hei = 1;//初始化宽度（剩余宽度）为w，高度为1
        for(int i = 1;i <= n;) {//需要选择n个矩阵
            int tri = -1;//记录选择的矩阵编号
            for(int j = 20;j >= 0;j--) {//从大到小开始寻找
                if(num[j]&&width>=(1<<j)) {//还有剩余数量并且放的下
                    width -= (1<<j);//修改剩余宽度
                    tri = j;//标记编号
                    break;
                }
            }
            if(tri==-1) {//为-1说明没有找到满足条件的矩形
                hei++;//修改高度和更新宽度，并忽略后面的操作
                width = w;
                continue;
            }
            num[tri]--;//对应数量--（每个矩阵最后都会选完，所以不需要初始化为0
            i++;//操作数++
        }
        cout<<hei<<"\n";
    }
	return 0;
}
