#include <stdio.h>
#include <stdlib.h>
int compInc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main() {
    /**
     * @brief  ������txt�е����ֽ�����������µ�txt
     * @author �ſ��� 16030199025
     */

    const int MAX_COUNT = 1000;//�������������Ŀ
    puts("�뽫��Ҫ�������������txt�ļ��ֱ�����Ϊ\"num1.txt\",\"num2.txt\",�ͱ����������ͬĿ¼�¡�");
    puts("׼��������");
    puts("�����������ַ�����...");
    getchar();

    FILE * fp1;
    FILE * fp2;
    fp1=fopen("num1.txt","r");
    fp2 = fopen("num2.txt","r");
    if(fp1==NULL||fp2==NULL){
        puts("��ȡ�ļ��������飡");
        getchar();
        return 0;
    }
    //��ʼ���ļ�ָ��_ֻ��ģʽ

    int numbers[MAX_COUNT];
    int i = 0; //numbers�±�
    int j = 0; //�ļ������±�
    while (fscanf(fp1,"%d",&numbers[i++])!=EOF);
    i--;
    //���ԭʼ����
    puts("num1�е����֣�");
    for (j = 0; j < i; j++) {
        printf("%d ",numbers[j]);
    }
    printf("\n");

    while (fscanf(fp2,"%d",&numbers[i++])!=EOF);
    i--;
    puts("num2�е����֣�");
    for (; j < i; j++) {
        printf("%d ",numbers[j]);
    }
    printf("\n");

    //�ر��ļ�ָ��
    fclose(fp1);
    fclose(fp2);

    qsort(numbers,i, sizeof(numbers[0]),compInc); //��������

    puts("���������֣�");
    for (int l = 0; l < i; l++) {
        printf("%d ",numbers[l]);
    }//չʾ������
    //д���ļ�
    FILE * fp3;
    fp3=fopen("num3.txt","w+");
    for (int m = 0; m < i; ++m) {
        fprintf(fp3,"%d ",numbers[m]);
    }
    puts("\n\n�ļ�д��ɹ���");
    fclose(fp3);
    return 0;
}
