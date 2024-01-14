#include<iostream>//ac
#include<stack>
#include<algorithm>
using namespace std;

//倒着25进制造字符串

int main() {
    int l,n;
    cin>>l>>n;
    //最低位从z开始，z代表1
    //其他位从y开始，y代表1，z代表0
    n -= 1;//所以需减1，巨关键！！！
    stack<int> num;
    for(int i = 1;i <= l;i++) {//共l个字符
        int tmp = n%26;
        num.push(tmp);
        n /= 26;//26进制
    }
    while(!num.empty()) {
        char ch = 'z'-num.top();
        cout<<ch;
        num.pop();
    }
    return 0;
}
