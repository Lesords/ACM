#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：先后判断用偶数和奇数来判断是否可以组成n
//偶数（前面都为2+剩余值）：总和必须为偶数，且n/2的数量必须大于k
//奇数（前面都为1+剩余值）：总和必须大于k，且(n-k)必须为偶数（这样才能都为奇数）

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(n%2==0&&n/2>=k) {//偶数必须判断总和是否为偶数
            cout<<"YES\n";
            for(int i = 1;i < k;i++) cout<<"2 ";
            cout<<n-(k-1)*2<<"\n";//计算最后一个剩余值
        }
        else if(n>=k&&(n-k)%2==0) {//奇数不需要判断 n 的余数！！！
            cout<<"YES\n";
            for(int i = 1;i < k;i++) cout<<"1 ";
            cout<<n-(k-1)<<"\n";//计算最后一个剩余值
        }
        else cout<<"NO\n";
    }
    return 0;
}
