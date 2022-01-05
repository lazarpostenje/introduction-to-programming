#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void obrisi(char *string) {

    char novi[SIZE];
    int k = 0;
    for (int i = 0; i < strlen(string); i++){
        if(string[i] != '*') {
        novi[k] = string[i];
        k++;
        }
    }
    novi[k] = '\0';
    strcpy(string,novi);


}

int main () {

    char mojString[SIZE];
    fgets(mojString, SIZE, stdin);
    mojString[strlen(mojString) - 1 ] = '\0';

    char output[SIZE] = "";

    char pomocnik[SIZE] = "";

    char pomocnik2[SIZE] = "";

    char *token = strtok(mojString, " ");
    char ch[2];

    while(token != NULL){
            int brojac = 0;
            pomocnik[0] = '\0';


            for (int i = 0; i < strlen(token); i++){

                if(token[i] >= 'A' && token[i] <= 'Z') brojac++;

            }
            if (brojac == 0) {
                    //AKO SU SVA MALA SLOVA
                    strcat(output, token);
                    strcat(output, " ");

            }else if (brojac == 1){
                //AKO JE JEDNO VELIKO SLOVO
                    for(int i = 0; i < strlen(token); i++){

                            if (token[i] >= 'a' && token[i] <= 'z'){

                                 ch[0] = token[i];
                                 ch[1] = '\0';
                                strcat(pomocnik,ch);



                            }else {
                                int puta = token[i] - 64;
                                for (int j = puta-1; j >= 0; j--){

                                     ch[0] = 97+j;
                                     ch[1] = '\0';
                                    strcat(pomocnik,ch);

                                }
                                     ch[0] = token[i];
                                     ch[1] = '\0';
                                    strcat(pomocnik,ch);


                                for (int j = 0; j < puta; j++){
                                    ch[0] = 97+j;
                                    ch[1] = '\0';
                                    strcat(pomocnik,ch);

                                }
                            }
                    }
                    strcat(output, pomocnik);
                            strcat(output, " ");


            }else {
                    int prvo = 0;
                    int drugo = 0;
                    pomocnik2[0] = '\0';
                    //AKO SU OBA VELIKA SLOVA
                                for (int i = 0; i < strlen(token); i++){

                                        if(token[i] >= 'A' && token[i] <= 'Z'){

                                        if(prvo == 0) prvo = token[i];
                                        else drugo = token[i];
                                        }
                                }
                    for(int i = 0; i < strlen(token); i++){

                            if(token[i] == prvo){

                                    //LEVA STRANA

                                int puta = prvo - 64;
                                ch[0] = token[i];
                                ch[1] = '\0';
                                strcat(pomocnik2, ch);


                                for (int j = 1; j <= puta; j++){

                                    pomocnik2[i-j] = '*';


                                }
                                prvo = 0;

                            }else if(token[i] == drugo){

                                //DESNA STRANA
                                int puta = drugo - 64;
                                ch[0] = token[i];
                                ch[1] = '\0';
                                strcat(pomocnik2, ch);


                                for (int j = 1; j <= puta; j++){

                                    pomocnik2[i+j] = '*';


                                }
                                i+=puta;

                            }else {

                                ch[0] = token[i];
                                ch[1] = '\0';
                                strcat(pomocnik2, ch);


                            }
                    }
                    obrisi(pomocnik2);
                    strcat(output, pomocnik2);
                    strcat(output, " ");


            }
            pomocnik2[0] = '\0';

        token = strtok(NULL, " ");

    }
    puts(output);




    return 0;
}