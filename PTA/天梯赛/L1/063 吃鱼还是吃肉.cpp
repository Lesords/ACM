#include<iostream>//ac
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int sex,hei,wei,shei,swei;//sheiΪ��׼��ߣ�sweiΪ��׼����
        cin>>sex>>hei>>wei;
        if(sex) shei = 130,swei = 27;
        else shei = 129,swei = 25;
        if(hei>shei) cout<<"ni li hai!";//�������
        else if(hei<shei) cout<<"duo chi yu!";
        else cout<<"wan mei!";
        if(wei>swei) cout<<" shao chi rou!\n";//��������
        else if(wei<swei    ) cout<<" duo chi rou!\n";
        else cout<<" wan mei!\n";
    }
    return 0;
}
