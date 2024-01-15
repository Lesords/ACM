#include<iostream>//ac
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,int> num;//统计每个字符串出现的次数
int main() {
    int n;
    cin>>n;
    while(n--) {
        string tmp;
        cin>>tmp;
        if(num.count(tmp)) {//若出现过
            //输出原字符串和出现次数
            cout<<tmp<<num[tmp]<<"\n";
        }
        else cout<<"OK\n";
        num[tmp]++;//数量++
    }
    return 0;
}
