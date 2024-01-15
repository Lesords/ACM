#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//题解：博弈论
//当数字为1时，先手必败
//当数字为2时，先手必胜（删除一个1，剩余1）
//当数字为奇数时，先手必胜（直接除以本身，剩余1）
//当数字为偶数时，区分两种情况：（没有奇因子的偶数先手必败！！！）
// 因为此时，只有-1的操作，导致对手有一个必胜的奇数
//包含奇数因子并且除的结果不为2，先手必胜（除去所有奇因子，剩余一个必败的偶数）
//其他，先手必败（有2则败了，没有奇因子也败了）

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n==1) cout<<"FastestFinger\n";
        else if(n==2||n%2) cout<<"Ashishgup\n";
        else {
            int flag = 0;
            for(int i = 2;i <= (int) sqrt(n);i++) {//寻找奇因子，并且另一个不为2
                if(n%i) continue;//跳过不是因子的数
                if(i%2&&(n/i)!=2) {//当前为奇数，并且另一个不为2
                    flag = 1;break;
                }
                if((n/i)%2&&i!=2) {//另一个为奇数，当前不为2
                    flag = 1;break;
                }
            }
            if(flag) cout<<"Ashishgup\n";//找到了先手胜利
            else cout<<"FastestFinger\n";
        }
    }
    return 0;
}
