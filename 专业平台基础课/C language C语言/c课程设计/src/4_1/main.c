/*ģ�� KTV ���ϵͳ���û��ɰ���������ĳ�׸����򰴸��������������и�����
������ʾ���������ʡ�����Ա����Ӻ�ɾ��������ÿ�������ĸ����һ����������
���洢��
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

void Printlrc(char *song) {
    /**
     * @brief ��ӡ���
     * @param song ������
     * @author �ſ��� 16030199025
     */
    if(isspace(song[strlen(song) - 1]))
        song[strlen(song) - 1]='\0';
    //ȥ���ַ�����β�Ļ��з�
    strcat(song, ".lrc");
    //strcat�����ַ��������ַ�������.lrc��׺
    FILE *fp;
    fp = fopen(song, "r");
    if (fp == NULL) return;
    //��ʼ���ļ�ָ�룬ֻ��ģʽ
    char string[1000];
    while (fgets(string, 1000, fp)) {
        puts(string);//ÿ����һ�о�����Ļ����ʾһ��
        sleep(1);

    }
    puts("\n\n�����������...");
    fflush(stdin);
    getchar();
}

void ChooseSong() {
    /**
     * @brief ��������
     * @author �ſ��� 16030199025
     */
    FILE *fp;
    fp = fopen("songlib.csv", "r");
    if (fp == NULL) return;
    //��ʼ���ļ�ָ�룬ֻ��
    char keyword[100];
    printf("��������������������\n");
    scanf("%s", keyword);
    //�����ؼ���
    int index = 0;
    //������±����
    char result[1000][100];
    //�����
    char string[1000];
    //����������ļ��ж������ַ���
    while (fgets(string, 1000, fp)) {
        //���д��������ؼ���
        for (int j = 0; j < strlen(string); j++) {
            //�����Ƿ����keyword
            int findflag = 1;
            //����״̬
            for (int i = 0; i < strlen(keyword); i++) {
                if (*(string + j + i) != keyword[i]) {
                    findflag = 0;//���ֲ�ƥ��
                    break;
                }
            }
            if (findflag) {
                //���ƥ��
                int i = 0;
                strcpy(result[++index], string);
                //��ƥ��ĸ�����Ϣ���浽������
                printf("���������¸�����Ŀ�����ؼ��֣�\n");
                printf("\t%d\t--\t", index);//������
                for (i = 0; i < strlen(string); ++i) {
                    if (*(string + i) == ',') break;//������������������Ž�ֹ
                    printf("%c", *(string + i));
                }
                printf("\t---%s\n", string + i + 1);//���������
            }
        }

    }
    if (index == 0) {
        printf("δ������\n\n");
        return;
    }
    printf("������ѡ�����ţ�");
    int choose;
    scanf("%d", &choose);
    //���û�ѡ��һ���±�
    if (choose <= index) {
        printf("���ɹ���\n\n");
        Printlrc(result[index]);
        //����printlic����ӡ��Ӧ�����ĸ��
        printf("\n\n");
    } else printf("�������������!!\n");

}

void AddSong() {
    /*
     * ����Ա������׷��һ�׸�
     */
    FILE *fp;
    fp = fopen("songlib.csv", "a"); //׷�Ӵ��ļ�
    if (fp == NULL) return;

    printf("�������������");
    char artist[100];
    scanf("%s", artist);
    printf("�������������");
    char songName[100];
    scanf("%s", songName);

    fprintf(fp, "%s,%s\n", artist, songName);
    //��ʽ��׷��
    printf("���Ӹ����ɹ�\n");
    printf("���ֶ��������ļ����ļ�������������,������.lrc����ע���Ƕ��ţ�\n\n");
    fclose(fp);
}

