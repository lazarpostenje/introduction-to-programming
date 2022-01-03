/**
Napisati program koji od dva data stringa P i S pravi treći tako što sve
podstringove stringa P koji se nalaze u zagradi prepisuje u treći string samo ako sadrže
bar dva karaktera koja se nalaze u S i svi karakteri u zagradi koji se nalaze i u S su
pojavljuju u istom redosledu kao karakteri u strigu P. String S sadrži sve različite
karaktere. Podstring u zagradi može da sadrži i karaktere kojih nema u S ili da se
karakteri ponavljaju, bitno je da redosled za sve karaktere bude isti kao u S. Ostali
karakteri, izvan zagrada i u zagradi za koje ne važi pravilo ne pripisuju se u rezultujući
string.
Primer

Unos: P: (dfhhj)fg(adbjbdnc)agh(haj)gh(akjh)
    S: dhj
Ispis: dfhhj haj
**/

#define SIZE 100

int proveri(char *token, char *str2) {
    char kopija[SIZE], pomocnik[SIZE] = "";
    int k = 0;
    strcpy(kopija, token);

    for (int i = 0; i < strlen(token); i++) {
        if (strchr(pomocnik, token[i]) == NULL && strchr(str2, token[i]) != NULL) {
            pomocnik[k++] = token[i];
            pomocnik[k] = '\0';
        }
    }
    if (strstr(str2, pomocnik) != NULL && k > 1) return 1;
    return 0;
}

void obrisi_zagrade(char *str) {
    char novi[SIZE] = "", ch[2];
    for (int i = 1; i < strlen(str)-1; i++) {
        ch[0] = str[i];
        ch[1] = '\0';
        strcat(novi, ch);
    }
    strcpy(str, novi);
}

int main()
{
    char str1[SIZE], str2[SIZE];
    fgets(str1, SIZE, stdin);
    fgets(str2, SIZE, stdin);
    str1[strlen(str1)-1] = '\0';
    str2[strlen(str2)-1] = '\0';

    char novi[SIZE] = "", ch[2];
    int zagrada = 0;

    for (int i = 0; i < strlen(str1); i++) {

        ch[0] = str1[i];
        ch[1] = '\0';

        if (str1[i] == ')') {
            strcat(novi, ch);
            strcat(novi, " ");
            zagrada = 0;
        }
        else if (str1[i] == '(') {
                    zagrada = 1;
                    strcat(novi, ch);
                 }
        else if (zagrada) strcat(novi, ch);
    }

    char pomocnik[SIZE] = "";

    char *token = strtok(novi, " ");
    while (token != NULL) {

        obrisi_zagrade(token);

        if (proveri(token, str2) == 1){
            strcat(pomocnik, token);
            strcat(pomocnik, " ");
        }

        token = strtok(NULL, " ");
    }
    puts(pomocnik);
    return 0;
}