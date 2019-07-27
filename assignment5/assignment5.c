#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void main()
{
    int strLength;
    char input[10][3];
    FILE *myfile = fopen("input.txt","r");
    int i, j, k, y=0;
    char *RNA[4][4][4]={ {{"UUU","UUC","UUA","UUG"},{"UCU","UCC","UCA","UCG"},{"UAU","UAC","UAA","UAG"},{"UGU","UGC","UGA","UGG"}},
                        {{"CUU","CUC","CUA","CUG"},{"CCU","CCC","CCA","CCG"},{"CAU","CAC","CAA","CAG"},{"CGU","CGC","CGA","CGG"}},
                        {{"AUU","AUC","AUA","AUG"},{"ACU","ACC","ACA","ACG"},{"AAU","AAC","AAA","AAG"},{"AGU","AGC","AGA","AGG"}},
                        {{"GUU","GUC","GUA","GUG"},{"GCU","GCC","GCA","GCG"},{"GAU","GAC","GAA","GAG"},{"GGU","GGC","GGA","GGG"}}};
    char arr[4][4][4]={ {{'F','F','L','L'},{'S','S','S','S'},{'Y','Y','s','s'},{'C','C','s','W'}},
                        {{'L','L','L','L'},{'P','P','P','P'},{'H','H','Q','Q'},{'R','R','R','R'}},
                        {{'I','I','I','M'},{'T','T','T','T'},{'N','N','K','K'},{'S','S','R','R'}},
                        {{'V','V','V','V'},{'A','A','A','A'},{'D','D','E','E'},{'G','G','G','G'}}};

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
            fscanf(myfile,"%c ",&input[i][j]);
    }
    printf("fname:  File content: ");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%c",input[i][j]);
    }
    fclose(myfile);
    printf("\n");
    if(input[0][0]!='A' || input[0][1]!='U' || input[0][2]!='G' )
    {
        printf("Not start with AUG it is not a protein.\n");
    }
    else if((input[9][0]!='U' || input[9][1]!='A' || input[9][2]!='A') && (input[9][0]!='U' || input[9][1]!='A' || input[9][2]!='G') && (input[9][0]!='U' || input[9][1]!='G' || input[9][2]!='A'))
    {
        printf("It is not a protein! No Stop code");
    }
    else
    {
        printf("The amino acids of MyProtein: ");
        for(y=0;y<10;y++)
        {
            for (i=0;i<4;i++)
            {
                for (j=0;j<4;j++)
                {
                    for(k=0;k<4;k++)
                    {
                        strLength = strlen(RNA[i][j][k]);
                        char str[strLength];
                        strcpy(str,RNA[i][j][k]);
                        if(input[y][0]==str[0] && input[y][1]==str[1] && input[y][2]==str[2] )
                        {
                            if(y!=9 && ((input[y][0]=='U' && input[y][1]=='A' && input[y][2]=='A') || (input[y][0]=='U' && input[y][1]=='A' && input[y][2]=='G') || (input[y][0]=='U' && input[y][1]=='G' && input[y][2]=='A')))
                            {
                                printf("\nIt is not a known protein.\nIt is probably a new protein.");
                                exit(1);
                            }
                            else
                            {
                                if(arr[i][j][k]!='s')
                                {
                                    if(y!=8)
                                    {
                                        printf("%c",arr[i][j][k]);
                                        printf("-");
                                    }
                                    else if(y==8)
                                    {
                                        printf("%c",arr[i][j][k]);
                                    }
                                }

                                else
                                    exit(1);
                            }
                        }
                    }
                }
            }
        }
    }
}
