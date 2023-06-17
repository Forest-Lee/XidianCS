#include <stdio.h>

typedef struct {
    double n;
    double i;
} complexNum;

complexNum add(complexNum complexNum1, complexNum complexNum2) {
    /**
     * @brief �����������
     * @param complexNum1 ��һ������
     * @param complexNum2 �ڶ�������
     * @return ����������ӵĽ��
     * @author �ſ��� 16030199025
     */
    complexNum complexNum3;
    complexNum3.n = complexNum1.n + complexNum2.n;
    complexNum3.i = complexNum1.i + complexNum2.i;
    return complexNum3;
}

complexNum del(complexNum complexNum1, complexNum complexNum2) {
    /**
     * @brief �����������
     * @param complexNum1 ��һ������
     * @param complexNum2 �ڶ�������
     * @return ������������Ľ��
     * @author �ſ��� 16030199025
     */
    complexNum complexNum3;
    complexNum3.n = complexNum1.n - complexNum2.n;
    complexNum3.i = complexNum1.i - complexNum2.i;
    return complexNum3;
}

complexNum multi(complexNum complexNum1, complexNum complexNum2) {
    /**
     * @brief �����������
     * @param complexNum1 ��һ������
     * @param complexNum2 �ڶ�������
     * @return ����������˵Ľ��
     * @author �ſ��� 16030199025
     */
    complexNum complexNum3;
    complexNum3.n = (complexNum1.n * complexNum2.n) + (complexNum1.i * complexNum2.i);
    complexNum3.i = (complexNum1.n * complexNum2.i) + (complexNum2.n * complexNum1.i);
    return complexNum3;
}

complexNum div(complexNum complexNum1, complexNum complexNum2) {
    /**
     * @brief �����������
     * @param complexNum1 ��һ������
     * @param complexNum2 �ڶ�������
     * @return ������������Ľ��
     * @author �ſ��� 16030199025
     */
    complexNum complexNum3;
    complexNum3.n = complexNum1.n / (complexNum2.n * complexNum2.n + complexNum2.i * complexNum2.i)
                    * complexNum2.n
                    + complexNum2.i / (complexNum2.n * complexNum2.n + complexNum2.i * complexNum2.i)
                      * complexNum2.i;
    complexNum3.i = complexNum1.n / (complexNum2.n * complexNum2.n + complexNum2.i * complexNum2.i)
                    * complexNum2.i
                    + complexNum2.i / (complexNum2.n * complexNum2.n + complexNum2.i * complexNum2.i)
                      * complexNum2.n;
    return complexNum3;
}

char *show(complexNum aComplexNum) {
    /**
     * @brief ����ת�ַ���
     * @param aComplexNum ����
     * @return �������ַ�����ʾ
     * @author �ſ��� 16030199025
     */
    static char complexNumString[50];
    sprintf(complexNumString, "%.2lf+%.2lfi", aComplexNum.n, aComplexNum.i);
    return complexNumString;
}

int main() {
    complexNum complexNum1;
    complexNum complexNum2;
    while (1) {
        puts("�������һ��������ʵ����");
        scanf("%lf", &complexNum1.n);
        puts("�������һ���������鲿��");
        scanf("%lf", &complexNum1.i);

        printf("����ĵ�һ������Ϊ��%.2lf+%.2lfi\n", complexNum1.n, complexNum1.i);

        puts("������ڶ���������ʵ����");
        scanf("%lf", &complexNum2.n);
        puts("������ڶ����������鲿��");
        scanf("%lf", &complexNum2.i);

        printf("����ĵڶ�������Ϊ��%.2lf+%.2lfi\n", complexNum2.n, complexNum2.i);

        puts("�����������(+ - * /)");
        char operator;
        while (((operator = (char) getchar()) != '\n') && operator != EOF);

        operator = (char) getchar();

        switch (operator) {
            case '+':
                printf("(%s)+", show(complexNum1));
                printf("(%s)", show(complexNum2));
                printf("=(%s)\n", show(add(complexNum1, complexNum2)));
                printf("������Ϊ��%s", show(add(complexNum1, complexNum2)));
                break;

            case '-':
                printf("(%s)-", show(complexNum1));
                printf("(%s)", show(complexNum2));
                printf("=(%s)\n", show(del(complexNum1, complexNum2)));
                printf("������Ϊ��%s", show(del(complexNum1, complexNum2)));
                break;

            case '*':
                printf("(%s)*", show(complexNum1));
                printf("(%s)", show(complexNum2));
                printf("=(%s)\n", show(multi(complexNum1, complexNum2)));
                printf("������Ϊ��%s", show(multi(complexNum1, complexNum2)));
                break;

            case '/':
                printf("(%s)/", show(complexNum1));
                printf("(%s)", show(complexNum2));
                printf("=(%s)\n", show(div(complexNum1, complexNum2)));
                printf("������Ϊ��%s", show(div(complexNum1, complexNum2)));
                break;

            default:
                puts("�������룡");
                break;
        }
        puts("\n������(y/n)");
        while (((operator = (char) getchar()) != '\n') && operator != EOF);
        operator = (char) getchar();
        if (operator == 'n')
            break;
    }

    return 0;
}
