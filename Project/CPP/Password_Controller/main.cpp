#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#define contrlccc 100039223
#define MAXN 1000001

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int cnt = 0;
typedef struct ctler{
	int id;
	/*string account;
	string pass;
	string info;*/
	char* account;
	char* pass;
	char* info;
}passctl;
passctl cc[MAXN];
class method{
public:
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
		cnt++;
		cc[cnt].id = cnt;
		cc[cnt].account = cca;
		cc[cnt].pass = ccap;
		cc[cnt].info = ifo;
		printf("¼����ɣ�\n");
		ofstream fout("data/save.csv", ios::app);
		fout << cc[cnt].id << "," << cc[cnt].account << "," << cc[cnt].pass << "," << cc[cnt].info << endl; 
		printf("success...\n");
	}
	void help()
	{
		printf("\n�汾1.0.1\nʹ�÷�������\n1��add���������\nʵ����\n>>>add\n�����û�����Thomas\n�������룺password123\n��ʾ��Ϣ��QQ\n¼����ɣ�\
	2��help��������ҳ��\n3��exit���˳�\n4��show����ʾ���м�¼\n�������������......\n");
	}
	void show()
	{
		ifstream fin("data/save.csv"); 
		for (int i = 0; i < cnt; i++)
		{
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
		}
	}
};
method met;
int main(int argc, char** argv) {
	printf("�����棺�������   �汾1.0.1\nʹ�÷�������\n1��add���������\nʵ����\n>>>add\n�����û�����Thomas\n�������룺password123\n��ʾ��Ϣ��QQ\n¼����ɣ�\n-----------------\n\
2��help��������ҳ��\n3��exit���˳�\n4��show����ʾ���м�¼\n�������������......\n");
	char tmpj = getch();
	system("cls");
	//delete search cls/clear  �س��Զ���ȫ 
	#if 1
	while (true)
	{
		printf(">>> ");
		string cp;
		cin >> cp;
		if (cp == "add")
			met.add();
		else if (cp == "help")
			met.help();
		else if (cp == "exit")
			exit(1);
		else if (cp == "show")
			met.show();
		else if (cp == "")
			continue;
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
