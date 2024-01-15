#include<iostream>//ac
#include<algorithm>
using namespace std;

//题意：每套系统中每发导弹可以拦截小于等于前一个高度的炮弹
//题解：故每套系统可拦截最大的导弹数量即为  最长非递增（小于等于）子序列
//所需的系统数为 最长上升子序列
//n^2的做法可用dp，nlogn的做法为 贪心+二分
//nlogn:
//初始化第一个值的状态
//接着遍历剩余所有元素,判断元素是否满足当前条件，满足则入数组
//不满足则二分对应数组，选择最优的可替换数进行替换

//upper_bound和lower_bound的区别：lower_bound可等于当前值，upper_bound不行

const int MAXN = 1e5+1;
int a[MAXN],up[MAXN],down[MAXN];
bool cmp(int a,int b){//升序数组
    return a>b;
}
int main() {
    int cnt = 0,tmp;
    while(cin>>tmp) a[++cnt] = tmp;
    //计算最长非递增子序列
    int len_down = 1;
    down[len_down] = a[1];//初始长度为1，且值为首值
    for(int i = 2;i <= cnt;i++) {//从第二个开始
        if(a[i]<=down[len_down]) down[++len_down] = a[i];//当前数满足非递增，直接进数组
        else *upper_bound(down+1,down+len_down+1,a[i],cmp) = a[i];//找到第一个小于a[i]的值，并更新
        //值相等可满足条件，所以选择upper_bound
        //cmp的作用是将down数组进行降序二分
    }
    //计算最长上升子序列
    int len_up = 1;
    up[len_up] = a[1];//初始长度为1，且值为首值
    for(int i = 2;i <= cnt;i++) {//从第二个开始
        if(a[i]>up[len_up]) up[++len_up] = a[i];//当前数满足上升，直接进数组
        else *lower_bound(up+1,up+len_up+1,a[i]) = a[i];//找到第一个大于等于a[i]的值，并更新
        //值相等不满足条件（！！！），所以选择lower_bound
    }
    cout<<len_down<<"\n"<<len_up<<"\n";
    return 0;
}
