#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void meni(){

    printf("\n\n1. Load a file\n");
    printf("2. Show the file\n");
    printf("3. Number of goals per team(iteratively)\n");
    printf("4. Number of goals per team(recursively)\n");
    printf("5. Genereate table\n");
    printf("6. Exit\n");



}

typedef struct team{

    char name;
    int points;
    int scored_goals;
    int received_goals;
    struct team *next;


}TEAM;

typedef struct match{

    int year;
    int month;
    int day;
    char team1;
    char team2;
    int team1_goal;
    int team2_goal;
    struct match *next;

}MATCH;

TEAM *make_new_team(char name, int points, int scored_goals, int received_goals){

    TEAM *neww = (TEAM*) malloc(sizeof(TEAM));

    neww->name = name;
    neww->points = points;
    neww->scored_goals = scored_goals;
    neww->received_goals = received_goals;
    neww->next = NULL;

    return neww;

}

TEAM *sort_team(TEAM *head, char name, int points, int scored_goals, int received_goals){

    TEAM *neww = make_new_team(name, points, scored_goals, received_goals);

    if(head == NULL){

        head = neww;
        return head;

    }

    printf("a\n");

    TEAM *tmp = head;

    if(points > tmp->points && abs(tmp->scored_goals - tmp->received_goals) < abs(scored_goals - received_goals) ){

        neww->next = head;
        head = neww;
        return head;

    }

    while(tmp->next != NULL && ((tmp->next->points > points) ||
                                (tmp->next->points == points && abs(tmp->next->scored_goals - tmp->next->received_goals) > abs(scored_goals - received_goals) ) ) ){

        tmp = tmp->next;

    }

    neww->next = tmp->next;
    tmp->next = neww;

    return head;

}

void print_team(TEAM *head){

    if(head == NULL){printf("\n"); return;}

    printf("%c %d %d %d\n", head->name, head->points, head->scored_goals, head->received_goals);
    print_team(head->next);

}

TEAM *generate(MATCH *head, TEAM *vugla){

    for(int i = 'a'; i <= 'z'; i++){

        MATCH *tmp = head;

        int points = 0;
        int flag = 0;
        int scored_goals = 0;
        int received_goals = 0;

        while(tmp){

            if(tmp->team1 == i){

                if(tmp->team1_goal > tmp->team2_goal) points += 3;
                else if(tmp->team1_goal == tmp->team2_goal) points += 1;

                scored_goals += tmp->team1_goal;
                received_goals += tmp->team2_goal;
                flag = 1;

            } else if(tmp->team2 == i){

                if(tmp->team2_goal > tmp->team1_goal) points += 3;
                else if(tmp->team2_goal == tmp->team1_goal) points += 1;

                flag = 1;
                scored_goals += tmp->team2_goal;
                received_goals += tmp->team1_goal;

            }

            tmp = tmp->next;
        }

        if(flag) vugla = sort_team(vugla, i, points, scored_goals, received_goals);

    }

    return vugla;

}

MATCH *make_new_match(int year, int month, int day, char team1, char team2, int team1_goal, int team2_goal){
        MATCH *neww = (MATCH*)malloc(sizeof(MATCH));
        neww->year = year;
        neww->month = month;
        neww->day = day;
        neww->team1 = team1;
        neww->team2 = team2;
        neww->team1_goal = team1_goal;
        neww->team2_goal = team2_goal;
        neww->next = NULL;

        return neww;
}

MATCH *sort_by_date(MATCH *head, int year, int month, int day, char team1, char team2, int team1_goal, int team2_goal){
    MATCH *neww = make_new_match(year,month,day,team1,team2,team1_goal,team2_goal);
    if (head == NULL){
        head = neww;
        return head;
    }
    MATCH *tmp = head;

    if (tmp->month > month || (tmp->month == month && tmp->day > day)){

            neww->next = head;
            head = neww;
            return head;
        }

        while (tmp->next != NULL && (tmp->next->month < month || (tmp->next->month == month && tmp->next->day < day))){

            tmp = tmp->next;
        }
        neww->next = tmp->next;
        tmp->next = neww;

        return head;


}

MATCH *load(MATCH *head, char *file){
    int counter;
    char line[SIZE];
    FILE *fp = fopen(file, "r");
    int year;
    int month;
    int day;
    char team1;
    char team2;
    int team1_goal;
    int team2_goal;

    while(fgets(line,sizeof(line),fp)){
            counter = 0;
        for (int i = 0; i < strlen(line); i++){
            if(line[i] == ' ') line[i] = '-';
        }
        char *token = strtok(line, "-");

        while(token != NULL){
            if(counter == 0) year = atoi(token);
            if(counter == 1) month = atoi(token);
            if(counter == 2) day = atoi(token);
            if(counter == 3) team1 = token[0];
            if(counter == 4) team2 = token[0];
            if(counter == 5) team1_goal = atoi(token);
            if(counter == 6) team2_goal = atoi(token);


            counter++;
            token = strtok(NULL, "-");
        }


        head = sort_by_date(head, year, month, day, team1, team2, team1_goal, team2_goal);



    }



    return head;

}

void print_file(MATCH *head){
        if(head == NULL){ printf("\n"); return;}
        printf("%d-%d-%d %c %c %d %d\n", head->year, head->month, head->day, head->team1, head->team2, head->team1_goal, head->team2_goal);
        print_file(head->next);

}

void number_of_goals(MATCH *head, char ch){

        int NumberOfGoals = 0;
            MATCH *tmp = head;

            while(tmp != NULL){
                if (tmp->team1 == ch) NumberOfGoals += tmp->team1_goal;
                if (tmp->team2 == ch) NumberOfGoals += tmp->team2_goal;

                tmp = tmp->next;
            }
            if (NumberOfGoals > 0) printf("\nTeam %c has scored %d goals\n\n", ch, NumberOfGoals);

}

void number_of_goals_rec(MATCH *head, char ch, int NumberOfGoals){

    if(head == NULL) {printf("\nTeam %c has scored %d goals\n\n", ch, NumberOfGoals); return;}

    if(head->team1 == ch) NumberOfGoals += head->team1_goal;
    if(head->team2 == ch) NumberOfGoals += head->team2_goal;

    number_of_goals_rec(head->next, ch, NumberOfGoals);
}


int main () {

    int option;
    char file[SIZE];
    MATCH *head = NULL;
    TEAM *vugla = NULL;
    char team;

    while(1){
        printf("Choose option : \n");
        meni();
        scanf("%d", &option);

        if (option == 1){
            printf("Enter the name of the file : ");
            scanf("%s", file);

            head = load(head, file);

        }else if (option == 2){

            print_file(head);

        }else if (option == 3){
            printf("Enter the name of the team: ");
            scanf(" %c", &team);
            number_of_goals(head, team);

        }else if(option == 4){

            printf("Enter the name of the team: ");
            scanf(" %c", &team);
            number_of_goals_rec(head, team, 0);

        }else if(option == 5){

            vugla = generate(head, vugla);
            print_team(vugla);

        }
        else if (option == 6){
                break;
        }

    }

    return 0;
}
