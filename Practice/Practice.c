#include <stdio.h>
#include <locale.h>
#include <time.h>

const char* product[] = { "����", "�����", "���", "�������", "������", "�����", "�����", "����", "����",
"�����", "�������", "�������", "�������", "�������", "�����", "����", "���", "�������", "���������", "��������" };

void print_product(int store[], int countProduct[]);

int main(void) {

    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int n, r = 0, t = 0, y = 0;
    int countProduct[20];
    char* resultArray1[20];
    char* resultArray2[20];
    char* resultArray3[20];

    for (int i = 0; i < 20; i++) {
        countProduct[i] = 0;
    }

    printf("������� N: ");
    scanf_s("%d", &n);

    int** store = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++) {
        store[i] = (int*)malloc(sizeof(int) * 20);
    }

    //------------��������� ��������------------

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            store[i][j] = 0 + rand() % 2;
        }
        printf("������� %d: ", i + 1);
        print_product(store[i], countProduct);
        printf("\n");
    }

    //------------���������� �����������------------

    for (int i = 0; i < 20; i++) {
        if (countProduct[i] > 0) {
            resultArray2[t] = product[i];
            t++;
            if (countProduct[i] == n) {
                resultArray1[r] = product[i];
                r++;
            }
        }
        else {
            resultArray3[y] = product[i];
            y++;
        }
    }

    //------------����� �����������------------

    printf("\n�������� ������� ���� � ������ �� ���������: ");

    for (int i = 0; i < r; i++) {
        printf("%s ", resultArray1[i]);
    }

    printf("\n�������� ������� ���� � ����-�� � ����� �� ���������: ");

    for (int i = 0; i < t; i++) {
        printf("%s ", resultArray2[i]);
    }

    printf("\n�������� ������� ��� �� � ����� �� ���������: ");

    for (int i = 0; i < y; i++) {
        printf("%s ", resultArray3[i]);
    }

    printf("\n");

    //------------������� ������------------

    for (int i = 0; i < n; i++) {
        free(store[i]);
    }
    free(store);
}

void print_product(int store[], int countProduct[]) {

    for (int i = 0; i < 20; i++) {
        if (store[i]) {
            printf("%s ", product[i]);
            countProduct[i]++;
        }
    }
}