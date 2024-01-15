#include<iostream>//ac
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

//题解：找规律，会发现从上往下第一个b的位置对应的数量为1 - 2 - 3 - 4 - n-1
//第二个b为从低位开始构造
//所以可以先判断当前处在哪个块来判断第一个b的位置，然后再判断第一个b的位置

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        string s(n,'a');//初始化为n个a
        for(int i = 1;i <= n-1;i++) {//判断在哪个分块 最多n-1个
            if(k<=i) {//在当前范围内
                s[n-1-i] = 'b';//第一个b的位置（后面空i个）
                s[n-k] = 'b';//第二个b的位置为 从低位开始数第k个
                cout<<s<<"\n";
                break;
            }
            else k -= i;//否则删除当前块的大小
        }
    }
    return 0;
}
