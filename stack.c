#include "stack.h"


Stack* st_create(int cap) {
    Stack* s = malloc(sizeof(Stack));
    s->data = malloc(cap * sizeof(int));
    s->cap = cap;
    s->top = 0;
    return s;
}
void st_free(Stack* s) {
    free(s->data);
    free(s);
}
int st_push(Stack* s, int val) {
    if (s->top >= s->cap) return 0;
    s->data[s->top++] = val;
    return 1;
}
int st_pop(Stack* s, int* val) {
    if (s->top == 0) return 0;
    *val = s->data[--s->top];
    return 1;
}
int st_empty(Stack* s) {
    return s->top == 0;
}


DStack* ds_create(int cap) {
    DStack* s = malloc(sizeof(DStack));
    s->data = malloc(cap * sizeof(double));
    s->cap = cap;
    s->top = 0;
    return s;
}
void ds_free(DStack* s) {
    free(s->data);
    free(s);
}
int ds_push(DStack* s, double val) {
    if (s->top >= s->cap) return 0;
    s->data[s->top++] = val;
    return 1;
}
int ds_pop(DStack* s, double* val) {
    if (s->top == 0) return 0;
    *val = s->data[--s->top];
    return 1;
}
int ds_empty(DStack* s) {
    return s->top == 0;
}


CStack* cs_create(int cap) {
    CStack* s = malloc(sizeof(CStack));
    s->data = malloc(cap * sizeof(char));
    s->cap = cap;
    s->top = 0;
    return s;
}
void cs_free(CStack* s) {
    free(s->data);
    free(s);
}
int cs_push(CStack* s, char val) {
    if (s->top >= s->cap) return 0;
    s->data[s->top++] = val;
    return 1;
}
int cs_pop(CStack* s, char* val) {
    if (s->top == 0) return 0;
    *val = s->data[--s->top];
    return 1;
}
int cs_empty(CStack* s) {
    return s->top == 0;
}

/* Задача 1: Создать стек, ввести размер и числа, найти сумму элементов */
void t1() {
    int cap;printf("=======================================\n");
    printf("Создать стек для целых чисел. Максимальный размер стека вводится с экрана. Найти сумму элементов стека.\n");
    printf("=======================================\n");
    printf("->");
    printf("Введите размер стека: ");
    scanf("%d", &cap);
    Stack* s = st_create(cap);
    printf("Введите %d чисел:\n", cap);
    for (int i = 0, num; i < cap; i++) {
        scanf("%d", &num);
        st_push(s, num);
    }
    int sum = 0;
    while (!st_empty(s)) {
        int num;
        st_pop(s, &num);
        sum += num;
    }
    printf("Сумма элементов: %d\n", sum);
    st_free(s);
}
void t2() {
    int n1, n2, num;
    printf("=======================================\n");
    printf("Создать два стека для целых чисел. \n Первый стек – организовать ввод по возрастанию, второй стек – организовать ввод по возрастанию.\nБез сортировок и переворачивания исходных стеков сформировать третий стек упорядоченный по возрастанию\n");
    printf("=======================================\n");
    printf("Введите количество элементов первого стека: ");
    printf("->");
    scanf("%d", &n1);
    Stack* s1 = st_create(n1);
    printf("Введите %d чисел (возрастание) для первого стека:\n", n1);
    int prev = 2147483648;
    for (int i = 0; i < n1; i++) {
        scanf("%d", &num);
        if (i == 0 || num >= prev) { st_push(s1, num); prev = num; }
        else { printf("Ошибка: число должно быть не меньше предыдущего\n"); i--; }
    }
    printf("Введите количество элементов второго стека: ");
    scanf("%d", &n2);
    Stack* s2 = st_create(n2);
    printf("Введите %d чисел (возрастание) для второго стека:\n", n2);
    prev = 2147483648;
    for (int i = 0; i < n2; i++) {
        scanf("%d", &num);
        if (i == 0 || num >= prev) { st_push(s2, num); prev = num; }
        else { printf("Ошибка: число должно быть не меньше предыдущего\n"); i--; }
    }
   
    Stack* s3 = st_create(n1 + n2);
    int i1 = 0, i2 = 0, pos = 0;
    int* arr = malloc((n1 + n2) * sizeof(int));
    while (i1 < s1->top && i2 < s2->top) {
        if (s1->data[i1] <= s2->data[i2])
            arr[pos++] = s1->data[i1++];
        else
            arr[pos++] = s2->data[i2++];
    }
    while (i1 < s1->top) arr[pos++] = s1->data[i1++];
    while (i2 < s2->top) arr[pos++] = s2->data[i2++];
    for (int i = 0; i < pos; i++) {
        st_push(s3, arr[i]);
    }
    printf("Объединённый стек: ");
    for (int i = 0; i < s3->top; i++)
        printf("%d ", s3->data[i]);
    printf("\n");
    free(arr);
    st_free(s1);
    st_free(s2);
    st_free(s3);
}

