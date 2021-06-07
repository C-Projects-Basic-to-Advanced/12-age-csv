#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 255

typedef struct{
    char name[MAX];
    int day;
    int month;
    int year;
} baby;

typedef struct{
    int d;
    int m;
    int y;
    int total;
} date;

void read_line(char [], FILE*);

int main(){
    FILE *init, *final;
    char line[MAX];
    char *token;
    baby bb;
    date today;
    int age;


    init = fopen("users.csv", "r");
    final = fopen("age_users.csv", "w");
    
    printf("Today's day: ");
    scanf("%i", &today.d);

    printf("Today's month: ");
    scanf("%i", &today.m);

    printf("Today's year: ");
    scanf("%i", &today.y);

    today.total = today.y*365 + today.m*30 + today.d;
    
    while (!feof(init)){
        read_line(line, init);

        token = strtok(line, ";");
        sprintf(bb.name, "%s", token);
    
        token = strtok(NULL, ";");
        bb.day = atoi(token);

        token = strtok(NULL, ";");
        bb.month = atoi(token);

        token = strtok(NULL, ";");
        bb.year = atoi(token);

        age = (today.total - (bb.year*365 + bb.month*30 + bb.day)) / 365;

        fprintf(final,
        "%s;%i\n", bb.name, age);

        }
        
        

    fclose(init);
    fclose(final);
    return 0;
}

void read_line(char txt[], FILE *init){
    
    fgets(txt, MAX, init);
    if (txt[strlen(txt)-1]=='\n')
        txt[strlen(txt)-1]='\0';
}