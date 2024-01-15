#include<iostream>//ac
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int n,ans,vis[25];//vis������¼��Ӧ���ַ������˼���
string s[25];
int check(string a,string b) {//����a��b���ظ���������������ȡС��
    //�ж��ظ�������a�ĺ�׺��b��ǰ׺�Ƚ�
    int siz = a.size()-1;//���ܰ���������ɾ��һ���ַ�
    a.erase(0,1);
    int ans = INF;//��ʼ��ΪINF
    while(siz--) {//����ʣ�����к�׺�ж��Ƿ����ظ���
        int op = 1;//1Ϊ���ظ���0Ϊ���ظ�
        for(int i = 0;i < a.size();i++) {//ֻ�ж�a�Ĵ�С����
            if(a[i]!=b[i]) {//��һ����ͬ��opΪ0
                op = 0;break;
            }
        }//�ظ���СΪ��Ӧa�Ĵ�С
        if(op) ans = min(ans,int(a.size()));//���ظ���ȡС������
        a.erase(0,1);//ɾ�����ַ���������һ����׺ƥ��
    }
    if(ans==INF) return 0;//ΪINF˵��û���ظ���
    return ans;//�����ظ��Ĵ�С
}
void dfs(string now,int len) {//nowΪ��ǰ��Ҫ�������ַ�����lenΪ���ַ�������
    for(int i = 1;i <= n;i++) {
        //�����ַ�������ͬ��ֻҪ��ѭ���ڣ�����
        if(vis[i]>=2||!check(now,s[i])) continue;//�������λ����ظ�
        int siz = s[i].size()-check(now,s[i]);//��ǰ�ж��ַ���-�ظ��ַ�����Ϊ������
        if(!siz) continue;//������ͬ���ַ�
        ans = max(ans,len+siz);//����ans
        vis[i]++;//����++
        dfs(s[i],len+siz);//�����ӵ�ǰ�ַ���dfs������len����
        vis[i]--;//���ݣ�����--
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>s[i];
    char start;
    cin>>start;//Ϊ�����ַ�
    for(int i = 1;i <= n;i++) {//���������ַ�
        if(s[i][0]!=start) continue;//��Ϊstart������
        vis[i]++;//��ǰ����++
        ans = max(ans,int(s[i].size()));//����ans�Ĵ�С
        dfs(s[i],s[i].size());
        vis[i]--;//���ݣ�����--
    }
    cout<<ans<<endl;
    return 0;
}
