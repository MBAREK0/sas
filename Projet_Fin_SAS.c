

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
double second ;
int i=0,test,found_id;;
int  count=0;
int count_done=0;
double second;
char s[20][20]= {"TO DO","DOING","DONE"};
int year=0,day=0,mounth=0,heuur=0,minut=0;
void MENU()
{
    printf("\n\t\t\t\t\t\t  M   M  EEEEE  N   N  U   U");
    printf("\n\t\t\t\t\t\t  MM MM  E      NN  N  U   U");
    printf("\n\t\t\t\t\t\t  M M M  EEEE   N N N  U   U");
    printf("\n\t\t\t\t\t\t  M   M  E      N  NN  U   U");
    printf("\n\t\t\t\t\t\t  M   M  EEEEE  N   N   UUU ");
    printf("\n\t\t\t ___________________________________________________________________________________ ");
    printf("\n\t\t\t| 1.Ajouter une nouvelle tache            |2.Afficher la liste de toutes les t�ches |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
    printf("\n\t\t\t| 3.Modifier une t�che                    |4.Supprimer une t�che par identifiant    |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
    printf("\n\t\t\t| 5.Rechercher les T�ches                 |6.Statistiques                           |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
    printf("\n\t\t\t|                                         |                                         |");
    printf("\n\t\t\t|                 7. clear                |           0. EXITE                      |");
    printf("\n\t\t\t|_________________________________________|_________________________________________|");
}
//=============================================================================================
//                                                                               ZONE STRUCTE |
//=============================================================================================
typedef struct
{
    char Titre[50];
    char Description[250];
    char Statut[20];
    int  Id;
    int yy,mm,dd,heur;

} NOUVELLE_TACHE;
NOUVELLE_TACHE Tache[100];
NOUVELLE_TACHE TASK;
//=============================================================================================
//                                                                               ZONE deathlien |
//=============================================================================================


double  deathlien(i)
{

    second=(Tache[i].heur)*3600+(Tache[i].dd-15)*24*3600+(Tache[i].mm)*30*24*3600+(Tache[i].yy-1970)*365*24*3600;
    return second;
}
double timenow()
{
    time_t current_time =time(NULL);
    return current_time;
}
//=============================================================================================
//                                                                               ZONE STRUCTE |
//=============================================================================================

void AJOUTER()
{
    printf("\n Titre : ");
    scanf(" %[^\n]s ",Tache[i].Titre);
    printf(" Description : ");
    scanf(" %[^\n]s ",Tache[i].Description);
    strcpy(Tache[i].Statut,s[0]);
    printf(" Statut :%s",Tache[i].Statut);
    printf("\n DEADLINE dd/mm/yy\n");
    printf("\t\t dd : ");
    scanf("%d",&Tache[i].dd);
    printf("\t\t mm : ");
    scanf("%d",&Tache[i].mm);
    printf("\t\t yy : ");
    scanf("%d",&Tache[i].yy);
    printf("\t\t heur : ");
    scanf("%d",&Tache[i].heur);
    deathlien(i);
    count+=1;
    Tache[i].Id=count;
    i++;
    int e ;
    printf("0:EXITE\t | 1: AJOUTER NOUVELLE TACHE\t  \n");
    printf("=> ");
    scanf("%d",&e);
    if(e==0)
    {



    }
    else if(e==1)
    {


        AJOUTER();
    }
    else
        printf("wrong numbre");

}
///////////////////////////////////
float AFDAY(float x)
{
    float day;

    day = x/60/60/24;

    return day;
}
float AFheur(float y)
{
    float heur, r;
    heur = fmod(y,(int)y);
    r =(int)heur*24;

    return r;
}
void AF(int j)
{
    float result;
    result = deathlien(j) - timenow();
    printf("| %-10d | %-20s | %-20s | %-10s | %-6.0f | %-6.0f |\n",
           Tache[j].Id, Tache[j].Titre, Tache[j].Description, Tache[j].Statut, AFheur(AFDAY(result)), AFDAY(result));

}
//=============================================================================================
//                                                                               ZONE STRUCTE |
//=============================================================================================

void AFFICHIER0()
{
    printf("| %-10s | %-20s | %-20s | %-10s | %-6s | %-6s |\n", "ID", "Titre", "Description", "Statut", "Heur", "Day");
    printf("|------------|----------------------|----------------------|------------|--------|--------|\n");

    for (int j = 0; j <i; j++)
    {
        AF(j);
    }
    int e ;
    printf("  1: <--  \t 0:EXITE\t   \n");
    printf("=> ");
    scanf("%d",&e);
    if(e==0)
    {



    }
    else if(e==1)
    {


        AFFICHER();
    }
    else
        printf("wrong numbre");
}


void AFFICHERALPHA()
{

    for(int j=0; j<i; j++)
    {
        for(int m=j+1; m<i; m++)
        {
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
void AFFICHERDEADLINE()
{

    for(int j=0; j<i; j++)
    {
        for(int m=j+1; m<i; m++)
        {
            if(deathlien(j)-timenow()>deathlien(m)-timenow())
            {
                TASK = Tache[j];
                Tache[j] = Tache[m];
                Tache[m] = TASK;
            }
        }
    }

    AFFICHIER0();
}
void AFFICHE3()
{
    for(int j=0; j<i; j++)
    {
        for(int m=j+1; m<i; m++)
        {
            if(deathlien(j)-timenow()>deathlien(m)-timenow())
            {
                TASK = Tache[j];
                Tache[j] = Tache[m];
                Tache[m] = TASK;
            }
        }
    }
    for (int j=0; j<i; j++)
    {
        if((deathlien(j)-timenow())<=259200)AF(j);
    }

}
void AFFICHER()
{
    printf("1:par ordre alphab�tique\n");
    printf("2: par deadline\n");
    printf("3:Afficher les t�ches dont le deadline est dans 3 jours ou moins\n");
    int k;
    printf("enter your choose");
    scanf("%d",&k);
    switch(k)
    {

    case 1:
        AFFICHERALPHA();
        break;
    case 2:
        AFFICHERDEADLINE();
        break;
    case 3:
        AFFICHE3();
        break;
    default:

        printf("wrong number");
        AFFICHER();
    }
}
void Search_by_Title ()
{
    char Rech[20];
    printf("titre de tach");
    scanf("%s",&Rech);
    for(int j=0; j<i; j++)
    {
        if(strcmp(Tache[j].Titre,Rech)==0)AF(j);

    }
}
void Search_by_Id ()
{
    int idi;
    printf("id de tach :");
    scanf("%d",&idi);
    for(int j=0; j<i; j++)
    {
        if(Tache[j].Id==idi) AF(j);
    }
}
void delete_by_id ()
{
    int j=found_index();
    for(int m=j; j<i; j++)Tache[m] = Tache[m+1];
    i--;

}
int found_index()
{
    int Modif,copier_id;
    printf("entrer id of tach you wanna Modifier:");
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
void Modifier_le_statut()
{
    int ms;
    printf("1:DOING\t2:DONE\n");
    printf("entrer your choose: ");
    scanf("%d",&ms);
    // char s[5][5]= {"DOING","DONE"};
    switch(ms)
    {
    case 1:
        strcpy(Tache[found_id].Statut,s[0]);
        break;
    case 2:
        strcpy(Tache[found_id].Statut,s[1]);
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
void Modify()
{
    float result;
    found_id=found_index();
    result = deathlien(found_id) - timenow();
    printf("| %-10d | %-20s | %-20s | %-10s | %-6.0f | %-6.0f |\n",
           Tache[found_id].Id, Tache[found_id].Titre, Tache[found_id].Description,
           Tache[found_id].Statut, AFheur(AFDAY(result)), AFDAY(result));
    printf("1: Modifier_le_statut\n");
    printf("2: Modifier_le_deadline\n");
    printf("3: Modifier_la_description\n");
    int edit;
    printf("enter the task do you want to edit : ");
    scanf("%d",&edit);
    switch(edit)
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
        printf("wronge number ");
        Modify();


    }
}

int Statistiques()
{
    int Stat;
    printf("1:le nombre total des t�ches esAfficher le nombre total des t�ches.\n");
    printf("2:Afficher le nombre de t�ches compl�tes.\n");
    printf("3:Afficher le nombre de t�ches incompl�tes.\n");
    printf("4:Afficher le nombre de jours restants jusqu'au d�lai de chaque t�che.\n");


    printf("enter your choose :");
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
        printf("| %-10s | %-10s | %-6s | %-6s |\n", "ID", "Titre", "Heur", "Day");
        printf("|------------|------------|--------|--------|\n");

        AFFICHIER0();
    }
    break;
    }
}
//////////////////////
int main(void)
{

    int Choose;
    do
    {
        MENU();
        printf("\n\n\t\tentre your choss : ");
        scanf("%d",&Choose);
        switch(Choose)
        {
        case 1:

            AJOUTER();
            break;
        case 2:

            AFFICHER();
            break;
        case 3:

            Modify();
            break;
        case 4:
            delete_by_id ();
            break;
        case 5:
        {

            printf("1: par titre\n\n");
            printf("2: par id \n");
            int Choose1;
            printf("enter your choose : ");
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
        case 6:
            Statistiques();
            break;
        case 7:
            system("cls");
            break;
        }
    }
    while(Choose!=0);
    return (0);
}
