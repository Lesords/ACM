#include<iostream>//ac
#include<cstdio>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//�ӵ㣺�������ֵ�ʱ��Ҫ�����˸��ţ�����

const int MAXN = 1e3+5;
int tree[MAXN],n,m;
map<int,int> pa;//pa�����Ӧֵ�����е�λ��
void update(int dot) {//���ϵ���
    while(dot!=1) {//��Ϊ�������
        if(tree[dot]<tree[dot/2]) {//����С�ڸ��ڵ��򽻻��������µ�ǰ�ڵ�
            swap(tree[dot],tree[dot/2]);
            dot /= 2;
        }
        else return ;//����ֱ�ӽ���
    }
}
bool check(string s) {//�жϵ�ǰ�ַ����Ƿ�Ϊ����
    for(int i = 0;i < (int)s.size();i++) {
        //���ţ��޾޾���Ҫ������
        if(s[i]>='0'&&s[i]<='9'||s[i]=='-') continue;
        else return 0;
    }
    return 1;
}
int to_num(string s) {//���ַ���ת��Ϊ����
    int ans = 0,st = 0,flag = 0;
    if(s[st]=='-') st++,flag = 1;//���⴦���ŵ����
    for(int i = st;i < (int)s.size();i++) {
        int tmp = s[i]-'0';
        ans = ans*10 + tmp;
    }
    if(flag) ans *= -1;//���и��ţ��ǵø�Ϊ����
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>tree[i];
        update(i);//���ϵ���
    }
    for(int i = 1;i <= n;i++) pa[tree[i]] = i;//��¼��ǰ�ڵ�ֵ��λ��
    getchar();//������ĩ�ո�
    for(int i = 1;i <= m;i++) {
        string s,tmp;
        int a = 0,b = 0,mode = 0,flag = 0;
        getline(cin,s);//ÿ��ֱ�Ӷ�ȡһ��
        stringstream ss(s);
        while(ss>>tmp) {//ÿ���ж϶��ж�һ�ĵ���
            if(tmp=="root") mode = 1;
            else if(tmp=="siblings") mode = 2;
            else if(tmp=="parent") mode = 3;
            else if(tmp=="child") mode = 4;
            if(check(tmp)) {//tmpΪ����
                if(!flag) a = to_num(tmp),flag = 1;//flagΪ0��ֵ��a������Ϊb
                else b = to_num(tmp);
            }
        }
        //���ݶ�Ӧ��Ӧģʽ�жϼ���
        if(mode==1) cout<<((a==tree[1])?"T\n":"F\n");//�жϵ�ǰ���Ƿ�Ϊ��
        else if(mode==2) cout<<((pa[a]/2==pa[b]/2)?"T\n":"F\n");//�ж������ڵ��Ƿ�Ϊ�ֵܽڵ�
        else if(mode==3) cout<<((pa[b]/2==pa[a])?"T\n":"F\n");//�ж�a�Ƿ�Ϊb�ĸ��ڵ�
        else if(mode==4) cout<<((pa[a]/2==pa[b])?"T\n":"F\n");//�ж�b�Ƿ�Ϊa�ĸ��ڵ�
    }
    return 0;
}
