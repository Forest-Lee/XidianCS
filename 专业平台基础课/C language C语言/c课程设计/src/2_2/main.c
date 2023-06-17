#include <stdio.h>
#include <ctype.h>
#include <memory.h>
#include <stdlib.h>

void countAlpha() {
    /**
     * @brief ������ĸ���ֵĴ���
     * @author �ſ��� 16030199025
     */
    FILE *fp;
    char c;
    int countlist[26] = {0};
    /*
     * countlist����˲�ͬ��ĸ���ַ���
     */
    fp = fopen("text.txt", "r");
    //ֻ�����ļ�
    if (fp == NULL) return;

    while (fscanf(fp, "%c", &c) != EOF) {
        if (isalpha(c)) {
            if (c >= 'a') {
                countlist[c - 'a']++;
            } else {
                countlist[c - 'A']++;
            }
        }
    }
    printf("ͳ����ɣ�������£�\n");
    printf("\t��ĸ\t--------\t����\n");
    for (int i = 0; i < 26; ++i) {
        printf("\t%c\t--------\t%d\n", 'a' + i, countlist[i]);
    }

    fclose(fp);
}

void StrReplace(char *strSrc, char *strReplace, int position, int len) {
    /**
     * @brief �滻�ַ���
     * @param strSrc ԭʼ�ַ���
     * @param strReplace �滻�ַ���
     * @param position �滻λ��
     * @return <description>
     * @exception <name> <description>
     * @see <name>
     * @warning <text>
     * @author �ſ��� 16030199025
     */
    char tempString[1000] = {0};
    //�ݴ��ַ���
    int oldlen = strlen(strSrc);
    memcpy(tempString, strSrc + position + len, strlen(strSrc) - position - len);

    memcpy(strSrc + position, strReplace, strlen(strReplace));
    //���滻�ַ������ǵ�Դ�ַ����Ķ�Ӧλ����
    memcpy(strSrc + position + strlen(strReplace), tempString, strlen(tempString));
    //����ԭ������ĺ�벿��
    *(strSrc + oldlen + strlen(strReplace) - len) = '\0';
}

void replaceString() {
    /**
     * @brief �滻�ļ��е��ַ���
     * @author �ſ��� 16030199025
     */

    FILE *fp;
    FILE *fptemp;
    char string[1000]; //���ڶ�ȡԭʼ�ַ���
    char keyword[200] = {0}; //�����ַ���
    char strReplace[200]; //�滻�ַ���

    fp = fopen("text.txt", "r");
    fptemp = fopen("temp.txt", "wt");
    if (fp == NULL) return;
    if (fptemp == NULL) return;
    //��ʼ���ļ�ָ��

    printf("������ؼ���:");
    scanf("%s", keyword);
    printf("�������滻�ַ�:");
    scanf("%s", strReplace);

    //��ȡ�û�����
    while (fgets(string, 1000, fp)) {
        //���д���
        for (int j = 0; j < strlen(string); j++) {
            //�����Ƿ����keyword
            int findflag = 1;
            //����״̬
            for (int i = 0; i < strlen(keyword); i++) {
                if (*(string + j + i) != keyword[i]) {
                    findflag = 0;//������
                    break;
                }
            }
            if (findflag) {
                printf("����������ƥ��������ؼ��֣�\n");
                printf("%s\n", string);

                StrReplace(string, strReplace, j, strlen(keyword));
                //�滻�ַ���

                printf("�滻���\n");
                printf("�滻��Ľ��Ϊ��\n");
                printf("%s\n\n-------\n", string);

            }//ִ���滻
        }
        fputs(string, fptemp);
    }
    printf("�������ݴ������\n");
    fclose(fp);
    fclose(fptemp);
    fp = fopen("text.txt", "wt");
    fptemp = fopen("temp.txt", "r");
    while (fgets(string, 1000, fptemp)) {
        fputs(string, fp);
    }
    fclose(fptemp);
    fclose(fp);
    printf("�����ɹ�������\n");
}


int main(int argc, char const *argv[]) {
    int choose = 0;

    while (1) {

        printf("\t==================\n");
        printf("\tӢ���ı�������=\n");
        printf("\t==================\n");
        printf("\t���\t--------\t����\n");
        printf("\t1\t--------\tͳ����ĸ����\n");
        printf("\t2\t--------\t�޸��ı��ַ���\n");
        printf("\t0\t--------\t�˳�ϵͳ\n");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                countAlpha();
                break;
            case 2:
                replaceString();
                break;
            case 0:
                return 0;
            default:
                puts("��������...");
        }
        puts("�밴���������...");
        fflush(stdin);
        getchar();
        system("cls");

    }
}



