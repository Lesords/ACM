#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：zkw线段树
//将每个操作理解为点修改，输出结果为区间查询即可

const int MAXN = 1e5+5;
int q,m;
ll tree[MAXN<<2];
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>q>>m;
        //初始化建树，所有点值为1
        for(int i = 0;i <= 2*q;i++) tree[i] = 1;
        for(int i = 1;i <= q;i++) {
            int op,x;
            cin>>op>>x;
            int pos = op==1?i:x;//对应位置
            int val = op==1?x:1;//对应值
            pos += q-1;//对应叶子节点编号（上面共 q-1 个节点
            tree[pos] = val%m;//修改对应叶子节点的值
            //自下到上，更新对应祖先节点的值
            //pos为当前点，所以需先移位一次
            for(pos>>=1; pos; pos>>=1) {
                tree[pos] = (tree[pos*2]*tree[pos*2+1])%m;
            }
            cout<<tree[1]<<"\n";//根节点即为值
        }
    }
    return 0;
}
