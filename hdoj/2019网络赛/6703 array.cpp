#include<cstdio>//ac
#include<algorithm>
using namespace std;

//题解：用权值线段树来记录每个值出现的位置，维护区间最大出现位置
// (1,pos) 将pos的原来的值的位置修改成n+1（从原序列中删除）
// (1,r,k) 遍历值域[k,n]，取位置大于r的最小值

const int MAXN = 1e5+5;
struct node {
    int l,r,index;//index记录值的位置，更新区间最大位置
}tree[MAXN<<2];
int a[MAXN],val[MAXN],n,m;//val记录值，a记录对应值的位置
void build(int dot,int l,int r) {//初始化线段树
    tree[dot].l = l,tree[dot].r = r;//该节点的左右区间
    if(l==r) {//叶子结点
        tree[dot].index = a[l];//保存l出现的位置
        return;
    }
    int mid = (l+r)/2;
    build(dot<<1,l,mid);//左区间
    build(dot<<1|1,mid+1,r);//右区间
    //更新较大出现位置
    tree[dot].index = max(tree[dot<<1].index,tree[dot<<1|1].index);
}
void change(int dot,int val) {//修改节点操作（dot是节点下标，val是修改的值）
    int l = tree[dot].l,r = tree[dot].r;//左右区间
    if(l==r&&l==val) {//叶子节点且值为val
        tree[dot].index = n+1;//修改位置
        return ;
    }
    int mid = (l+r)/2;
    if(val<=mid) change(dot<<1,val);//递归修改包含val的区间
    else change(dot<<1|1,val);
    //更新最大位置
    tree[dot].index = max(tree[dot<<1].index,tree[dot<<1|1].index);
}
int query(int dot,int l,int r,int index) {//查询[l,r]区间里位置大于index的最小值
    if(l <= tree[dot].l && tree[dot].r <= r) {//查询区间大于节点区间
        if(tree[dot].l==tree[dot].r) {//叶子节点
            if(tree[dot].index>index) return tree[dot].l;
            else return n+1;
        }
        //判断左右子节点哪个的位置大于index（优先判断左，应为值小）
        if(tree[dot<<1].index>index) return query(dot<<1,l,r,index);
        if(tree[dot<<1|1].index>index) return query(dot<<1|1,l,r,index);
        return n+1;
    }
    int mid = (tree[dot].l+tree[dot].r)/2;
    int ans = n+1;//初始化为n+1
    //只判断单侧，未判断另一侧，所以需要写查询区间（l和r都为同一侧时，取mid会大于原值）！！！
    if(mid>=l) ans = query(dot<<1,l,r,index);//左区间有包含（查询区间不变！！！）
    if(mid<r) ans = min(ans,query(dot<<1|1,l,r,index));//右区间有包含（取小）
    return ans;//返回结果
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++) {
            scanf("%d",&val[i]);a[val[i]] = i;
            //读入数据，并记录对应值的位置（位置为下标）
        }
        build(1,1,n);//初始化权值线段树
        int op,x,y,last = 0;
        for(int i = 1;i <= m;i++) {
            scanf("%d%d",&op,&x);
            if(op==1) {
                x ^= last;//x为所需修改值的下标
                change(1,val[x]);
            }
            else {
                scanf("%d",&y);
                x ^= last;//r的值
                y ^= last;//k的值
                last = query(1,y,n,x);//更新last
                printf("%d\n",last);
            }
        }
    }
    return 0;
}
