#include<iostream>//ac
#include<cstring>
#include<bitset>
#include<algorithm>
using namespace std;

//��⣺�ֵ�������Ͳ�ѯ�ַ���
//Ȼ��ÿ�β����������Ľڵ���
//���ݽڵ��������в���
//����bitset����¼��һ�д��ڸ��ַ���

struct Trie {
    static const int SIZE = 2e5+5;
    int nex[SIZE][26], cnt;
    void init() {
        cnt = 0;
        memset(nex, 0, sizeof(nex));
    }
    int insert(char *s, int l) {  // �����ַ���
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) nex[p][c] = ++cnt;  // ���û�У�����ӽ��
            p = nex[p][c];
        }
        return p;//���ص�ǰ�ڵ���
    }
    int find(char *s, int l) {  // �����ַ���
        int p = 0;
        for (int i = 0; i < l; i++) {
            int c = s[i] - 'a';
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return p;//���ص�ǰ�ڵ���
    }
}t;

const int MAX = 5e6+5;
char s[33];
bitset<1001> b[MAX];//���ö�Ӧ�ڵ��Ƿ�����һ�г��ֹ�
int main() {
    t.init();
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        while(tmp--) {
            cin>>s;
            int len = strlen(s);
            b[t.insert(s, len)][i] = 1;//��Ӧ�ڵ��ڵ�i�г��ֹ�
        }
    }
    cin>>m;
    while(m--) {
        cin>>s;
        int len = strlen(s);
        int pos = t.find(s, len);//�ڵ��
        if(pos) for(int i = 1;i <= n;i++) {
            if(b[pos][i]==1) {//���ڣ�������к�
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
