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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：权值树状数组求第k大值
//由于数据范围较大，所以需要用到离散化
//那么需要离线操作，因为要先存储数据才能离散化
//由于每次需要 拉取管道头部 的要求，那么我们需要用到队列来记录所有要求
//那么碰到 out 操作时，直接提取队首即可
//对于in和out的操作，我们都可以理解对应的数值出现的次数+1和-1
//即这两个操作实际上就是对树状数组进行单点修改
//对应query操作，其实就是寻找第k大

const int MAXN = 1e4+5;
const int MOD = 1e9+7;
string op[MAXN];
int a[MAXN],tree[MAXN],b[MAXN],siz;
int lowbit(int x) {
    return (x)&(-x);
}
int get_val(int pos) {//获取pos值对应的位置
    return lower_bound(a+1, a+siz+1, pos)-a;
}
int add(int pos,int val) {//对pos进行 +val 操作
    while(pos<=siz) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int kth(int mid) {//寻找第 mid 小数值
    int num = 0, pos = 0;
    int len = log2(siz);
    for(int i = len;~i;i--) {
        pos += 1<<i;
        if(pos>=siz||num+tree[pos]>=mid) pos -= 1<<i;
        else num += tree[pos];
    }
    return a[pos+1];//对应位置的值即为实际值
}
int main() {
    fast;
    int n,cas = 1;
    while(cin>>n) {
        queue<int> q;
        memset(tree, 0, sizeof(tree));//初始化为0
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            int x;
            cin>>op[i];
            if(op[i]=="in") {
                cin>>x;
                a[++cnt] = x;//记录数据（用于后面的离散化
                b[cnt] = x;//再次记录数据（用于离线操作 in）
                q.push(x);//队列记录信息（用于离线操作 out）
            }
        }
        sort(a+1, a+cnt+1);
        siz = unique(a+1, a+cnt+1)-a-1;//离散化操作
        cnt = 1;//in操作的位置
        int num = 0;//当前管道内请求的数量
        cout<<"Case #"<<cas++<<":\n";//注意 cas++！！！
        for(int i = 1;i <= n;i++) {
            if(op[i]=="in") {
                num++;//添加，数量++
                add(get_val(b[cnt++]), 1);//对应位置+1
            }
            else if(op[i]=="out") {
                num--;//减少，数量--
                add(get_val(q.front()), -1);//对应位置-1
                q.pop();//弹出队首
            }
            else {
                //返回 num/2+1 的值
                cout<<kth(num/2+1)<<"\n";
            }
        }
    }
	return 0;
}
