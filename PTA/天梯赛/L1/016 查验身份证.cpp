#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int val[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//权值
char num[20] = {'1','0','X','9','8','7','6','5','4','3','2'};//模值对应的校验码
int main() {
    int n,flag = 1;//flag判断是否有错的
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        int ans = 0;
        for(int i = 0;i < 17;i++) {
            int tmp = s[i] - '0';
            ans += tmp*val[i];//计算权值和
        }
        if(num[ans%11]==s[17]) continue;//判断是否等于后一位校验码
        cout<<s<<"\n";
        flag = 0;//0表示有错误
    }
    if(flag) cout<<"All passed\n";//没错的情况
    return 0;
}
