#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int main() {
    int n;cin>>n;
    while(n--) {
        string tmp;
        cin>>tmp;
        int num1 = 0,num2 = 0;
        for(int i = 0;i < 3;i++) num1 += tmp[i]-'0';//����ǰ��λ
        for(int i = 3;i < 6;i++) num2 += tmp[i]-'0';//�������λ
        //�ж��Ƿ����
        cout<<((num1==num2)?"You are lucky!\n":"Wish you good luck.\n");
    }
    return 0;
}
