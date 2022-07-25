#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

int findCode(int inpCode){

    int tab[]= {152,147,222,881,236};
    bool isFind = false;

        for(int i=0; i<5; i++){
            if(tab[i] == inpCode){
                isFind = true;
            }
        }
        return isFind;
}

void secretCode1(){
    //DECLARATION DES VARIABLES
    int i= 0, cpt=2, inpCode;
    char tabChaine[80];

    //COMMENT
    printf("Veillez saisir un code: \n");
    scanf( "%[^\n]", &tabChaine );

    while (i <= 2)
    {
        if(!(checkStr(tabChaine))){

            printf("\n");
            printf("code secret saisi incorrect.....\n");
            printf("Veillez saisir des entiers: \n");
            scanf("%s", &tabChaine);
            if (i == 2)
            {
                printf("code  not valid");
                return;
            }
            
        }

        inpCode = atoi(tabChaine);

        if(findCode(inpCode))
        {
            printf("\n");
            printf("code secret correct \n \n");
            return;
        }else if(i == 0){
                printf("\n");
                printf("code secret saisi incorrect.....\n");
                printf("Veillez réssayer le code: \n");
                scanf("%s", &tabChaine);
        }else if (cpt == 2 && i > 0){
                printf("\n");
                printf("code secret saisi incorrect....\n");
                printf("Il vous reste %d tentative \n", --cpt);
                printf("Veillez saisir encore code: \n");
                scanf("%s", &tabChaine);
        }else{
                printf("\n");
                printf("Fin des tentatives \n \n");
                return;
        }

        i++;
    }
}


void secretCode2(){

    int tab[]={587,1200,222,0102,555};
    int i= 0, inpCode, cpt= 1;

    char tabChaine[80];

    printf("Veillez saisir un code: \n");
    scanf( "%[^\n]", &tabChaine );

    while (i <= 2)
    {
        if(!(checkStr(tabChaine))){
            printf("code  not valid");
            return;
        }

        inpCode = atoi(tabChaine);

        for (int j=0; j < 5; j++)
        {
            if(tab[j] == inpCode){
                printf("code secret correct \n \n");
                return;
            }
        }

        if(i == 2){
            printf("\n");
            printf("Fin des tentatives \n \n");
            return;
        }

        printf("\n");
        printf("code secret saisi incorrect....\n");
        (i > 0) ? printf("Il vous reste %d tentative \n ", cpt) : printf("");
        printf("Veillez réssayer le code: \n");
        scanf("%s", &tabChaine);
        i++;

    }
}

int main(){
    return 0;
}