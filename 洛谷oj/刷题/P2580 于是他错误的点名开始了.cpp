#include<iostream>//ac
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

//��⣺�ֵ���ģ���⣬����set���ж��Ƿ��ظ�����
//trie��������ֵ����ڵ����Ϣ
//End������ǵ�ǰ�Ľڵ��Ƿ�Ϊһ���ַ���
//cntΪ�ڵ�ı��
//trie�ĳ��ȼ���Ϊ N*str(s) Ҳ���� �ַ�������*�ַ������ȣ�ÿ���ַ���Ϊһ���ڵ㣩

const int MAXN = 5e5+5;
int trie[MAXN][26],End[MAXN],cnt;//trie�Ĵ�С������
set<string> st;//��������
void Insert(string tmp) {//���tmp����Ϣ���ֵ�����
    int p = 1;//��ʼ�ڵ�Ϊ1
    for(int i = 0;i < tmp.size();i++) {//���������ַ�
        char ch = tmp[i];
        if(trie[p][ch]==0) trie[p][ch] = ++cnt;//��ǰ�ڵ㲻��������
        p = trie[p][ch];//�ƶ��ڵ�λ��
    }
    End[p] = 1;//pλ�ô����ַ���
}
int Find(string tmp) {//�ж�tmp�ַ����Ƿ����
    int p = 1;
    for(int i = 0;i < tmp.size();i++) {//���������ַ�
        char ch = tmp[i];
        if(trie[p][ch]==0) return 0;//��ǰ�ڵ㲻�����򷵻�0
        p = trie[p][ch];
    }
    return End[p];//Ϊ1��ʾ���ڣ�0��ʾ������
}
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        Insert(tmp);//��tmp��ӵ��ֵ�����ȥ
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        string tmp;
        cin>>tmp;
        int ok = Find(tmp);//�ж�tmp�ַ���
        if(ok&&st.find(tmp)==st.end()) {
            cout<<"OK\n";
            st.insert(tmp);
        }
        else if(ok==0) {//tmp������
            cout<<"WRONG\n";
        }
        else if(st.find(tmp)!=st.end()) {//�ظ���
            cout<<"REPEAT\n";
        }
    }
    return 0;
}
