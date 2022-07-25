#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>




//function permettant de verifier si un ou des caracteres saisies sont des entiers
//la function retourne false si au moins un caractere alpha numeric est detecté

int checkStr(char *inpCode) {

    bool isCorrect = true;
    size_t length = strlen( inpCode );
    for( int i=0; i<length; i++ ) {
        if ( ! isdigit( inpCode[i] ) ) {
            isCorrect = false;
        }
    }
  
    return isCorrect;
}



//function permettant de verifier si un utilisateur a saisie un bon code

void secretCode3(){
    //tableau contenant les codes predefinies
    int tab[]={587,1200,222,0102,555};

    //declaration des variables i pour le compteur de nombre de saisie
    //la variable j utiliser comme index pour le tableau
    //la variable inpCode reçoit la valeur convertie en entier
    int i= 0,inpCode,j=1;

    //le tableau des caractéres saisie par l'utilisateur
    char tabChaine[80];

    printf("Veillez saisir un code: \n");
    scanf( "%[^\n]", tabChaine );

    //Boucle permettant de compter le nombre de tentatives de saisie faites par l'utlisateur
    while (i < 3)
    {
        //Appel de la function permettant la verification des caracteres saisies
        if(!(checkStr(tabChaine))){
            printf("code  not valid \n");
            return;
        }
        //Conversion des caracteres saisie en un nombre entier    
        inpCode = atoi(tabChaine);
       
        //Boucle permettant de parcourrir le tableau 
        for (int j=0; j < 5; j++)
        {
            //Condition permettant de comparer le contenu du tableau et le code saisie
            if(tab[j] == inpCode){
                printf("\n");
                printf("code secret correct \n \n");
                return;
            }
        }
       
        //Condition permettant de savoir si on est a la premiere tentative
        if(i == 0){
            printf("\n");
            printf("code secret saisi incorrect....\n");
            printf("Veillez réssayer le code: \n");
            scanf( "%s", tabChaine);
            
            
        }
        //Condition permettant de savoir si on a epuisé le nombre de tentative
        else if(i == 2){
            printf("\n");
            printf("Fin des tentatives \n \n");
            return;     
        }
        //Condition permettant d'avertir si on est a la derniere tentative
        else{
            printf("\n");
            printf("code secret saisi incorrect....\n");
            printf("Il vous reste 1 tentative\n");
            printf("Veillez réssayer le code: \n");
            scanf( "%s",tabChaine );
            
        }

        //icrementation du compteur de la boucle
        i++;

    }
}

void computerNote(){
      //Declaration du table a deux dimensions, une variable pour la somme des notes et une autre pour les coeffs  
      float tab[4][2],somme=0, somCoef=0;

      //Declaration des tableaux contenant les valeurs des coefficients et un autre pour stoker les notes finales
      int coef [4]={4,2,3,2},noteFinale[4];

      //Declaration de la variable destinée à recevoir la moyenne finale
      float moyenne;
       // Declaration des tableaux contenant les coefficients et un autre pour stocker le nom de l'eleve
      char *tabCoefName[]={"Maths","Anglais","Français","Svt"}, student[80];

      printf("Veillez saisir le nom complet de l'eleve :\n");
      fgets(student, sizeof(student), stdin);

      for (int i = 0; i <4; i++){
        for (int j = 0; j < 2; j++){
            printf("\n");
            printf("%s saisir la note %d: \n",tabCoefName[i],j+1);
            if ( scanf("%f", &tab[i][j]) != 1 || tab[i][j] < 0 || tab[i][j] > 20){
                printf("\n");
                printf("Vous devez saisir que des nombres compris entre 0 et 20....\n \n");
                printf("Recommencer encore....\n \n");
                return;
            }
        } 
      }


      
    int line= 0, colonne;
      while (line < 4)
      {
        int sumNote = 0;
        for (colonne = 0; colonne < 2; colonne++)
        {
            
            sumNote = (sumNote + tab[line][colonne]); 
            noteFinale[line] = sumNote/2;
            
        }
        
        somme = somme+ (noteFinale[line]* coef[line]);
        somCoef += coef[line];
        line++;
      }
      

       moyenne = somme / somCoef;
       
       printf("\n");
       printf("La moyenne est de %f \n", moyenne);

      if(moyenne < 10){
        printf("\n");
        puts(student); 
        printf("Votre resultat est médiocre... \n \n");
      }else if (moyenne == 10){
        printf("\n");
        puts(student);
        printf("Votre resultat est passable... \n \n");
      }else if (moyenne == 12 && moyenne <= 14){
        printf("\n");
        puts(student);
        printf("Votre resultat est très bien... \n \n");
      }else{
        printf("\n");
        puts(student);
        printf("Votre resultat est Excellent... \n \n");
      }
}


int main()
{
    
   secretCode3();     
   return 0;
}
