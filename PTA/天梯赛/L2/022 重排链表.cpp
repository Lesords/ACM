#include<iostream>//ac
#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+1;//用数组比string占用的内存小，两者都可以过
//用string的话可直接输出地址，不需要用printf
struct node{
    int name,val;//记录当前地址和值
};
int data[MAXN],nextt[MAXN],vis[MAXN];//data为当前节点的值，nextt为当前节点的下一个地址
//vis判断当前地址是否有值
vector<node> link;
int main() {
    int head,n;
    scanf("%d%d",&head,&n);
    for(int i = 1;i <= n;i++) {
        int a,b,val;
        scanf("%d%d%d",&a,&val,&b);
        vis[a] = 1;//a地址有值
        data[a] = val;//更新节点的值
        nextt[a] = b;//更新当前节点的下一个地址
    }
    while(vis[head]) {//当前地址有值
        link.push_back(node{head,data[head]});//记录地址和值
        head = nextt[head];//移到下一个位置
    }
    int l = 0,r = link.size()-1,flag = 0;//flag判断当前是否为第一个输出的，1则不是
    //只要不是第一个输出的，都需要多输出地址一次（为上一行输出的下一个地址）
    //其他的每次只需要输出 当前地址 和 值 即可
    while(l<=r) {//还有l==r的情况！！！
        if(l==r) {
            //凡是flag判断的都需要回车符，为上一行的 下一个地址
            if(flag) printf("%05d\n",link[l].name);//注意 %05d
            printf("%05d %d ",link[l].name,link[l].val);
            l++,r--;//巨重要！！！
            //l==r时没有更新，导致一直入队，直到内存超限，换了写法之后为tle！！！
        }
        else {//利用双指针的思想，交替输出
            if(flag) printf("%05d\n",link[r].name);//先大后小
            printf("%05d %d ",link[r].name,link[r].val);
            flag = 1;
            if(flag) printf("%05d\n",link[l].name);
            printf("%05d %d ",link[l].name,link[l].val);
            r--,l++;
        }
    }
    printf("-1");//最后一行的下一个地址一定为 -1
    return 0;
}
