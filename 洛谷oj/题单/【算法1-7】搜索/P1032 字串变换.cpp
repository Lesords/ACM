#include<iostream>//ac
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    string now;//��¼��ǰ�ַ���
    int step;//��¼��ǰ����
    friend bool operator < (node a,node b) {
        return a.step > b.step;//���ݲ�����С������
    }
};
map<string,vector<string> > mp;//�洢��Ӧ�Ӵ�����ת�����ַ�������vector!!!
set<string> vis;//������ǵ�ǰ�ַ���״̬�Ƿ���������ֹtle������
int main() {
    string a,b,tmp1,tmp2;
    cin>>a>>b;
    while(cin>>tmp1>>tmp2) {
        mp[tmp1].push_back(tmp2);//��tmp2����tmp1��Ӧ��vector��
    }
    priority_queue<node> q;
    q.push({a,0});//��ʼ����Ϊaԭ��
    int ans = -1;//��ʼ��Ϊ-1���������Ϊ-1����ʾ�޽�
    while(!q.empty()) {
        node tmp = q.top();q.pop();
        if(tmp.now==b) {//�ѵ���Ŀ�Ĵ�������´𰸣�����
            ans = tmp.step;break;
        }
        if(vis.count(tmp.now)) continue;//�жϵ�ǰ�ַ����Ƿ������
        else vis.insert(tmp.now);
        int len = tmp.now.size();//��¼��ǰ���ĳ���
        for(int i = 0;i < len;i++) {
            for(int j = i;j < len;j++) {//ȡ��ǰ���������Ӵ�������
                string ss = "",sleft = "",sright = "";
                for(int k = i;k <= j;k++) ss += tmp.now[k];//��ǰ�Ӵ�[i,j]
                if(mp.count(ss)) {
                    int pos = 0;
                    while(pos<i) sleft += tmp.now[pos++];//�Ӵ�ǰ���ַ���
                    pos = j+1;
                    while(pos<len) sright += tmp.now[pos++];//�Ӵ�����ַ���
                    for(int k = 0;k < mp[ss].size();k++) {//������ǰ�Ӵ�����ת�����ַ���
                        string snow = mp[ss][k];//ת������ַ���
                        //�� sleft+snow+sright ��Ϊ�������
                        q.push(node{sleft+snow+sright,tmp.step+1});//����+1
                    }
                }
            }
        }
    }
    if(ans==-1) cout<<"NO ANSWER!\n";
    else cout<<ans<<"\n";
    return 0;
}
