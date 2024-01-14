#include<iostream>//ac
#include<cmath>
#include<deque>
#include<algorithm>
using namespace std;

//题解：利用两个双端队列维护数据
//一个维护从左边进入的数值，一个维护从右边进入的数值
//每次删除操作，只需要将对应的值标记为-1，到时候查询的时候可弹出被删除的值（类似lazy标记
//由于需要取中间偏右位置的值
//例如：若有4个数字，取第三个（2+2，偏右即为3）
//      若为5个数字，取第三个（2+1+2，左右距离一致）
//分析：
//1. 如果我们令 左队列最后一个 为中心
//对于4个数字来说，左边队列需要3个，右边队列需要1个，此时左边队列末尾满足条件
//对于5个数字来说，左边队列需要3个，右边队列需要2个，此时左边队列末尾满足条件
//也就是说两个队列的差值可为2，也可为1（不好确定）
//2. 如果我们令 右队列第一个 为中心点
//对于4个数字来说，左边队列需要2个，右边队列需要2个，此时右边队列队首满足条件
//对于5个数字来说，左边队列需要2个，右边队列需要3个，此时右边队列队首满足条件
//也就说，右边队列的大小需要大于等于左边队列
//该方案可行

//例：1,4     2,3     3,2
//    1,3     2,2     3,1
//观察样例可有：
//1. 当左右两边大小相同，直接返回
//2. 当左边大于右边时，将左边的队尾移到右边的队首，直到左边不大于右边
//3. 当左边小于（右边-1）时，将右边队首移到左边队尾，直到左边不小于（右边-1）

const int MAXN = 1e7+5;
deque<int> Left,Right;//右边队首即为中心点
int a[MAXN];//记录对应值在哪个队列中（1为左边，2为右边，-1表示删除了）
int lnum, rnum;//记录左右队列的大小
void adjust() {
    if(lnum==rnum) return ; //1. 两个大小相同
    while(lnum>rnum) {      //2. 左边大于右边
        int lback = Left.back();//将左边队尾放入右边队首
        Left.pop_back();
        if(a[lback]==-1) continue;//被删除了，跳过
        lnum--;//更新对应的数量
        rnum++;
        a[lback] = 2;//更新位置
        Right.push_front(lback);
    }
    while(lnum<rnum-1) {    //3. 左边小于（右边-1）
        int rfront = Right.front();//将右边队首放入左边队尾
        Right.pop_front();
        if(a[rfront]==-1) continue;//被删除了，跳过
        lnum++;//更新对应数量
        rnum--;
        a[rfront] = 1;//更新位置
        Left.push_back(rfront);
    }
}
int main() {
//    freopen("data/input.txt", "r", stdin);
//    freopen("data/out.txt", "w", stdout);
    int q,val = 0;
    scanf("%d", &q);
    while(q--) {
        char op;
        scanf(" %c", &op);
        if(op=='L') {
            Left.push_front(++val);
            lnum++;//更新对应数量，即位置
            a[val] = 1;
            adjust();//调整
        }
        else if(op=='R') {
            Right.push_back(++val);
            rnum++;//更新对应数量，即位置
            a[val] = 2;
            adjust();//调整
        }
        else if(op=='G') {
            int x;
            scanf("%d", &x);
            if(a[x]==1) lnum--;//对应位置的队列数量--
            else if(a[x]==2) rnum--;
            a[x] = -1;//标记为-1（被删除）
            adjust();//调整
        }
        else {
            //右边队首即为结果
            //但是如果右边队首为-1（被删除），则需要弹出
            while(a[Right.front()]==-1) Right.pop_front();
            printf("%d\n", Right.front());
        }
    }
    return 0;
}
