#include<iostream>//ac
using namespace std;
int main() {
    int n;
    char ch;
    cin>>n>>ch;
    for(int i = 1;i <= (n+1)/2;i++) {//������������!!!
        for(int j = 1;j <= n;j++) cout<<ch;
        cout<<"\n";
    }
    return 0;
}
