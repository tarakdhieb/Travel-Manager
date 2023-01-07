#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct date {
    int jj,mm,aa;
}date;

struct voyage {
    int id;
    char destination[50];
    char description[200];
    int nbPlaces;
    int nbPlacesRestantes;
    date dateDebut, dateFin ;
    struct voyage *suivant;
};
struct voyage *premierVoyage = NULL;

date saisie(){
    date d ;
    int n ;
     do
{
    fflush(stdin);
    n=scanf("%d:%d:%d",&d.jj,&d.mm,&d.aa);
}while(!(n==3&&d.jj>=1&&d.mm>=1&&d.aa>=22&&d.jj<31&&d.mm<13&&d.aa<25));
return d ;
}
void ajouterVoyage() {
    system("cls");
    struct voyage *nouveauVoyage = malloc(sizeof(struct voyage));
    if (nouveauVoyage == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        printf("\t\t\t\t   Appuyez sur entrer pour revenir au menu ");
        getch();
        return;
    }
    printf("\t\t\t_____________________________________________________________________\n\n");
    printf("\t\t\t\t\t\tAjout d'un voyage\n");
    printf("\t\t\t_____________________________________________________________________\n");
    printf("\t\t\tDestination : ");
    scanf("%s", nouveauVoyage->destination);
    printf("\n\t\t\tDescription : ");
    scanf("%s", nouveauVoyage->description);
    printf("\n\t\t\tNombre de places : ");
    scanf("%d", &nouveauVoyage->nbPlaces);
    printf("\n\t\t\tDate de debut jj:mm:aa : ");
    nouveauVoyage->dateDebut = saisie() ;
    printf("\n\t\t\tDate de fin jj/mm/aa : ");
    nouveauVoyage->dateFin = saisie();
    nouveauVoyage->nbPlacesRestantes = nouveauVoyage->nbPlaces;

    static int id = 1;
    nouveauVoyage->id = id++;
    nouveauVoyage->suivant = premierVoyage;
    premierVoyage = nouveauVoyage;
     FILE *fichier = fopen("voyages.txt", "a");
    if (fichier == NULL) {
        printf("Erreur d'ouverture du fichier !\n");
        printf("\t\t\t\tAppuyez sur entrer pour revenir au menu ");
        getch();
        return;
    }   
    fprintf(fichier, "%d,%s,%s,%d,%d,%d:%d:%d,%d:%d:%d\n", nouveauVoyage->id, nouveauVoyage->destination, nouveauVoyage->description, nouveauVoyage->nbPlaces, nouveauVoyage->nbPlacesRestantes, nouveauVoyage->dateDebut.jj, nouveauVoyage->dateDebut.mm, nouveauVoyage->dateDebut.aa, nouveauVoyage->dateFin.jj, nouveauVoyage->dateFin.mm, nouveauVoyage->dateFin.aa);
fclose(fichier);
printf("\t\t\t\tAppuyez sur entrer pour revenir au menu ");
getch();
return;
}
void enregistrer() {
    FILE* f;
    f = fopen("voyages.txt","w");
    struct voyage *actuel = premierVoyage;
    while (actuel == NULL){
        char ligne[300];
        sprintf(ligne,"%d,%s,%s,%d,%d,%d:%d:%d,%d:%d:%d\n", actuel->id, actuel->destination, actuel->description, actuel->nbPlaces, actuel->nbPlacesRestantes, actuel->dateDebut.jj, actuel->dateDebut.mm, actuel->dateDebut.aa, actuel->dateFin.jj, actuel->dateFin.mm, actuel->dateFin.aa);
        fputs(ligne,f);
        actuel = actuel->suivant;
    }
}
void supprimerVoyage() {
system("cls");
int id;
printf("\t\t___________________________________________________________\n\n");
printf("\t\t\t\tID du voyage : \n");
printf("\t\t___________________________________________________________\n\n");
scanf("%d", &id);
if (premierVoyage == NULL) {
printf("\t\t\t\tAucun voyage a supprimer !\n");
printf("\t\t\tAppuyez sur entrer pour revenir au menu ");
getch();
return;
}
if (premierVoyage->id == id) {
    struct voyage *aSupprimer = premierVoyage;
    premierVoyage = premierVoyage->suivant;
    free(aSupprimer);
    printf("\t\t\t\tC'est bon\n\t\t\tAppuyez sur entrer pour revenir au menu ");
    getch();
    return;
}
struct voyage *actuel = premierVoyage;
while (actuel->suivant != NULL) {
    if (actuel->suivant->id == id) {
        struct voyage *aSupprimer = actuel->suivant;
        actuel->suivant = actuel->suivant->suivant;
        free(aSupprimer);
        enregistrer();
        printf("\t\t\t\tC'est bon\n\t\t\tAppuyez sur entrer pour revenir au menu ");
        getch();
        return;
    }
    actuel = actuel->suivant;
}
printf("\t\t\t\tVoyage %d introuvable !\n", id);
printf("\t\t\tAppuyez sur entrer pour revenir au menu ");
getch();
return;
}
void modifierVoyage() {
system("cls");
int id;
printf("\t\t___________________________________________________________\n\n");
printf("\t\t\t\tID du voyage : ");
printf("\n\t\t___________________________________________________________\n\n");
scanf("%d", &id);
struct voyage *actuel = premierVoyage;
while (actuel != NULL) {
if (actuel->id == id) {
printf("\t\t\tModification du voyage %d\n", id);
printf("\t\t\tDestination (%s) : ", actuel->destination);
scanf("%s", actuel->destination);
printf("\t\t\tDescription (%s) : ", actuel->description);
scanf("%s", actuel->description);
printf("\t\t\tNombre de places (%d) : ", actuel->nbPlaces);
scanf("%d", &actuel->nbPlaces);
actuel->nbPlacesRestantes = actuel->nbPlaces;
printf("\t\t\tDate de debut (%d:%d:%d) : ", actuel->dateDebut.jj, actuel->dateDebut.mm, actuel->dateDebut.aa);
actuel->dateDebut = saisie();
printf("\t\t\tDate de fin (%d:%d:%d) : ", actuel->dateFin.jj, actuel->dateFin.mm, actuel->dateFin.aa);
actuel->dateFin = saisie();
printf("\t\t\t\tAppuyez sur entrer pour revenir au menu ");
getch();
return;
}
actuel = actuel->suivant;
}
printf("Voyage %d introuvable !\n", id);
printf("\t\t\t\tAppuyez sur entrer pour revenir au menu ");
getch();
return;
}
void afficherDescriptionVoyage() {
    system("cls");
     printf("\t\t__________________________________\n\n");
    printf("\t\t\tID du voyage : \n");
    printf("\t\t__________________________________\n");
    int id;
    scanf("%d", &id);
    struct voyage *actuel = premierVoyage;
    while (actuel != NULL) {
        if (actuel->id == id) {
            printf("\t\tDescription du voyage %d : %s\n", id, actuel->description);
            printf("\t\tAppuyez sur entrer pour revenir au menu ");
            getch();
            return;
        }
      actuel = actuel->suivant;
    }
    printf("\t\t\tVoyage %d introuvable !\n", id);          
    printf("\t\t\tAppuyez sur entrer pour revenir au menu ");
    getchar();
}
void afficherVoyagesDisponibles() {
system("cls");
printf("\t\t\tDate de debut jj:mm:aa : ");
char dateDebut[20];
scanf("%s", dateDebut);
printf("\n\t\t\tDate de fin jj:mm:aa : ");
char dateFin[20];
scanf("%s", dateFin);
struct voyage *actuel = premierVoyage;
int i = 0;
printf("\t\t_____________________________________________\n");
while (actuel != NULL) {
    char jjd[2], mmd[2], aad[2], jjf[2], mmf[2], aaf[2];
    char dateDebuta[9], dateFina[9];
    sprintf(dateDebuta, "%d:%d:%d", jjd, mmd, aad);
    sprintf(dateFina, "%d:%d:%d", jjf, mmf, aaf);
    if (strcmp(dateDebuta, dateDebut) >= 0 && strcmp(dateFina, dateFin) <= 0 && actuel->nbPlacesRestantes > 0) {
        printf("\n\t\t\tVoyage %d : %s (%d places disponibles)\n", actuel->id, actuel->destination, actuel->nbPlacesRestantes);
        i++;
    }
    actuel = actuel->suivant;
}
if (i==0){
    printf("\t\t\til'y a pas de voyages pour le moments\n");
}
printf("\t\tAppuyez sur entrer pour revenir au menu ");
getchar();
return;
}

