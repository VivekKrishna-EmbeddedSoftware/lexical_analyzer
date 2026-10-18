//AUTHOR : ELURI VIVEK KRISHNA
//File description: Does argument validation and executes the application logic.
//Start date:9-10-2026
//End date: 16-06-2026

#include"args_validation.h"
#include"token_checkers.h"
#include<stdio.h>
int main(int argc,char *argv[])
{

    //argument validation
    if(argc==1){
       printf("Usage : ./a.out file_name.c\n");
       return -1;}
    else if(argc==2){
      if(!(is_c_file(argv[1]))){
      printf("The given file is not a c file, only c files are analyzed\n");
       return -1; }
    }else {
      printf("Only one file will be analyzed\n");
      printf("Usage : ./a.out file_name.c");
      return -1;
    }
    

    //opening the .c file
    FILE* fp; 
    if((fp=fopen(argv[1],"r"))==NULL){
        perror("File opening failed ");
        return -1;
    }
    
    //Identifying the tokens 
    int ret;
    sing_char=fgetc(fp); //sing_char-->holds the single char from the file
    int flag=0;
    while(sing_char!=EOF)
    {
        
        if(operator_check(fp)) {                      //checking if it is an operator  
            printf("%c ->  Operator\n",sing_char);
           flag=1;
        }
        else if(preprocessor_dir_check(fp))       //checking if it is a preprocessor directive
        {
             printf(" %s ->  Preprocessor directive\n",token);
             flag=2;
        }
        else if((sing_char>=65&&sing_char<=90)||(sing_char>=97&&sing_char<=122)||sing_char=='_') //checking if the character is alphabet
        {
            //checking the type of token
            ret=keyword_check(fp);
            if(ret==1)
               printf("%s  ->  Reserved keyword\n",token);
            else if(ret==2)
                printf("%s  ->  Unreserved keyword\n",token);
            else
                printf("%s  ->  Identifier\n",token);

            flag=3;
        }
        else if(sing_char==' '){
            while((sing_char=fgetc(fp))==' ');
            flag=4;
        }
        else if(special_char_check(fp)){
            flag=5;
        }
        else if(ret=const_check(fp))
        {
            if(ret==1)
            printf("%s -> Numeric constant\n",token);
            else 
            printf("%s -> String literal constant\n",token);
            
            flag=6;
        }
        
        if(sing_char=='\n')
        while((sing_char=fgetc(fp))=='\n');
        else if (flag==1||flag==5||flag==0)
        sing_char=fgetc(fp);
        
        //printf("%c\n",sing_char);
        
        flag=0;//resetting flag so that again it can be identified whether if char pointer updation is needed
    }
    

}