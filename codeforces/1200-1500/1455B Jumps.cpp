#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：每次要么向右跳k，要么向左跳1，所以说必须先跳到>=x的位置，然后再左跳
//那么前几个跳的距离即为 step*(1+step)/2  （等差和公式）
//那么由于差x的位置肯定小于step（否则会再走），所以可以用一次右跳k换左跳1
//那么由于最小的交换为 +1 -> -1，距离为2，所以当距离相差1时还是需要再左跳一次

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x,step = 1;
        cin>>x;
        while((1+step)*step<x*2) step++;//计算右跳次数
        if((1+step)*step/2==x+1) step++;//差距为1的时候需要多左跳一次
        cout<<step<<"\n";
    }
    return 0;
}
