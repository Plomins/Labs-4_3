#ifndef STACK_H
#define STACK_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <locale.h>

typedef struct {
    int* data;
    int top;
    int cap;
} Stack;

Stack* st_create(int cap);
void st_free(Stack* s);
int st_push(Stack* s, int val);
int st_pop(Stack* s, int* val);
int st_empty(Stack* s);


typedef struct {
    double* data;
    int top;
    int cap;
} DStack;

DStack* ds_create(int cap);
void ds_free(DStack* s);
int ds_push(DStack* s, double val);
int ds_pop(DStack* s, double* val);
int ds_empty(DStack* s);


typedef struct {
    char* data;
    int top;
    int cap;
} CStack;

CStack* cs_create(int cap);
void cs_free(CStack* s);
int cs_push(CStack* s, char val);
int cs_pop(CStack* s, char* val);
int cs_empty(CStack* s);

#endif
