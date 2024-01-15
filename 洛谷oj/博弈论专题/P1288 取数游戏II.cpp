#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：博弈
//对于当前位置而言，每次将对应的一条边置为0，那么下一个人只能被迫往前置零
//因为如果没有置0的话，上一个人可以返回置零，使得下一个人必败
//也就是说每次的最优操作都会将对应边置零
//那么对于先手来说，可以判断到达0的边有几条，若为奇数，则必胜，否则必败
//由于是环形，所以两个方向都要判断
//如果有一个方向为奇数的话，那么一直往这个方向走，下一个人即为被动状态
//则当前必胜

int a[25];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    int right = 0,left = 0;
    //right记录顺时针走的话到达0的次数
    for(int i = 1;i <= n;i++) {
        if(a[i]==0) break;
        right++;
    }
    //left记录逆时针走的话，到达0的次数
    for(int i = n;i >= 1;i--) {
        if(a[i]==0) break;
        left++;
    }
    //只要两个方向有一个为奇数，则必胜
    if(left%2||right%2) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
