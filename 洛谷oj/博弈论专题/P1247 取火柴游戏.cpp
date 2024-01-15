#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：NIM博弈，结论是所有数的异或为0位必败态
//那么对于必胜态的操作是将其中数的值改为 异或值^当前值
//使得整个异或值为：原来的异或值 ^ 修改后的异或值 = 0
//例：5^3 = 6
//修改为 5^6 ^ 3 = 0，也就是将原来的5改为5^6，即3

const int MAXN = 5e5+5;
int a[MAXN],ans;//ans记录最后的异或结果
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        ans ^= a[i];//异或所有数求值
    }
    if(ans==0) {//异或值为0，则是必败态
        cout<<"lose\n";
        return 0;
    }
    for(int i = 1;i <= n;i++) {//判断所有数，选择一个异或后值会小于当前数的即可
        if((ans^a[i])<a[i]) {//注意括号！！！
            //原来的为a[i]，需要的为ans^a[i]，差值即为拿走的值
            cout<<a[i]-(ans^a[i])<<" "<<i<<"\n";
            for(int j = 1;j <= n;j++) {
                if(j!=i) cout<<a[j]<<" ";
                else cout<<(ans^a[j])<<" ";//为当前数，则修改为操作后的值
            }
            break;//直接结束
        }
    }
    return 0;
}