double applyOp(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return b == 0 ? 0 : a / b;
    }
    return 0;
}
int prec(char op) {
    return (op == '+' || op == '-') ? 1 : (op == '*' || op == '/') ? 2 : 0;
}
int isOp(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void t3() {
    char inFile[100], outFile[100];
    printf("=======================================\n");
    printf("В текстовом файле записаны строки – арифметические выражения.\n Числа – вещественные,знаки действий - -, +, *, / и скобки().\nИспользуя работу со стеками найти значение каждого выражения и записать в файл результатов. \n Если в исходном файле в строке есть ошибка – найти ее предполагаемуюпозицию(позицию первой ошибки) и в выходной файл записать сообщение «Ошибка в позиции N»\n");
    printf("=======================================\n");
    printf("Введите имя входного файла: \n");
    printf("->");
    scanf("%s", inFile);
    printf("Введите имя выходного файла: \n");
    printf("->");
    scanf("%s", outFile);
    FILE* fin = fopen(inFile, "r");
    if (!fin) { printf("Не удалось открыть входной файл\n"); return; }
    FILE* fout = fopen(outFile, "w");
    if (!fout) { printf("Не удалось открыть выходной файл\n"); fclose(fin); return; }
    char line[256];
    while (fgets(line, sizeof(line), fin)) {
        line[strcspn(line, "\n")] = 0;
        DStack* vals = ds_create(100);
        CStack* ops = cs_create(100);
        int errorPos = -1, valid = 1, len = strlen(line);
        for (int i = 0; i < len; i++) {
            char c = line[i];
            if (isspace(c)) continue;
            if (isdigit(c) || c == '.') {
                char buf[64];
                int j = 0;
                while (i < len && (isdigit(line[i]) || line[i] == '.'))
                    buf[j++] = line[i++];
                buf[j] = '\0';
                ds_push(vals, atof(buf));
                i--;
            }
            else if (c == '(') {
                cs_push(ops, c);
            }
            else if (c == ')') {
                int found = 0;
                while (!cs_empty(ops)) {
                    char op;
                    cs_pop(ops, &op);
                    if (op == '(') { found = 1; break; }
                    else {
                        double b, a;
                        if (!ds_pop(vals, &b) || !ds_pop(vals, &a)) { valid = 0; errorPos = i; break; }
                        ds_push(vals, applyOp(a, b, op));
                    }
                }
                if (!found) { valid = 0; errorPos = i; break; }
            }
            else if (isOp(c)) {
                while (!cs_empty(ops)) {
                    char op;
                    cs_pop(ops, &op);
                    if (op == '(' || prec(op) < prec(c)) { cs_push(ops, op); break; }
                    else {
                        double b, a;
                        if (!ds_pop(vals, &b) || !ds_pop(vals, &a)) { valid = 0; errorPos = i; break; }
                        ds_push(vals, applyOp(a, b, op));
                    }
                }
                cs_push(ops, c);
            }
            else { valid = 0; errorPos = i; break; }
            if (!valid) break;
        }
        while (valid && !cs_empty(ops)) {
            char op;
            cs_pop(ops, &op);
            if (op == '(') { valid = 0; errorPos = len; break; }
            double b, a;
            if (!ds_pop(vals, &b) || !ds_pop(vals, &a)) { valid = 0; errorPos = len; break; }
            ds_push(vals, applyOp(a, b, op));
        }
        if (valid && !ds_empty(vals)) {
            double res;
            ds_pop(vals, &res);
            fprintf(fout, "%lf\n", res);
        }
        else {
            fprintf(fout, "Ошибка в позиции %d\n", errorPos);
        }
        ds_free(vals);
        cs_free(ops);
    }
    fclose(fin);
    fclose(fout);
    printf("Результаты записаны в файл %s\n", outFile);
}
