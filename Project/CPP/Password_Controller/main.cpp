#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#define contrlccc 100039223
#define MAXN 1000001

#define ConstHelpMain "�����棺�������   �汾1.2.2\nʹ�÷�������\n1��add���������\nʵ����\n>>>add\n�����û�����Thomas\n�������룺password123\n��ʾ��Ϣ��QQ\n¼����ɣ�\n-----------------\n\
2��help��������ҳ��\n3��exit���˳�\n4��show����ʾ���м�¼\n5��cls/clear������\n6��delete��ɾ��ĳ��\nʵ����\n>>> delete\n������Ҫɾ���ı�ţ�2\nɾ����ɣ�\n-----------------\n�������������......\n"


#define ConstHelpInline ""
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int cnt = 0;
int allcnt; //�ܼ���
typedef struct ctler{
	int id;
	/*string account;
	string pass;
	string info;*/
	char* account;
	char* pass;
	char* info;
	bool flag = true;
}passctl;
passctl cc[MAXN];
class method{
private:
	void clears()
	{
		system("cls");
	}
public:
	method()
	{
		ifstream fin("data/allcnt.txt");
		fin >> allcnt;
	}
	void add()
	{
		string ac, password;
		char ifo[101];
		char cca[101], ccap[101];
		//printf("�����û�����");
		cout << "�����û�����";
		//getline(cin, ac);
		//gets(cca);
		scanf("%s", &cca);
		printf("�������룺");
		//getline(cin, password, '\n');
		//gets(ccap);
		scanf("%s", &ccap);
		printf("��Ϣ��");
		//getline(cin, info);
		//gets(ifo);
		scanf("%s", &ifo);
		cc[cnt].id = cnt;
		cc[cnt].account = cca;
		cc[cnt].pass = ccap;
		cc[cnt].info = ifo;
		cnt++;
		allcnt++;
		printf("¼����ɣ�\n");
		ofstream fout("data/save.csv", ios::app);
		fout << cc[cnt].id << "," << cc[cnt].account << "," << cc[cnt].pass << "," << cc[cnt].info << endl; 
		printf("success...\n");
	}
	void help()
	{
		printf(ConstHelpMain);
	}
	void show()
	{
		ifstream fin("data/save.csv"); 
		for (int i = 0; i < allcnt; i++)
		{
			if (cc[i].flag) {
				string tmps;
				getline(fin, tmps);
				for (int i = 0; i < tmps.size(); i++)
				{
					if (tmps[i] == ',') {
						cout << " ";
						continue;
					}
					else{
						cout << tmps[i];
					}
				}printf("\n");
			} else {
				continue;
			}
		}
	}
	void del()
	{
		printf("������Ҫɾ���ı��> ");
		int idx;
		cin >> idx;
		cc[idx - 1].flag = false; //��Ƿ�ɾ��ģʽ
		printf("ɾ���ɹ���\n");
		return;
	}
	void change(int idx, char* account, char* pass, char* info)
	{
		return;
	}
	void clsc()
	{
		clears();
	}
	void gexit()
	{
		ofstream fout("data/allcnt.txt");
		fout << allcnt << endl;
		exit(1);
	}
};
method met;
int main(int argc, char** argv) {
	system("cls");//��ʼ�����
	printf(ConstHelpMain);
	char tmpj = getch();
	system("cls");
	//delete search cls/clear  �س��Զ���ȫ 
	//reset/restart
	// change
	#if 1
	while (true)
	{
		printf(">>> ");
		string cp;
		#if 0
		cin >> cp;
		#endif
		getline(cin, cp, '\n');
		if (cp == "add")
			met.add();
		else if (cp == "help")
			met.help();
		else if (cp == "exit")
			met.gexit();
		else if (cp == "show")
			met.show();
		else if (cp == "cls") met.clsc();
		else if (cp == "delete") met.del();
		else if (cp == "clear") met.clsc();
		else if (cp == "");
		else
			printf("�﷨����\n");
	}
	#endif
	#if 0
	do{
		printf(">>> ");
		string cp;
		cin >> cp;
		if (cp == "add") met.add();
		else if (cp == "help") met.help();
		else if (cp == "exit") exit(1);
		else if (cp == "show") met.show();
		else if (cp == "\n") printf(">>> ");
		else printf("�﷨����\n");
	} while (true);
	#endif
	#if 0
	system("pause");
	#endif
	return 0;
}



//protect:
/*
(const char [306])"�����棺�������   �汾1.2.2\nʹ�÷�������\n1��add���������\nʵ����\n>>>add\n�����û�����Thomas\n�������룺password123\n��ʾ��Ϣ��QQ\n¼����ɣ�\n-----------------\n2��help��������ҳ��\n3��exit���˳�\n4��show����ʾ���м�¼\n�������������......\n"
*/