/*
 * ���������ı��ļ�db1.txt��db2.txt��
 * db1.txt�е�һ��Ϊ�������ڶ���ΪӢ��ɼ���
 * db2.txt�е�һ��Ϊ�������ڶ���Ϊ��ѧ�ɼ���
 * ͨ�������ֶν�db1.txt�ļ�������db2.txt�ļ�����db3.txt�ļ���
 * db3.txt�ļ���һ��Ϊ�������ڶ���ΪӢ��ɼ���
 * ������Ϊ��ѧ�ɼ���������Ϊƽ���ɼ���
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS_AMOUNT 100
typedef struct {
    char name[20]; //����
    int englishGrade; //Ӣ��ɼ�
    int mathGrade; //��ѧ�ɼ�
    double average; //ƽ���ɼ�
} StuGrades;

StuGrades StructstuGrades[MAX_STUDENTS_AMOUNT];
//�ṹ������,���ѧ����Ϣ

int comInt(const void *p, const void *q) {
    return -(int) ((*(StuGrades *) p).average - (*(StuGrades *) q).average);
}

int main() {
    /**
     * @brief �ɼ�������
     * @author �ſ��� 16030199025
     */
    //��ʼ���ļ�ָ��
    puts("�뽫��Ҫ���д���ķ������ݷֱ�����Ϊ\"db1.txt\",\"db2.txt\",�ͱ����������ͬĿ¼�¡�");
    puts("׼��������");
    puts("�����������ַ�����...");
    getchar();

    FILE *fp1 = fopen("db1.txt", "r");
    FILE *fp2 = fopen("db2.txt", "r");
    FILE *fp3 = fopen("db3.txt", "w+");
    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        puts("���ļ�ʧ�ܣ�");
    }
    puts("���ļ��ɹ�");

    int i = 0;
    char name[20];
    int grade;
    while (fscanf(fp1, "%s%d", StructstuGrades[i].name, &StructstuGrades[i].englishGrade) != EOF)
        i++;

    while (fscanf(fp2, "%s%d", name, &grade) != EOF) {
        //Ѱ��ѧ������һ��������λ��
        for (int j = 0; j < i; ++j) {
            if (strcmp(name, StructstuGrades[j].name) == 0) {
                StructstuGrades[j].mathGrade = grade;
            }
        }
    }

    for (int j = 0; j < i; ++j) {
        StructstuGrades[j].average = (StructstuGrades[j].englishGrade + StructstuGrades[j].mathGrade) / 2.0;
    }//����ƽ������
    //����
    qsort(StructstuGrades, i, sizeof(StuGrades), comInt);

    //���
    puts("����Ϊ������:");
    printf("%15s %4s %4s %4s\n", "����", "Ӣ��", "��ѧ", "ƽ������");
    for (int k = 0; k < i; ++k) {
        printf("%15s %4d %4d %4.2lf\n", StructstuGrades[k].name, StructstuGrades[k].englishGrade,
               StructstuGrades[k].mathGrade, StructstuGrades[k].average);
    }
    //д���ļ�
    for (int k = 0; k < i; ++k) {
        fprintf(fp3, "%15s %4d %4d %4.2lf\n", StructstuGrades[k].name, StructstuGrades[k].englishGrade,
                StructstuGrades[k].mathGrade, StructstuGrades[k].average);
    }
    printf("д���ļ�\"db3.txt\"�ɹ�!!");
}
