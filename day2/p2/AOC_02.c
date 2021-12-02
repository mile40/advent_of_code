#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct t_pos{
    int x;
    int y;
    int aim;
} pos;

int main(int argc, char** argv){
    FILE* file;
    char * line = NULL;
    size_t len = 0;
    size_t read;
    pos p;
    p.x = 0;
    p.y = 0;
    p.aim = 0;

    file = fopen("./inputs.txt", "r");
    if(file == NULL)
        exit(EXIT_FAILURE);

    while(read = getline(&line, &len, file) != -1){

        if(strstr(line, "forward")){
            p.x += atoi(line+7);
            p.y += atoi(line+7) * p.aim;
        }

        if(strstr(line, "down")){
            p.aim += atoi(line+4);
        }

        if(strstr(line, "up")){
            p.aim -= atoi(line+2);
        }
    }

    fclose(file);
    if(line)
        free(line);
    printf("result: %d\n", p.x*p.y);
    return 0;
}