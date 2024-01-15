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

//题解：从0到9开始判断，每次更新最左和最右和最上和最下的值
//若某个数字出现次数小于2，则面积一定为0！！！
//然后再遍历所有的数，判断当前点和四个极点组合的最大面积
//在当前点的垂直或水平方向放置另外一个点！！！
//与最上和最下组合时，需计算垂直高度，然后选择 0或n 来计算水平宽度（起点为0）
//与最左和最右组合时，需计算水平宽度，然后选择 0或n 来计算垂直高度

const int MAXN = 2e3+5;
string a[2005];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        for(int i = 0;i < n;i++) cin>>a[i];
        for(int i = 0;i <= 9;i++) {//逐个数字判断，从0到9
            if(i!=0) cout<<" ";
            int leftt = n,up = n,down = 1,rightt = 1;//极点初始化
            int num = 0,ans = 0;//num计算当前值的数量，ans记录答案
            for(int j = 0;j < n;j++) {
                for(int k = 0;k < n;k++) {
                    int tmp = a[j][k]-'0';
                    if(tmp!=i) continue;//不为当前数
                    num++;
                    leftt = min(leftt,k);//更新4个极点
                    up = min(up,j);
                    down = max(down,j);
                    rightt = max(rightt,k);
                }
            }
            if(num<2) cout<<"0";//2！！！
            else {
                for(int j = 0;j < n;j++) {//以四个极点为第一个顶点
                    for(int k = 0;k < n;k++) {//然后寻找第二个顶点
                        int tmp = a[j][k]-'0';//第三个顶点任意（取边界点值最大）
                        if(tmp!=i) continue;
                        ans = max(ans,max(down-j,j-up)*max((n-1)-k,k));//固定垂直方向的极点
                        ans = max(ans,max(rightt-k,k-leftt)*max((n-1)-j,j));//固定水平方向的极点
                    }
                }
                cout<<ans;
            }
        }
        cout<<"\n";
    }
	return 0;
}
