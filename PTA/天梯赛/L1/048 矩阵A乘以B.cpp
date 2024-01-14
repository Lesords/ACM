#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105][105],b[105][105],c[105][105];
int main() {
    int r1,c1,r2,c2;
    cin>>r1>>c1;
    for(int i = 1;i <= r1;i++) {
        for(int j = 1;j <= c1;j++) cin>>a[i][j];
    }
    cin>>r2>>c2;
    for(int i = 1;i <= r2;i++) {
        for(int j = 1;j <= c2;j++) cin>>b[i][j];
    }
    if(c1!=r2) {//A行不等于B列，则无法运算
        cout<<"Error: "<<c1<<" != "<<r2;
        return 0;
    }
    for(int i = 1;i <= r1;i++) {
        for(int j = 1;j <= c2;j++) {
            for(int k = 1;k <= c1;k++)//共计算k次
                c[i][j] += a[i][k]*b[k][j];
        }
    }
    cout<<r1<<" "<<c2<<"\n";
    for(int i = 1;i <= r1;i++) {
        for(int j = 1;j <= c2;j++) {
            if(j!=1) cout<<" ";
            cout<<c[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
