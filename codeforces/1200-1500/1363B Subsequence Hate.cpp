#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��������ҪôΪǰ��1����0��ҪôΪǰ��0����1����1100,0011��
//��ô�����ȼ�¼һ��1��������0������
//Ȼ���ڱ���һ���ַ�������������Ϊ01�ĺ�׺���������ټ�¼һ��ǰ׺����
//Ȼ�����10��01�����������Сֵ���κ�һ��λ�ö���Ϊ01�ķָ�㣩

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int one = 0,zero = 0;
        for(int i = 0;i < s.size();i++) {//����01������
            if(s[i]=='1') one++;
            else zero++;
        }
        int ans = INF,pre1 = 0,pre0 = 0;//�𰸣�01��ǰ׺����
        for(int i = 0;i < s.size();i++) {
            if(s[i]=='1') pre1++,one--;//��ǰΪ1��1��ǰ׺���ӣ���׺����
            if(s[i]=='0') pre0++,zero--;//��ǰΪ0��0��ǰ׺���ӣ���׺����
            ans = min(ans, pre0+one);//10
            ans = min(ans, pre1+zero);//01
        }
        cout<<ans<<"\n";
    }
    return 0;
}
