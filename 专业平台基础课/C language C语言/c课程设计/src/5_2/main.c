#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100 //����������
int main() {

    int randomList[MAX_NUMBER]; //���д洢���ɵ������
    int n; //��Ҫ���ɵ����������
    int min; //�������Сֵ
    int max; //��������ֵ
	srand((unsigned) time(NULL));
    do {
        puts("��������Ҫ���ɵ������������");
        scanf("%d", &n);
        if(n>=0&&n<=MAX_NUMBER) {
            break;
        } else{
            puts("������������֣�����������");
        }
    }while (1);

    do {
        puts("��������Ҫ���ɵ��������Сֵ��");
        scanf("%d", &min);
        puts("��������Ҫ���ɵ���������ֵ��");
        scanf("%d", &max);
        if(min<max) {
            break;
        } else{
            puts("������������֣�����������");
        }
    }while (1);
    while (1) {
        for (int i = 0; i < n; ++i) {

            int newRandomNumber = 0;
     
            newRandomNumber = (rand() % (max - min)) + min;
            int findSameFlag = 0;
            for (int j = 0; j < i; ++j) {
                if (randomList[j] == newRandomNumber) {
                    i--;
                    findSameFlag = 1;
                    break;
                    //��鵽�ظ�����������
                }
            }
            if(!findSameFlag)
                randomList[i] = newRandomNumber;
            //���ظ������������������
        }

        puts("���������������:");
        for (int k = 0; k < n; ++k) {
            printf("%d , ", randomList[k]);
        }
        puts("����������(y/n)");
        fflush(stdin); 
        char choise;
        choise = getchar();
        if(choise == n){
            break;
        }

    }

}
