#include"args_validation.h"
int is_c_file(const char *filename)
{
int len = 0;
    while (filename[len]) len++;
    return (len > 2 && filename[len - 2] == '.' && filename[len - 1] == 'c');
}
