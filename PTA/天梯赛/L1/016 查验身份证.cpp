#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;
int val[20] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};//Ȩֵ
char num[20] = {'1','0','X','9','8','7','6','5','4','3','2'};//ģֵ��Ӧ��У����
int main() {
    int n,flag = 1;//flag�ж��Ƿ��д��
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        int ans = 0;
        for(int i = 0;i < 17;i++) {
            int tmp = s[i] - '0';
            ans += tmp*val[i];//����Ȩֵ��
        }
        if(num[ans%11]==s[17]) continue;//�ж��Ƿ���ں�һλУ����
        cout<<s<<"\n";
        flag = 0;//0��ʾ�д���
    }
    if(flag) cout<<"All passed\n";//û������
    return 0;
}