void DelSong() {
    /*
     * ����Ա������ɾ������
     */
    FILE *fp;
    FILE *fptemp; //��ת���棬��ʱ�ļ�
    fptemp = fopen("temp.txt", "wt");
    fp = fopen("songlib.csv", "r");
    if (fptemp == NULL) return;
    if (fp == NULL) return;
    //��ʼ���ļ�ָ��

    char string[100];
    int index = 0;
    printf("�������������");
    char artist[100];
    scanf("%s", artist);
    printf("�������������");
    char songName[100];
    scanf("%s", songName);

    while (fgets(string, 1000, fp)) {
        int findArtist = 0;
        int findSongName = 0;
        for (int j = 0; j < strlen(string); j++) {
            //�����Ƿ����artist
            int findArtistflag = 1;
            //����״̬
            for (int i = 0; i < strlen(artist); i++) {
                if (*(string + j + i) != artist[i]) {
                    findArtistflag = 0;
                    continue;
                }
            }
            if (findArtistflag == 1) {
                findArtist = 1;
                continue;
            }
            int findSongNameFlag = 1;
            //�����Ƿ����Songname
            for (int i = 0; i < strlen(songName); i++) {
                if (*(string + j + i) != songName[i]) {
                    findSongNameFlag = 0;//������
                    continue;
                }
            }
            if (findSongNameFlag == 1) {
                findSongName = 1;
                continue;
            }
        }
        if (findArtist && findSongName) {
            int i = 0;
            printf("���������¸�����Ŀ�����ؼ��֣�\n");
            printf("\t%d\t--\t", ++index);
            for (i = 0; i < strlen(string); ++i) {
                if (*(string + i) == ',') break;
                printf("%c", *(string + i));
            }
            printf("\t---%s\n", string + i + 1);
            printf("ɾ����(y/n)");
            fflush(stdin);
            char choice;
            scanf("%c", &choice);
            if (choice == 'y') continue;
        }

        fputs(string, fptemp);
    }
    fclose(fp);
    fclose(fptemp);
    fptemp = fopen("temp.txt", "r");
    fp = fopen("songlib.csv", "wt"); 
    if (fptemp == NULL) return;
    if (fp == NULL) return;
    while (fgets(string, 1000, fptemp)) {
        fputs(string, fp);
    }

    fclose(fptemp);
    fclose(fp);
    printf("\n");

}

void Admin() {
    /*
     * ����Ա��̨
     */
    char psw[100];
    char correctPsw[100];
    printf("���������Ա���룺");
    scanf("%s", psw);

    FILE *fp;
    fp = fopen("admin.db", "r");
    if (fp == NULL) return;

    fgets(correctPsw, 100, fp);
    //���ļ��ж�ȡ����
    for (int i = 0; i < strlen(correctPsw); ++i) {
        //�Ƚ��Ƿ���ͬ�������κ�һλ��ֱͬ���˳�
        if (psw[i] != correctPsw[i]) {
            printf("����Ա�������\n");
            return;
        }
    }
    printf("����Ա���ȷ�ϳɹ���\n");
    printf("\t���\t--------\t����\n");
    printf("\t1\t--------\t���Ӹ���\n");
    printf("\t2\t--------\tɾ������\n");
    printf("\t0\t--------\t�˳�ϵͳ\n");
    int choose;
    scanf("%d", &choose);
    switch (choose) {
        case 1:
            AddSong();
            break;
        case 2:
            DelSong();
            break;
        case 0:
            return;
        default:
            puts("��������...");
            getchar();
    }
}
void ShowLib() {
    /**
     * @brief չʾ��������
     * @author �ſ��� 16030199025
     */
    FILE *fp;
    fp = fopen("songlib.csv", "r");
    if (fp == NULL) return;
    //��ʼ���ļ�ָ�룬ֻ��
    //�����ؼ���
    int index = 0;
    //������±����
    char result[1000][100];
    //�����
    char string[1000];
    //����������ļ��ж������ַ���
    printf("����������¸�����Ŀ��\n");
    while (fgets(string, 1000, fp)) {
        int i = 0;
        strcpy(result[++index], string);
        printf("\t%d\t--\t", index);//������
        for (i = 0; i < strlen(string); ++i) {
            if (*(string + i) == ',') break;//������������������Ž�ֹ
            printf("%c", *(string + i));
        }
        printf("\t---%s\n", string + i + 1);//���������
    }
}
int main(void) {
    int choose = 0;

    while (1) {

        printf("\t==================\n");
        printf("\tktv���ϵͳ\n");
        printf("\t==================\n");
        printf("\t���\t--------\t����\n");
        printf("\t1\t--------\tչʾ����\n");
        printf("\t2\t--------\t��ʼ���\n");
        printf("\t3\t--------\t����Ա��¼\n");
        printf("\t0\t--------\t�˳�ϵͳ\n");
        scanf("%d", &choose);
        switch (choose) {
            case 1:
                ShowLib();
                break;
            case 2:
                ChooseSong();
                break;
            case 3:
                Admin();
                break;
            case 0:
                return 0;
            default:
                puts("��������...");
                getchar();
        }
    }
}
