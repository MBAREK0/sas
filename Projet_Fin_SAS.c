#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
//=============================================================================================
//                                                                             variables ZONE  |
//=============================================================================================
double second ;
short int i=0, found_id, count=0, count_done=0,
          year=0,day=0,mounth=0,heuur=0,minut=0;
char s[3][10]= {"TO DO","DOING","DONE"};
//=============================================================================================
//                                                                                  menu ZONE  |
//=============================================================================================
void MENU()
{
    printf("\n\t\t\t\t\t\t  M   M  EEEEE  N   N  U   U");
    printf("\n\t\t\t\t\t\t  MM MM  E      NN  N  U   U");
    printf("\n\t\t\t\t\t\t  M M M  EEEE   N N N  U   U");
    printf("\n\t\t\t\t\t\t  M   M  E      N  NN  U   U");
    printf("\n\t\t\t\t\t\t  M   M  EEEEE  N   N   UUU ");
    printf("\n\t\t\t ___________________________________________________________________________________ ");
    printf("\n\t\t\t|        1. Add a new task                |    2. Display the list of all tasks     |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
    printf("\n\t\t\t|        3. Modify a task                 |    4. Delete a task by ID               |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
    printf("\n\t\t\t|        5. Search Tasks                  |    6. Statistics                        |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
    printf("\n\t\t\t|                                         |                                         |");
    printf("\n\t\t\t|               7. Clear                  |              0. EXIT                    |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
}
//=============================================================================================
//                                                                               STRUCTE ZONE  |
//=============================================================================================
typedef struct
{
    char Titre[50];
    char Description[250];
    char Statut[20];
    int  Id,
         yy,mm,dd,heur;
} NOUVELLE_TACHE;
NOUVELLE_TACHE Tache[100];
NOUVELLE_TACHE TASK;
//=============================================================================================
//                                                                              deadline ZONE  |
//=============================================================================================
double  Change_date_to_seconds(i)
{
    second=(Tache[i].heur)*3600+(Tache[i].dd-15)*24*3600
           +(Tache[i].mm)*30*24*3600+(Tache[i].yy-1970)*365*24*3600;
    return second;
}
double timenow()
{
    time_t current_time =time(NULL);
    return current_time;
}
float AFDAY(float x)  //-------------------------------------------------- change secons to days
{
    float day;
    day = x/60/60/24;
    return day;
}
float AFheur(float y) //---------------------------------------------------change secons to hour
{
    float heur;
    heur =(int)(fmod(y,(int)y)*24);
    return heur;
}
//=============================================================================================
//                                                                                   add ZONE  |
//=============================================================================================

void AJOUTER()
{
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t Titre : ");
    scanf(" %[^\n]s ",Tache[i].Titre);
    printf("\t Description : ");
    scanf(" %[^\n]s ",Tache[i].Description);
    strcpy(Tache[i].Statut,s[0]);
    printf("\t Statut :%s\n",Tache[i].Statut);
    printf("\t DEADLINE dd/mm/yy\n");
    printf("\t\t\t dd : ");
    scanf("%d",&Tache[i].dd);
    printf("\t\t\t mm : ");
    scanf("%d",&Tache[i].mm);
    printf("\t\t\t yy : ");
    scanf("%d",&Tache[i].yy);
    printf("\t\t\t heur : ");
    scanf("%d",&Tache[i].heur);
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    Change_date_to_seconds(i);
    count+=1;
    Tache[i].Id=count;
    i++;
    int Choose1 ;
    printf(" | 0:EXITE\t  |  1: NEW TASK   |");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("             ==> ");
    scanf("%d",&Choose1);
    if(Choose1==1) AJOUTER();
}
//=============================================================================================
//                                                                               Display ZONE  |
//=============================================================================================
void AF(int j)         // ----------------------------------Display the informatiion of one task
{
    float result;
    result = Change_date_to_seconds(j) - timenow();
    printf("| %-10d | %-20s | %-20s | %-10s | %-6.0f | %-6.0f |\n",
           Tache[j].Id, Tache[j].Titre, Tache[j].Description, Tache[j].Statut,
           AFDAY(result), AFheur(AFDAY(result)));
}
void AFFICHIER0()   // ---------------------------------------Display the informatiion of tasks
{
    printf("| %-10s | %-20s | %-20s | %-10s | %-6s | %-6s |\n", "ID", "Titre", "Description", "Statut","Day","Heur");
    printf("|------------|----------------------|----------------------|------------|--------|--------|\n");

    for (int j = 0; j <i; j++)
    {
        AF(j);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int Choose1 ;
    printf("\n\t  1: <--  \t 0:EXITE\t   \n");
    printf("=> ");
    scanf("%d",&Choose1);
    if(Choose1==1)AFFICHER_Mom();
}
void AFFICHERALPHA() //-------------------------- Display the informatiion of tasks by alpha ordre
{
    for(int j=0; j<i; j++)
    {
        for(int m=j+1; m<i; m++)
        {
            to_upper(Tache[j].Titre);
            to_upper(Tache[m].Titre);
            if(strcmp(Tache[j].Titre, Tache[m].Titre)>0)
            {
                TASK = Tache[j];
                Tache[j] = Tache[m];
                Tache[m] = TASK;
            }
        }
    }
    AFFICHIER0();
}
void AFFICHER_DEADLINE()  // ----------------------Display tasks with a deadline of 3 days or less
{

    for(int j=0; j<i; j++)
    {
        for(int m=j+1; m<i; m++)
        {
            if(Change_date_to_seconds(j)-timenow()>Change_date_to_seconds(m)-timenow())
            {
                TASK = Tache[j];
                Tache[j] = Tache[m];
                Tache[m] = TASK;
            }
        }
    }

    AFFICHIER0();

}
void AFFICHE_3_day_or_less()
{
    for(int j=0; j<i; j++)
    {
        for(int m=j+1; m<i; m++)
        {
            if(Change_date_to_seconds(j)-timenow()>Change_date_to_seconds(m)-timenow())
            {
                TASK = Tache[j];
                Tache[j] = Tache[m];
                Tache[m] = TASK;
            }
        }
    }
    int test =0;
    printf("| %-10s | %-20s | %-20s | %-10s | %-6s | %-6s |\n", "ID", "Titre", "Description", "Statut","Day","Heur");
    printf("|------------|----------------------|----------------------|------------|--------|--------|\n");

    for (int j=0; j<i; j++)
    {
        if((Change_date_to_seconds(j)-timenow())<=259200) //------- 3 days in seconds is 259200
        {
            AF(j);
            test++;
        }
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    if(test==0)printf("\n\t\t NO_THING!\n");
    int Choose1 ;
    printf("\n\t  1: <--  \t 0:EXITE\t   \n");
    printf("=> ");
    scanf("%d",&Choose1);
    if(Choose1==1)AFFICHER_Mom();

}
void AFFICHER_Mom() // ---------------------------------------------main display function
{
    printf("\n\t\t1: in alphabetical order\n");
    printf("\t\t2: by deadline\n");
    printf("\t\t3: Display tasks with a deadline of 3 days or less\n");
    int Choose1;
    printf("\nenter your choose : ");
    scanf("%d",&Choose1);
    switch(Choose1)
    {
    case 1:
        AFFICHERALPHA();
        break;
    case 2:
        AFFICHER_DEADLINE();
        break;
    case 3:
        AFFICHE_3_day_or_less();
        break;
    default:
        printf("wrong number");
        AFFICHER_Mom();
    }
}
//=============================================================================================
//                                                                                Search ZONE  |
//=============================================================================================
void to_upper(char str[]) //------------------------------------- change the title to uppercase
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        str[i] = toupper(str[i]);
    }

}
void Search_by_Title ()
{
    char Choose1[20];
    printf("\n\n\t\tENTER THE TASK TITLE : ");
    scanf("%s",&Choose1);
    to_upper(Choose1); // make choose capitel

    printf("| %-10s | %-20s | %-20s | %-10s | %-6s | %-6s |\n", "ID", "Titre", "Description", "Statut","Day","Heur");
    printf("|------------|----------------------|----------------------|------------|--------|--------|\n");
    for(int j=0; j<i; j++)
    {
        to_upper(Tache[j].Titre);// make titre capitel
        if(strcmp(Tache[j].Titre,Choose1)==0)
        {
            AF(j) ;
            break;
        }
    }
}
void Search_by_Id ()
{
    int Choose1;
    printf("ENTER THE ID OF THE TASK : ");
    scanf("%d",&Choose1);
    printf("| %-10s | %-20s | %-20s | %-10s | %-6s | %-6s |\n", "ID", "Titre", "Description", "Statut","Day","Heur");
    printf("|------------|----------------------|----------------------|------------|--------|--------|\n");
    for(int j=0; j<i; j++)
    {
        if(Tache[j].Id==Choose1)
        {
            AF(j) ;
            break;
        }
    }
}

//=============================================================================================
//                                                                                delete ZONE  |
//=============================================================================================
int found_index() //-------------------- find the index of task to use it in defrance fonctions
{
    int Modif,copier_id;
    printf("Enter the ID of the task you want to Modify or Delete: ");
    scanf("%d",&Modif);
    for(int j=0; j<i; j++)
    {
        if(Tache[j].Id==Modif)
        {
            copier_id=j;
        }
    }
    return copier_id;
}
void delete_by_id ()
{
    int j=found_index();
    if(strcmp(Tache[j].Statut,s[2])==0)count_done--;
    for(int m=j; m<i; m++)
    {
        Tache[m] = Tache[m+1];
    }
    i--;
}
//=============================================================================================
//                                                                              Modifier ZONE  |
//=============================================================================================

void Modifier_le_statut()
{
    int Choose1;
    printf("\n\t\t1:DOING\t2:DONE\n");
    printf("\nenter your choose: ");
    scanf("%d",&Choose1);
    switch(Choose1)
    {
    case 1:
        strcpy(Tache[found_id].Statut,s[1]);
        break;
    case 2:
        strcpy(Tache[found_id].Statut,s[2]);
        count_done++;
        break;
    default:
        printf("wronge number ");
        Modifier_le_statut();
    }
}
void Modifier_le_deadline()
{
    printf("\n entre the new DEADLINE dd/mm/yy\n");
    printf("\t\t dd : ");
    scanf("%d",&Tache[found_id].dd);
    printf("\t\t mm : ");
    scanf("%d",&Tache[found_id].mm);
    printf("\t\t yy : ");
    scanf("%d",&Tache[found_id].yy);
    printf("\t\t heur : ");
    scanf("%d",&Tache[found_id].heur);
}
void Modifier_la_description()
{
    printf(" Description : ");
    scanf(" %[^\n]s ",Tache[found_id].Description);
}
void Modify() //------------------------------------------------- main Modify function
{
    float result;
    found_id=found_index();
    result = Change_date_to_seconds(found_id) - timenow();
    printf("| %-10d | %-20s | %-20s | %-10s | %-6.0f | %-6.0f |\n",
           Tache[found_id].Id, Tache[found_id].Titre, Tache[found_id].Description,
           Tache[found_id].Statut, AFheur(AFDAY(result)), AFDAY(result));
    printf("1: Modify the status\n");
    printf("2: Modify the deadline\n");
    printf("3: Modify the description\n");
    int Choose1;
    printf("enter the task do you want to modify : ");
    scanf("%d",&Choose1);
    switch(Choose1)
    {
    case 1:
        Modifier_le_statut();

        break;
    case 2:
        Modifier_le_deadline();

        break;
    case 3:
        Modifier_la_description();

        break;
    default:
        printf("wrong number ");
        Modify();
        break;
    }
}
//=============================================================================================
//                                                                          Statistiques ZONE  |
//=============================================================================================
int Statistiques()
{
    int Stat;
    printf("\t\t1: Display the total number of tasks.\n");
    printf("\t\t2: Display the number of completed tasks.\n");
    printf("\t\t3: Display the number of incomplete tasks.\n");
    printf("\t\t4: Display the number of days remaining until the deadline for each task.\n");
    printf("\nenter your choose :");
    scanf("%d",&Stat);
    switch(Stat)
    {
    case 1:
        printf("le nombre total des t�ches est : %d",i);
        break;
    case 2:
        printf("le nombre de taches completes est : %d",count_done);
        break;
    case 3:
        printf("le nombre de taches incompletes est : %d",i-count_done);
        break;
    case 4:
    {
        printf("|----------------------|--------|--------|\n");
        printf("| %-20s | %-6s | %-6s |\n", "Titre", "Day", "Hour");
        printf("|----------------------|--------|--------|\n");
        for(int j = 0; j<i; j++)
        {
            float result;
            result = Change_date_to_seconds(j) - timenow();
            printf("| %-20s | %-6.0f | %-6.0f |\n", Tache[j].Titre, AFDAY(result), AFheur(AFDAY(result)));
            printf("|----------------------|--------|--------|\n");
        }
    }
    break;
    }
}
//=============================================================================================
//                                                                                  main ZONE  |
//=============================================================================================

int main(void)
{
    int Choose;

    MENU();
    printf("\n\n\t\tentre your choss : ");
    scanf("%d",&Choose);
    switch(Choose)
    {
    case 0:
        return 0;
        break;
    case 1:
        AJOUTER();
        main();
        break;
    case 2:

        AFFICHER_Mom();
        main();
        break;
    case 3:

        Modify();
        main();
        break;
    case 4:
        delete_by_id();
        main();
        break;
    case 5:
    {
        printf("\n1: par titre\t");
        printf("2: par id \n");
        int Choose1;
        printf("\nenter your choose : ");
        scanf("%d",&Choose1);
        switch(Choose1)
        {
        case 1:
            Search_by_Title ();
            break;
        case 2:
            Search_by_Id ();
            break;
        }
    }
    main();
    break;
    case 6:
        Statistiques();
        main();
        break;
    case 7:
        system("cls");
        main();
        break;
       // default : main();break;
    }
    return (0);
}
