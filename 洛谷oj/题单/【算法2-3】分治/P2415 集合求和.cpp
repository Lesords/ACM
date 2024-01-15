#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

//题解：对于一个大小为n的集合来说，共有2^n个子集
//即：每个元素都有两个选择：选和不选，共n个元素，即为2^n个子集
//那么对于这些子集来说，每个元素选和不选都占1/2
//那么即可以算子集和，然后 乘以2^n 后 除2

int a[50],cnt;
ll ans;
int main() {
    int tmp;
    while(cin>>tmp) {
        a[++cnt] = tmp;
        ans += tmp;
    }
    //因为longlong和double类型相乘时会转换为double类型
    //所以需要显示转换成longlong类型
    cout<<(ll)(ans*pow(2,cnt)/2);
    return 0;
}