int main() {
    FILE *fichier = fopen("voyages.txt", "r");
    if (fichier != NULL) {
        char ligne[300];
        while (fgets(ligne, 300, fichier) != NULL) {
            int id;
            char destination[50];
            char description[200];
            int nbPlaces;
            int nbPlacesRestantes;
            date dateDebut;
            date dateFin;
            int jjd,mmd,aad,jjf,mmf,aaf;
            sscanf(ligne, "%d,%[^,],%[^,],%d,%d,%d:%d:%d,%d:%d:%[^\n]", &id, destination, description, &nbPlaces, &nbPlacesRestantes, &jjd, &mmd, &aad, &jjf, &mmf, aaf);
            dateDebut.aa = aad;
            dateDebut.mm = mmd;
            dateDebut.jj = jjd;
            dateFin.aa = aad;
            dateFin.mm = mmd;
            dateFin.jj = jjd;
            
            struct voyage *nouveauVoyage = malloc(sizeof(struct voyage));
            if (nouveauVoyage == NULL) {
                printf("Erreur d'allocation mémoire !\n");
                return 1;
            }
            nouveauVoyage->id = id;
            strcpy(nouveauVoyage->destination, destination);
            strcpy(nouveauVoyage->description, description);
            nouveauVoyage->nbPlaces = nbPlaces;
            nouveauVoyage->nbPlacesRestantes = nbPlacesRestantes;
            nouveauVoyage->dateDebut.aa = dateDebut.aa;
            nouveauVoyage->dateDebut.mm = dateDebut.mm;
            nouveauVoyage->dateDebut.jj = dateDebut.jj;
            nouveauVoyage->dateFin.aa = dateDebut.aa;
            nouveauVoyage->dateFin.mm = dateFin.mm;
            nouveauVoyage->dateFin.jj = dateFin.jj;
            nouveauVoyage->suivant = premierVoyage;
            premierVoyage = nouveauVoyage;
        }
        fclose(fichier);
    }
    int choix;
    do {
        system("cls");
        printf("\t\t_____________________________________________________________________\n\n\t\t\t------BIENVENU chez notre site TRAVEL-MANAGER------\n");
        printf("\t\t_____________________________________________________________________\n\n");
        printf("\t\t\t\t\t\tMenuMenu \n");               
        printf("\t\t\t\t[1] Ajouter un voyage\n");                                       
        printf("\t\t\t\t[2] Afficher la description d'un voyage\n");
        printf("\t\t\t\t[3] Supprimer un voyage\n");
        printf("\t\t\t\t[4] Modifier un voyage\n");
        printf("\t\t\t\t[5] Afficher les voyages disponibles entre deux dates\n");
        printf("\t\t\t\t[6] Quitter\n");
        printf("\t\t____________________________________________________________________\n\n");
        printf("\t\t\t\t\nChoix : ");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterVoyage();
                break;
            case 2:
                afficherDescriptionVoyage();
                break;
            case 3:
                supprimerVoyage();
                break;
            case 4:
                modifierVoyage();
                break;
            case 5:
                afficherVoyagesDisponibles();
                break;
            case 6:
                return 0;
            default:
                printf("Choix incorrect !\n");
                break;
        }
    }while (choix != 6);
  return 0 ;  
}



