#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//��⣺�������⽨�ߣ����Ҽ�¼���
//���Ϊ0�ĵ㼴Ϊ����Ȼ��˳�Ÿ�����ǰ���������

char s[5],tree[30];//tree��¼���ڵ��ֵ
int l[50],r[30],vis[30],in[30];//l��r�ֱ�Ϊ���Ҷ��ӣ�vis��¼���ֵ��ַ���in��¼���
int idx(char ch) {
    return ch-'a'+1;//��Ŵ�1��ʼ����ֹ���У����Ҷ���Ϊ0��ʾ����Ϊ�գ�����
}
char chx(int id) {
    return id+'a'-1;//ת�ַ���-1
}
void preorder(int rt) {//ǰ�����
    cout<<chx(rt);
    if(l[rt]) {
        preorder(l[rt]);
    }
    if(r[rt]) {
        preorder(r[rt]);
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>s;
        vis[idx(s[0])] = 1;//��ʾ��ǰ�ַ�
        if(s[1]!='*') {//����������ӣ����¼��Ӧ��Ϣ
            vis[idx(s[1])] = 1;
            l[idx(s[0])] = idx(s[1]);//�����
            in[idx(s[1])]++;//���
        }
        if(s[2]!='*') {//�������Ҷ��ӣ����¼��Ӧ��Ϣ
            vis[idx(s[2])] = 1;
            r[idx(s[0])] = idx(s[2]);//�Ҷ���
            in[idx(s[2])]++;//���
        }
    }
    int rt = -1;//rt����ı��
    for(int i = 0;i < 26;i++) {//Ѱ�Ҹ��ı��
        if(vis[i]&&in[i]==0) {//���ڵ��ַ����������Ϊ0
            rt = i;break;
        }
    }
    preorder(rt);
    return 0;
}
