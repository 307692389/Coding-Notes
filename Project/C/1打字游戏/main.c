#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

//����ַ������Ҵ�ӡ��ͬʱͳ������ʱ�����ȷ��
void userWord(char *str, int len)
{
    int i = 0;
    char ch;
    double T_len = 0.0; //������¼��ȷ����ĵ��ַ���
    time_t start_time, end_time;
    printf("\t������Ϸ�����ַ���Ϊ��\n");
    printf("%s\n", str);
    start_time = time(NULL); //��ʼʱ��
    for (; i < len - 1; i++)
    {
        ch = _getch();
        if (*(str + i) == ch)
        {
            printf("%c", ch);
            ++T_len;
        }
        else
            printf("%c", '_');
    }
    end_time = time(NULL); //��ֹʱ��
    putchar('\n');
    printf("\t�ܹ����ˣ�%ds\n", end_time - start_time);
    printf("\t��ȷ�ʣ�%.2lf%%\n", (T_len / len) * 100.0);
    //��Ҫͷ�ļ�#include <time.h>
}

int main(void)
{

    char buf0[50];
    char num;
    int i, len;
    puts("\t-------------------------");
    puts("\t**                    **");
    puts("\t**��ӭʹ�ô���С��Ϸ  **");
    puts("\t-------------------------");
    len = sizeof(buf0);
    srand((unsigned int)time(NULL));
    memset(buf0, 0, sizeof(buf0));
    for (i = 0; i < len - 1; i++) //0----
    {
        num = 'a' + rand() % 26;
        buf0[i] = num;
    }

    printf("\t�ַ����г��� = %d\n", len);
    userWord(buf0, len);
    puts("\t**                    **");
    puts("\t-------------------------");
    system("pause");
    return 0;
}