#include <stdio.h>

FILE* fp;
FILE* wf;

#define True 1
#define Flase 0

void split(char line[], char *pieces[])
{
    int linecounter=0;
    int wordcounter=0;
    //outer loop for my word
    while(line[linecounter]!='\0')
    {
        int lettercounter=0;
        //inner loop for my letter
        while (line[linecounter]!=' ' && line[linecounter]!='\0')
        {
            char tocopy = line[linecounter];
            pieces[wordcounter][lettercounter]=tocopy;

            lettercounter++;
            linecounter++;
        }
        pieces[wordcounter][lettercounter]='\0';
        if (line[linecounter]=='\0')
            break;
        wordcounter++;
        linecounter++;
    }
}

void shell(){
    printf("Welcome to Andreas's Shell\n");

    char line[10];

    int i;
    int a;
    int c;
    int rem;
    int pid;
    int size;
    char file_char;
    char args[1][1];
    a=1;
    while(True)
    {
        printf("awiede$ ");
        for(i=0; i<100; i++)
        {
            //printf("begin for loop\n");
            line[i]=getchar();
            if(line[i]=='\n') {
                a=0;
                line[i]='\0';
                i=101;
            }
        }
        printf("end for loop\n");

        printf("The input is %s and nothing else. \n",line);
        //printf("strcmp of line and exit is %i\n", strcmp(line,'exit'));
        if(strcmp(line,"exit")==0)
        {
            printf("Terminating Shell\n");
            break;
        }
        else if(strncmp(line,"type",4)==0)
        {
            printf("In the type if statement\n");
            char command[4];
            char file_name[50];
            char* pieces[2];
            pieces[0]=command;
            pieces[1]=file_name;

            split(line, pieces);
            printf("pieces[0] is: %s\n", pieces[0]);
            printf("pieces[1] is: %s\n", pieces[1]);

            fp=fopen(pieces[1],"r");
            //fprintf(stderr, "%s\n", );
            while(1)
            {
                c = fgetc(fp);
                if(feof(fp))
                    break;
                printf("%c", c);
            }
            printf("\n");
            fclose(fp);
        }
        else if (strncmp(line,"copy",4)==0)
        {
            printf("In the Copy if statement.\n");
            char command[4];
            char file_name1[50];
            char file_name2[50];
            char* pieces[3];
            pieces[0]=command;
            pieces[1]=file_name1;
            pieces[2]=file_name2;
            split(line, pieces);

            printf("pieces[0]: %s\n", pieces[0]);
            printf("pieces[1]: %s\n", pieces[1]);
            printf("pieces[2]: %s\n", pieces[2]);

            fp=fopen(pieces[1],"r");
            wf=fopen(pieces[2],"w");

            while(1)
            {
                c = fgetc(fp);
                if(feof(fp))
                    break;
                fputc(c,wf);
            }
            fclose(fp);
            fclose(wf);
        }
        else if(strncmp(line, "delete",6)==0)
        {
            printf("In the delete if statement\n");
            char command[6];
            char file_name[50];
            char* pieces[2];
            pieces[0]=command;
            pieces[1]=file_name;
            split(line,pieces);
            printf("pieces[1]: %s\n", pieces[1]);
            //fp=fopen(pieces[1],"w");
            remove(pieces[1]);
            //rem=remove(fp);
            //printf("Remove: %i\n", rem);
        }
        else
        {
            printf("Inside the else statement. \n");
            pid = fork();
            if (pid==0)
            {
                
                char path[50];
                char command1[50];
                char command2[50];
                char* pieces[4];
                char* arg1[1];
                char* arg2[3];
                pieces[0]=path;
                pieces[1]=command1;
                pieces[2]=command2;
                pieces[3]="\0";
                split(line, pieces);
                size=0;
                for(i=1;i<4; i++)
                {
                    printf("In for loop\n");
                    printf("pieces i 0 %i\n", pieces[i][0]);
                    if (pieces[i][0]!=0)
                        size++;
                    else
                        break;
                }
                pieces[size+1]=0;
                printf("pieces 0 %s\n", pieces[0]);
                printf("pieces 1 %s\n", pieces[1]);
                printf("peices 2 %s\n", pieces[2]);
                printf("size %i\n", size);
                //arg2[1]=pieces[2];
                //arg2[2]='\0';
                //args[0][0]='\0';
                execvp(pieces[0], pieces);
                
                //execvp(line);
            }
            else if (pid!=0)
            {
                wait();
            }
        }
    }    
    printf("Shell Terminated\n");
}

main(){
    shell();
}