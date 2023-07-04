#include <stdio.h>
#include <memory.h>
#include <windows.h>

void findDifferent(FILE *fp1, FILE *fp2) {
    /**
     * @brief �Ƚ������ļ�ָ���Ӧ��txt��֮ͬ��
     * @param fp1 ��һ��txt��Ӧ���ļ�ָ��
     * @param fp2 �ڶ���txt��Ӧ���ļ�ָ��
     * @author �ſ��� 16030199025
     */
    const int MAX_LENGTH = 80; //ÿ�е���󳤶�
    char tempString1[MAX_LENGTH];   //�����ļ�һ���ַ���
    char tempString2[MAX_LENGTH];   //�����ļ�һ���ַ���
    HANDLE handle;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int j = 0; //�����к�
    int i = 0;
    while (1) {
        j++;//�����к�
        if ((fgets(tempString1, MAX_LENGTH, fp1) == NULL) &
            (fgets(tempString2, MAX_LENGTH, fp2) == NULL)) {
            puts("δ��⵽��ͬ");
        };

        if (isspace(*(tempString1 + strlen(tempString1) - 1)))
            tempString1[strlen(tempString1) - 1] = '\0';
        if (isspace(*(tempString2 + strlen(tempString2) - 1)))
            tempString2[strlen(tempString2) - 1] = '\0';
        //ȥ��ĩβ�Ŀհ��ַ�

        if (strcmp(tempString1, tempString2)) {
            printf("�ڵ�%d�в�׽����ͬ\n",j);
            for (i = 0;
                 i <= (strlen(tempString1) < strlen(tempString2) ? strlen(tempString1) : strlen(tempString2)); i++) {
                if (*(tempString1 + i) == *(tempString2 + i)) {
                    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
                    printf("%c", *(tempString1 + i));
                } else {
                    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
                    printf("%c", *(tempString1 + i));
                    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
                }
            }
            if (i < strlen(tempString1)) {
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
                puts(tempString1 + i);
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
            } else printf("\n");

            for (i = 0;
                 i <= (strlen(tempString2) < strlen(tempString1) ? strlen(tempString2) : strlen(tempString1)); i++) {
                if (*(tempString1 + i) == *(tempString2 + i)) {
                    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
                    printf("%c", *(tempString2 + i));
                } else {
                    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
                    printf("%c", *(tempString2 + i));
                    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
                }
            }
            if (i < strlen(tempString2)) {
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
                puts(tempString2 + i);
                SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
            } else printf("\n");

            return;
        }
    }


}

int main() {
    /**
     * @brief �Ƚ�����txt�Ĳ�֮ͬ������ӡ��һ����ͬ����
     * @author �ſ��� 16030199025
     */

    HANDLE handle;
    handle = GetStdHandle(STD_OUTPUT_HANDLE); //������
    puts("txt�ļ��ȽϹ���");
    puts("�뽫��Ҫ�Ƚϵ�txt�ļ��ֱ�����Ϊ\"txt1.txt\",\"txt2.txt\",�ͱ����������ͬĿ¼�¡�");
    puts("׼��������");
    getchar();

    FILE *fp1;
    FILE *fp2;
    fp1 = fopen("txt1.txt", "r");
    fp2 = fopen("txt2.txt", "r");
    if (fp1 == NULL || fp2 == NULL) {
        puts("��ȡ�ļ��������飡");
        getchar();
        exit(1);
    }
    //��ʼ���ļ�ָ��_ֻ��ģʽ

    findDifferent(fp1, fp2); //����findDifferent�Ƚ������ļ�ָ���Ӧ��txt��֮ͬ��
    fclose(fp1);
    fclose(fp2);
}
