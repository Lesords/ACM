#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//���⣺�����������ڣ������ǵ����
//��⣺dfs��������������׵�ʱ���������������µ�������˳��

int val[25],n,ans;//val����ؽѵĵ�������ansΪ�ڵĵ�����
vector<int> g[25],ord,num;//g����·��ͼ��ordΪ�м�˳��numΪ���˳��
void dfs(int dot) {//dotΪ��ǰ��
    if(g[dot].empty()) {//������
        int tmp = 0;//tmp���浱ǰ�ڳ��ĵ�����
        for(int i = 0;i < ord.size();i++) tmp += val[ord[i]];//ord������ǵ�
        if(tmp>ans) {//���½ϴ�ֵ
            num = ord,ans = tmp;
        }
        return;
    }
    for(int i = 0;i < g[dot].size();i++) {//��������ָ��ĵ�
        ord.push_back(g[dot][i]);//���ָ���
        dfs(g[dot][i]);//����dfs�˵�
        ord.pop_back();//ȥ���˵�
    }
}
int main() {
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>val[i];//�����Ӧ�ؽѵĵ�����
    for(int i = 1;i < n;i++) {
        int op;
        for(int j = i+1;j <= n;j++) {
            cin>>op;
            if(op) g[i].push_back(j);//1Ϊ������
        }
    }
    for(int i = 1;i < n;i++) {//���еĵ�Ϊ������dfs������
        ord.push_back(i);//��ӵ�ǰ��
        dfs(i);
        ord.pop_back();//ɾ����ǰ��
    }
    for(int i = 0;i < num.size();i++) cout<<num[i]<<' ';//���˳��
    cout<<endl<<ans<<endl;
    return 0;
}
