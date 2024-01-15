#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：种类并查集
//由于只有两行，并且每行都需要为全排列，即不能有重复的
//所以可以先记录所有数字出现次数，如果有数字出现不为两次的，则无解
//对于每个数来说，两次出现的位置不能为同行，即为不同行
//所以先可以记录每个数，两次出现的位置
//为了方便计算，第二行的位置为索引+n！！！
//由于每列只有两种状态，换和不换
//所以可以根据值（1~n）出现的位置来逐个判断哪列需要交换
//如果两次出现在同一行，则选择任一列交换即可
//否则两列都需要交换（小于等于n表示交换，大于n表示不交换）
//合并对应的情况
//最后遍历每一列，判断是否有哪一列 换和不换 重合了
//如果没有的话，选择操作次数少的放入结果序列中
//相当于：合并符合条件的列为连通块，然后判断连通块内是否有哪列出现矛盾的

const int MAXN = 4e5+10;
int a[MAXN],b[MAXN];
int pos1[MAXN],pos2[MAXN],flag[MAXN],cnt[MAXN];
//pos1记录元素第一次出现的位置，pos2记录元素第二次出现的位置
//flag记录当前列是否需要翻转，cnt记录数字出现的次数
int cost[MAXN],fa[MAXN];//cost为当前列集合花费的操作数，fa为祖先节点
vector<int> ans;//记录结果序列
void init(int n) {//初始化
    ans.clear();
    for(int i = 1;i <= n*2;i++) {
        if(i<=n) {
            cnt[i] = 0;
            pos1[i] = pos2[i] = 0;              //位置初始化为0
            cost[i] = 1;                        //小于等于n需要操作
        }
        else cost[i] = 0;                       //大于n不操作
        fa[i] = i;                              //祖先节点
        flag[i] = 0;
    }
}
int getf(int pos) {//路径压缩
    return fa[pos]=(pos==fa[pos])?pos:getf(fa[pos]);
}
void Merge(int a,int b) {
    a = getf(a);                                //直接用原变量，无需新开变量！！！
    b = getf(b);
    if(a==b) return;
    //错了一万年！！！
    fa[b] = a;                                  //查询和合并的数值不一致！！！
    cost[a] += cost[b];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        init(n);
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            cnt[a[i]]++;                        //记录数值出现次数
            if(pos1[a[i]]==0) pos1[a[i]] = i;   //记录对应出现次数的位置
            else pos2[a[i]] = i;
        }
        for(int i = 1;i <= n;i++) {
            cin>>b[i];
            cnt[b[i]]++;                        //记录数值出现次数
            //第一行的位置+n
            if(pos1[b[i]]==0) pos1[b[i]] = i+n; //记录对应出现次数的位置
            else pos2[b[i]] = i+n;
        }
        int mark = 0;
        for(int i = 1;i <= n;i++) {             //数值出现次数没有两次，则无解
            if(cnt[i]!=2) {
                cout<<"-1\n";
                mark = 1;
                break;
            }
        }
        if(mark) continue;                      //无解则跳过
        for(int i = 1;i <= n;i++) {
            int p1 = pos1[i],p2 = pos2[i];
            if(p1>n) p1 -= n;                   //p1和p2为实际的列数
            if(p2>n) p2 -= n;
            //如果为同行，则交换一个即可，否则两个一起交换
            if((pos1[i]<=n&&pos2[i]<=n)||(pos1[i]>n&&pos2[i]>n)) {
                Merge(p1, p2+n);                //小于等于n的为需要操作，大于n的不需要操作
                Merge(p1+n, p2);
            }
            else {
                Merge(p1, p2);
                Merge(p1+n, p2+n);
            }
        }
        for(int i = 1;i <= n;i++) {             //遍历所有列，判断是否有发生矛盾的
            int p1 = getf(i);
            int p2 = getf(i+n);
            if(p1==p2) {                        //如果发生矛盾了，说明无解
                mark = 1;
                cout<<"-1\n";
                break;
            }
            if(flag[p1]==0) {                   //还未操作，则选择其中操作数少的
                if(cost[p1]<cost[p2]) {
                    flag[p1] = 1;               //1为选择，-1为不选
                    flag[p2] = -1;
                }
                else {
                    flag[p1] = -1;
                    flag[p2] = 1;
                }
            }
            if(flag[p1]==1) {                   //将操作的放入结果序列中
                ans.push_back(i);
            }
        }
        if(mark) continue;                      //无解则跳过
        cout<<ans.size()<<"\n";
        for(int i = 0;i < ans.size();i++) {     //输出所有序列
            if(i) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
    }
	return 0;
}
