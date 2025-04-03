#include "stack.h"
int main() {
    setlocale(LC_ALL, "Russian");
    int ch;
    printf("=======================================\n");
    printf("Выберите задание (1-3, 0 для выхода): \n");
    printf("=======================================\n");
    printf("->");
    scanf("%d", &ch);
  switch (ch) {
       case 1: t1(); break;
       case 2: t2(); break;
       case 3: t3(); break;
       default: printf("Ввод не коректный попробуйте еще раз"); break;
       }
    return 0;
}