#include<iostream>//ac
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;

//题解：先将所有相邻的异形队列入队列
//然后每次选择队列首的值，然后标记选中的人
//接着将当前选中的人向两边寻找可以相邻的人（去除当前位置后，即可相邻）

const int MAXN = 2e5+5;
struct node{
    int cha,x,y;
    friend bool operator < (node a,node b) {
        if(a.cha!=b.cha) return a.cha > b.cha;//先根据差从小到大排序
        return a.x > b.x;//然后根据最小值x，从小达到排序
    }
};
int a[MAXN],ansA[MAXN],ansB[MAXN],in[MAXN];//in为当前位置是否被选中
char gen[MAXN];//记录性别
priority_queue<node> q;//优先队列
int main() {
    int n,num = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>gen[i];
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(i!=1&&gen[i]!=gen[i-1]) {//相邻的异性入队
            q.push({abs(a[i]-a[i-1]), i-1,i});//差，较小位置，较大位置
        }
    }
    while(!q.empty()) {//不为空，即还有组合
        int x = q.top().x;
        int y = q.top().y;
        q.pop();//记得出队
        if(in[x]||in[y]) continue;//若有一个已选中，则跳过
        num++;//数量++
        ansA[num] = x;
        ansB[num] = y;//记录对应位置
        in[x] = in[y] = 1;//标记为已选中
        while(x>=1&&in[x]) x--;//x往左寻找第一个未被选中的人
        while(y<=n&&in[y]) y++;//y往右寻找第一个未被选中的人
        if(x<1||y>n) continue;//越界，则跳过
        //判断性别是否不同！！！
        if(gen[x]!=gen[y]) q.push({abs(a[x]-a[y]),x,y});//继续入队
    }
    cout<<num<<"\n";
    for(int i = 1;i <= num;i++) {
        cout<<ansA[i]<<" "<<ansB[i]<<"\n";
    }
    return 0;
}
