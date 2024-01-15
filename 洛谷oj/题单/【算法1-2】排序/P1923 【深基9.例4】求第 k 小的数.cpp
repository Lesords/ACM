#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：利用快速排序思想来求第k的问题
//由于题目中的排序从0开始，所以可以给排名+1，方便计算！！！

const int MAXN = 5e6+5;
int a[MAXN],n,k;
inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}
//数组从左到右升序，基准数取中间位置（取左边会MLE，递归次数过多）
int solve(int left,int right,int k) {           //在[left,right]区间内找第k小值
    int val = a[(left+right)/2];                //基准值
    int l = left,r = right;
    while(l<=r) {                               //相等情况，还需要判断，比如在val值的位置
        while(a[r]>val) r--;                    //寻找右区间小于等于val的位置
        while(a[l]<val) l++;                    //寻找左区间大于等于val的位置
        if(l<=r) {                              //存在两个位置
            swap(a[l],a[r]);                    //交换，并移动对应位置
            l++,r--;
        }
    }
    // left r l right
    if(k<=r) {                                  //第k小在左区间，记得等号！！！
        return solve(left,r,k);
    }
    else if(k>=l) {                             //第k小在右区间，记得等号！！！
        return solve(l,right,k);
    }
    else return a[k];                           //直接根据下标输出值
}
int main() {
    re(n),re(k);                                //快读
    for(int i = 1;i <= n;i++) {                 //从1开始记录
        re(a[i]);
    }
    printf("%d", solve(1,n,k+1));               //细节：排名k+1！！！
    return 0;
}
