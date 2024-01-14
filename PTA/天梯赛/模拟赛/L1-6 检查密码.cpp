#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
bool is_right(string tmp) {
    for(int i = 0;i <    (int) tmp.size();i++) {
        if(tmp[i]>='0'&&tmp[i]<='9') continue;
        if(tmp[i]>='a'&&tmp[i]<='z') continue;
        if(tmp[i]>='A'&&tmp[i]<='Z') continue;
        if(tmp[i]=='.') continue;
        return 1;
    }
    return 0;
}
int main() {
    int n;
    cin>>n;
    getchar();
    string tmp;
    for(int i = 1;i <= n;i++) {
        getline(cin,tmp);
        if(tmp.size()<6) cout<<"Your password is tai duan le.\n";
        else if(is_right(tmp)) cout<<"Your password is tai luan le.\n";
        else {
            int num = 0,alp = 0;
            for(int i = 0;i < (int)tmp.size();i++) {
                if(tmp[i]>='0'&&tmp[i]<='9') num++;
                if(tmp[i]>='a'&&tmp[i]<='z') alp++;
                if(tmp[i]>='A'&&tmp[i]<='Z') alp++;
            }
            if(num&&!alp) cout<<"Your password needs zi mu.\n";
            else if(!num&&alp) cout<<"Your password needs shu zi.\n";
            else cout<<"Your password is wan mei.\n";
        }
    }
    return 0;
}
