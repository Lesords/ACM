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

//题解：由于根为1，并且为bfs遍历，所有前两个点肯定是固定的
//并且所有的子儿子是根据上升来遍历的
//那么从第三个节点开始判断，如果大于前一个节点，表示为同一层的节点
//无需更换父节点
//否则，需要寻找新的父节点（利用last记录父节点，后移一位即为新的父节点）
//不断更定深度，最后的h[n]即为结果

const int MAXN = 2e5+5;
int a[MAXN],h[MAXN];//h[i] 为 i点 的高度
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,last = 1;//last为当前的父节点
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        h[1] = 0,h[2] = 1;//初始化，前两个的值是固定的
        for(int i = 3;i <= n;i++) {
            //last 巨巧妙！！！
            //子节点为升序！！！
            if(a[i]<a[i-1]) last++;//当前值小于前一个值，需要换个节点存子节点
            h[i] = h[last] + 1;//当前节点的高度为 父节点+1
        }
        cout<<h[n]<<"\n";//n的高度即为树的高度
    }
	return 0;
}
