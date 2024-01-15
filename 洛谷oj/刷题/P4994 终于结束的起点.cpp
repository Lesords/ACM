#include<iostream>//ac （暴力）
using namespace std;
int main() {
    int m,one,two,now;
    cin>>m;
    one = two = 1;//第一个数，第二个数，第三个数
    for(int i = 3;;i++) {
        now = (one+two)%m;//当前数为前两个相加（取模）
        if(two%m==0&&now%m==1) {//前0后1
            cout<<i-1<<endl;//判断的是前一个位置
            return 0;
        }
        one = two;two = now;//更新数字
    }
}
