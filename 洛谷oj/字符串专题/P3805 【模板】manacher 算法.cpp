#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺�������������Ĵ�

const int MAXN = 11e6 + 5;
char s[MAXN], ma[MAXN*2];
int mp[MAXN*2];//mp[i] Ϊ��s���Զ�Ӧλ��Ϊ���ĵļ����ӻ��Ĵ����ܳ���+1
int Manacher(char *s, int siz){//sizΪ�ַ�������
    int len = 0;
    ma[len++] = '$'; ma[len++] = '#';
    for(int i = 0;i < siz;i++){
        ma[len++] = s[i];
        ma[len++] = '#';
    }
    ma[len] = 0;//ĩβΪ���ַ�
    int mx = 0, id = 0;//idΪ�ֲ������Ĵ����ĵ㣬mxΪ�ұ߽�
    int res = 0;
    for(int i = 0;i < len;i++) {
        //���ڶ���i�ĶԳƵ�j��jС����˵��id - j = i - id �Ƴ� j = 2id-i
        mp[i] = mx > i ? min(mp[2*id-i], mx - i) : 1;
        while(ma[i+mp[i]] == ma[i-mp[i]]) mp[i]++;//����ö��
        if(i + mp[i] > mx) {//���¾ֲ������Ĵ�
            mx = mp[i] + i;
            id = i;
        }
        res = max(res, mp[i] - 1);
        //mp[i]Ϊ�󲿷ִ�С�����ǰ�����#������������#������ԭ�ַ����࣬������-1
    }
    return res;
}

int main() {
    cin>>s;
    int len = strlen(s);
    cout<<Manacher(s, len);
    return 0;
}
