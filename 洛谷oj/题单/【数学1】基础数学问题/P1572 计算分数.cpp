#include<iostream>//ac
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

//��⣺�ַ���ģ��
//�ȸ��� / �ַ��ָ�����еķ���
//�ٸ��� + �� - �ַ��ָ�����еķ�ĸ
//��Ҫ�������һλ
//���ñ���mark���ж����ֵķ��ţ�������ֵ�ʱ��ǵó�mark
//Ȼ��ͨ��
//�������з�ĸ������С��������Ȼ����� ��С������/��ĸ*���� ���

vector<int> up,down;                            //up�Ǵ洢���ӣ�down�洢��ĸ
int gcd(int a,int b) {                          //���Լ��
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b) {                          //��С������
    return a*b/gcd(a,b);
}
int main() {
    string s;
    cin>>s;
    int tmp = 0,mark = 1;                       //tmpΪ��ǰ����ֵ��markΪ���ķ���
    int len = s.size();
    for(int i = 0;i < len;i++) {
        if(isdigit(s[i])) {                     //��Ϊ���֣�ֱ�Ӳ���
            tmp = tmp*10 + s[i]-'0';
        }
        else {
            if(s[i]=='/') {                     //���ţ�˵��ǰ�����Ϊ����
                up.push_back(tmp*mark);
                mark = 1;                       //�������ʼ��Ϊ1����
            }
            else if(s[i]=='-') {                //��Ϊ������˵��ǰ��Ϊ��ĸ���ҽ������ķ�����Ϊ-1
                down.push_back(tmp*mark);
                mark = -1;
            }
            else if(s[i]=='+') {                //��Ϊ������˵��ǰ��ҲΪ��ĸ
                down.push_back(tmp*mark);
                mark = 1;                       //�������ʼ��Ϊ1����
            }
            tmp = 0;
        }
        if(i==len-1) {                          //����ĩβ���
            down.push_back(tmp*mark);
        }
    }
    int sumDown = 1;
    for(auto v:down) sumDown = lcm(sumDown,v);  //������С������
    int sumUp = 0;                              //�ۼӷ��ӵ�ֵ
    for(int i = 0;i < down.size();i++) {
        sumUp += sumDown/down[i]*up[i];
    }
    tmp = gcd(sumDown,sumUp);                   //��¼���Ӻͷ�ĸ֮���Ƿ��й�����
    if(sumDown/tmp==1) {                        //��ĸΪ1��ֻ��Ҫ������ӣ�����
        cout<<sumUp/tmp;
    }
    else if(sumDown/tmp<0) {                    //����ĸΪ���������Ƶ�ǰ�棡����
        cout<<"-"<<sumUp/tmp<<"/"<<-1*sumDown/tmp;
    }
    else cout<<sumUp/tmp<<"/"<<sumDown/tmp;     //����ֱ�����
    return 0;
}
