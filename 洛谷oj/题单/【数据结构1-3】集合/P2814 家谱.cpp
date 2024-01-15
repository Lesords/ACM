#include<iostream>//ac
#include<cstdio>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

//��⣺����map���ַ���ת�������֣�Ȼ����в��鼯����

const int MAXN = 5e4+5;
int dis[MAXN],num;      //dis��¼���ȣ�numΪ�ַ������
map<string,int> id;     //���ַ���תΪ����
map<int,string> name;   //������תΪ�ַ���
int getf(int pos) {     //Ѱ�����ȣ�·��ѹ��
    return dis[pos]==pos?pos:dis[pos]=getf(dis[pos]);
}
void Merge(int a,int b) {//�ϲ�������a������
    a = getf(a),b = getf(b);
    if(a!=b) {
        dis[b] = a;
    }
}
int main() {
    for(int i = 1;i < MAXN;i++) dis[i] = i;//��ʼ������Ϊ����
    string s,fa;
    char op;
    //�ո���ĩβ�س�
    while(scanf(" %1c",&op)&&op!='$') {     //$Ϊ������
        cin>>s;
        //�µ��ַ���������Ӷ�Ӧ��Ϣ
        if(id.find(s)==id.end()) id[s] = ++num,name[num] = s;
        if(op=='#') {                       //�������ȵ��ַ���
            fa = s;
        }
        else if(op=='+') {                  //�����ӽڵ�ϲ������ڵ�
            Merge(id[fa],id[s]);
        }
        else {
            int fa = getf(id[s]);           //��ѯid[s]�����ȣ�����ֱ��dis����Ѱ�ң�����
            cout<<s<<" "<<name[fa]<<"\n";   //�������ȵ�id����ַ���
        }
    }
    return 0;
}
