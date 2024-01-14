#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool check(int num) {
    for(int i = 2;i*i <= num;i++) {
        if(num%i==0) return 0;
    }
    return 1;
}
int main() {
    int l,k;
    string s;
    cin>>l>>k>>s;
    int len = s.size();
    for(int i = 0;i < len;i++) {
        if(i+(k-1)>=len) break;
        int num = 0;
        for(int j = i;j <= i+k-1;j++) {
            num = num*10+(s[j]-'0');
        }
        if(check(num)) {
            for(int j = i;j <= i+k-1;j++) cout<<s[j];
            return 0;
        }
    }
    cout<<"404\n";
    return 0;
}
