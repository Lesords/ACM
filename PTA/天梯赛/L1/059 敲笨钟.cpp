#include<iostream>//ac
#include<cstdio>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    getchar();
    while(n--) {
        string s;
        getline(cin,s);
        int num = 0;
        //找到逗号和句号，然后判断前三个字符是否为“ong"即可
        for(int i = 0;i < (int)s.size();i++) {
            if(s[i]==','||s[i]=='.') {
                string tmp = "";
                for(int j = i-3;j <= i-1;j++) tmp += s[j];
                if(tmp=="ong") num++;
            }
        }
        if(num!=2) cout<<"Skipped\n";//没有都为“ong”，则跳过
        else {
            int pos = 0,num = 0;
            for(int i = (int)s.size()-1;i >= 0;i--) {//倒着找到第三个空格的位置
                if(s[i]==' ') num++;
                if(num==3) {//pos为倒三个空格的位置
                    pos = i;break;
                }
            }//然后输出这段位置的所有字符，最后补上对应字符串即可
            for(int i = 0;i <= pos;i++) cout<<s[i];
            cout<<"qiao ben zhong.\n";
        }
    }
    return 0;
}
