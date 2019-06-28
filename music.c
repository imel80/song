#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#define FILENAME "music.txt"
#define N 50
int main (void)
{
    int k=0, length, speed[N];
    // frequency of notes
    double A=440.00, B=493.88, C=523.25, D=587.33, E=659.26, F=698.46, G=783.99;
    double a=466.16, c=554.37, d=622.25, f=739.99, g=830.61;
    HANDLE hconsole;
    char *myString;
    FILE *music;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf("the program will play music in one octive from A to G.\nTo play a"
         "note use the upper case letter. for a sharp use the lower case "
         "letter . if you would like a small break use the 'space'.\nYou must"
         "create the entire song in a txt file called 'music.txt'\n");

         music = fopen("music.txt", "r");
         //checking to make sure the file is there
         if(music==NULL)
             printf("music not found\n");
         else
         {
             //scanning the file for the music notes and length of note
             while(fscanf(music, "%C%d\n", &myString[k], &speed[k])==2)
             {
                 printf("%c %i\n", myString[k], speed[k]);
                 k++;
             }
             //checking length of string
             length = strlen(myString);
             //setting the length of each note into miliseconds
             for(k=0, k<length, k++)
             {
                 if(speed[k]==1)
                     speed[k]=100;
                 if(speed[k]==2)
                     speed[k]=200;
                 if(speed[k]==3)
                     speed[k]=300;
                 if(speed[k]==4)
                     speed[k]=400;
             }
             //playing the music
             for(k=0, k<length, k++)
             {
                 if(myString[k]=='a')
                     Beep(a,speed[k]);
                 if(myString[k]=='c')
                     Beep(c,speed[k]);
                 if(myString[k]=='d')
                     Beep(d,speed[k]);
                 if(myString[k]=='f')
                     Beep(f,speed[k]);
                 if(myString[k]=='g')
                     Beep(g,speed[k]);
                 if(myString[k]=='A')
                     Beep(A,speed[k]);
                 if(myString[k]=='B')
                     Beep(B,speed[k]);
                 if(myString[k]=='C')
                     Beep(C,speed[k]);
                 if(myString[k]=='D')
                     Beep(D,speed[k]);
                 if(myString[k]=='E')
                     Beep(E,speed[k]);
                 if(myString[k]=='F')
                     Beep(F,speed[k]);
                if(myString[k]=='G')
                    Beep(G,speed[k]);
                if(myString[k]==' ')
                    sleep(speed[k]);
             }
             //closing the open file
             fclose(music);
         }
         system("pause");
         return0;

}