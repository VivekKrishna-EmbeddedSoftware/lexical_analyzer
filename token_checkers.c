#include"token_checkers.h"
 char operators[]={'/','+','*','-','%','=','<','>','~','&','!','^','|','\0'};
char *res_keywords[] = {
    "const", "volatile", "extern", "auto", "register",
    "static", "signed", "unsigned", "short", "long",
    "double", "char", "int", "float", "struct",
    "union", "enum", "void", "typedef", NULL
};
char *unres_keywords[] = {
    "goto", "return", "continue", "break",
    "if", "else", "for", "while", "do",
    "switch", "case", "default", "sizeof",NULL
};
char token[TOK_MAX_LENGTH];
char sing_char;

int operator_check(FILE *fp)
{
    int i=0;
    while(operators[i])
    {  if(sing_char==operators[i]) 
        {  
       return 1;
        }
        i++;
    }//end of while loop
    return 0;
}
int preprocessor_dir_check(FILE *fp)
{
    //printf("in preprocessor dir\n");
    if(sing_char=='#')
    {   
       // printf("in if\n");
        int i=0;
        while(sing_char!='\n'&&sing_char!=EOF)
        { 
          token[i]=sing_char; 
        sing_char=fgetc(fp);
        i++;
        }
        token[i]='\0';
        printf("%s\n",token);
        return 1;
    }
    else
    return 0;
}
 
int keyword_check(FILE *fp)
{

    //storing the word into token
        int i=0;
        token[0]=sing_char;
        sing_char=fgetc(fp);
        i++;
        while(isalnum(sing_char)||sing_char=='_')
        {
            token[i]=sing_char;
            sing_char=fgetc(fp);
            i++;
        }
        token[i]='\0';//null terminating the token

   
    i=0;
    while(res_keywords[i]!=NULL)
    {
        if(strcmp(token,res_keywords[i])==0)
        return 1;
        i++;
    }
    
    i=0;
    while(unres_keywords[i]!=NULL)
    {
        if(strcmp(token,unres_keywords[i])==0)
        return 2;
        i++;
    }
    return 0;
}

int special_char_check(FILE *fp)
{
    if(sing_char=='(')
    {
        printf("( -> Open brace\n");
    }else if(sing_char==')')
    {
        printf(") -> Closed brace\n");
    }else if(sing_char=='{')
    {
        printf("{ -> Open brace\n");
    }else if(sing_char=='}')
    {
        printf("} -> Closed brace\n");
    }else if(sing_char==';')
    {
        printf("; -> Semicolon\n");      
    }else
    return 0;
}

int const_check(FILE *fp)
{
    if(isdigit(sing_char))
    {
        int i=0;
        while(isdigit(sing_char))
        {
            token[i]=sing_char;
            sing_char=fgetc(fp);
            i++;
        }
        token[i]='\0';
        return 1;
    }else if(sing_char=='"')
    {
        int i=0;
        token[i++]=sing_char;
        sing_char=fgetc(fp);
        while(sing_char!='"')
        {
            token[i]=sing_char;
            sing_char=fgetc(fp);
            i++;
        }
        token[i++]='"';
        token[i]='\0';
        sing_char=fgetc(fp);
        return 2;
        
    }
    return 0;
}