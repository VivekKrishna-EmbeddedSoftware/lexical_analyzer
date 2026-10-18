//Author : Eluri Vivek Krishna
//Date created: 16-10-2026
//File description: contains the declarations for token checker functions and important arrays containing the operators,keywords,etc.
//useful for token checking

#ifndef TOKEN_CHECKERS_H
#define TOKEN_CHECKERS_H
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#define TOK_MAX_LENGTH 100
extern char operators[];
extern char *res_keywords[];
extern char *unres_keywords[];
extern char token[TOK_MAX_LENGTH];
extern char sing_char;
int operator_check(FILE *fp);
int keyword_check(FILE *fp);
int preprocessor_dir_check(FILE *fp);
int special_char_check(FILE *fp);
int const_check(FILE *fp);

#endif 