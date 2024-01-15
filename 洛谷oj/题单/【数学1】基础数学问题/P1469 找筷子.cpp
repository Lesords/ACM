#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：根据 a^a = 0, 0^a = a
//并且异或满足交换律
//所以对于相同高度的筷子，异或的结果为0
//那么将所有筷子异或，最后的值即为落单的筷子
//因为成双的筷子异或和为0

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//加速
    int n,tmp,ans = 0;//初始化为0
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp;
        ans ^= tmp;//与所有数异或
    }
    cout<<ans;
    return 0;
}
