#include "stack.h"
int main() {
    setlocale(LC_ALL, "Russian");
    int ch;
    printf("=======================================\n");
    printf("�������� ������� (1-3, 0 ��� ������): \n");
    printf("=======================================\n");
    printf("->");
    scanf("%d", &ch);
  switch (ch) {
       case 1: t1(); break;
       case 2: t2(); break;
       case 3: t3(); break;
       default: printf("���� �� ��������� ���������� ��� ���"); break;
       }
    return 0;
}