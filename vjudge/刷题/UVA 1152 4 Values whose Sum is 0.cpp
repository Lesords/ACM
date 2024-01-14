#include<iostream>//ac  哈希表
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

//题解：利用哈希存储A+B的所有组合值，然后计算-C-D的数量，累加即为答案

const int MAXN = 4e3+5;
const int hashsize = 1e6+3;
struct node{
    int a,b,c,d;
}val[MAXN];//存储对应四个值
int head[hashsize],nextt[MAXN*MAXN+10],res[MAXN*MAXN+10],num[MAXN*MAXN+10],cnt;
//head存储对应值的的表头下标, nextt存储的是下一个位置的值的下标
//res表示存储值的大小，num存储对应值出现的数量，cnt为对应的下标
int Hash(int val) {//取模值
    return (val+hashsize)%hashsize;
}
void hash_insert(int val) {//添加操作
    int h = Hash(val);//取哈希值
    int to = head[h];//取表头值（数组下标）
    while(to) {//0为无数据了
        if(res[to]==val) {//若与当前值一致，则结束
            num[to]++;
            return ;
        }
        to = nextt[to];//指向下一个位置
    }
    nextt[cnt] = head[h];//更新链表
    head[h] = cnt;//更新表头
    res[cnt] = val;//不存在当前值，需添加
    num[cnt++] = 1;//新的数量为1
}
int hash_find(int val) {//查询操作
    int h = Hash(val);//取哈希值
    int to = head[h];//对应表头
    while(to) {
        if(res[to]==val) return num[to];//找值
        to = nextt[to];
    }
    return 0;//不存在即为0
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,flag = 0;
    cin>>t;
    while(t--) {
        int n,ans = 0;cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>val[i].a>>val[i].b>>val[i].c>>val[i].d;
        }
        memset(head,0,sizeof(head));//初始化两个数组
        memset(nextt,0,sizeof(nextt));
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++)
                hash_insert(val[i].a+val[j].b);//插入操作
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                //直接可查询结果
                ans += hash_find(-val[i].c-val[j].d);
            }
        }
        if(flag) cout<<"\n";
        flag = 1;
        cout<<ans<<"\n";
    }
    return 0;
}
