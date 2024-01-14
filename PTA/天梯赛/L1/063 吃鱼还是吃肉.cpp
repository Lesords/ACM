#include<iostream>//ac
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int sex,hei,wei,shei,swei;//shei为标准身高，swei为标准体重
        cin>>sex>>hei>>wei;
        if(sex) shei = 130,swei = 27;
        else shei = 129,swei = 25;
        if(hei>shei) cout<<"ni li hai!";//先判身高
        else if(hei<shei) cout<<"duo chi yu!";
        else cout<<"wan mei!";
        if(wei>swei) cout<<" shao chi rou!\n";//后判体重
        else if(wei<swei    ) cout<<" duo chi rou!\n";
        else cout<<" wan mei!\n";
    }
    return 0;
}
