#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char welcomeMenu()
{
    char chose;
    system("cls");
    printf("\n\n\n\n\n\n\n                           Premi invio per continuare\n\n\n                           Inserisci C per Credits\n\n\n                           Inserisci X per Uscire\n");
    chose=getch();
    system("cls");
    return chose;
}

char scegliMetodo()
{
    char key;
    do{
        system("cls");
        printf("\nInserisci 1 per il metodo di Jacobi\n\nInserisci 2 per il metodo di Gauss Seidel\n");
        key=getch();
        printf("%c",key);
    }while(key!='1'&&key!='2');
    return key;

}



void risoluzione(int nelementi,float x[5][5],float epsilon,char key)
{
    float q[5],rq[5]={0,0,0,0,0},r[5]={0,0,0,0,0},modulo;
    int si,c,c2;
    int nVolte=0;

    system("cls");
    if(key=='1')printf("Metodo Jacobi:\n\n");
    else printf("Metodo Gauss Seidel:\n\n");
    do
    {
        for(c=0;c<nelementi-1;c++)
            q[c]=rq[c];
        printf("%d",++nVolte);
        for(c=0;c<nelementi-1;c++)
        {

            for(c2=0,r[c]=x[c][nelementi-1];c2<nelementi-1;c2++)
                if(c2!=c)
                    if(x[c][c2]!=0)
                    {
                        if(key=='1')r[c]-=(x[c][c2]*q[c2]);           //la scelta tra meotodo jacobi e gauss
                        else r[c]-=(x[c][c2]*r[c2]);
                    }


            r[c]/=x[c][c];
            rq[c]=r[c];

            printf("\tX%d = %4.2f",c+1,r[c]);

        }
        printf("\n");
        for(c=0,si=0;c<nelementi-1;c++)
        {
            modulo=rq[c]-q[c];
            if(modulo<0)modulo*=(-1);
            if(epsilon>=modulo)
                    si++;
        }



    }while(si!=nelementi-1);

    printf("\n                       <Press any key to continue>\n");
    getch();
}

//l'acquistione dalla tastiera della matrice

void insertMatrix()
{
   float temp,temp2,epsilon,x[5][5];
    int c,c2,si,nelementi;
    char key;
    do{
        system("cls");
        printf("Inserisci %c :  ",156);
        scanf("%f",&epsilon);
    }while(epsilon<0||epsilon>1);
    do{
        system("cls");
        printf("%c : %4.3f",156,epsilon);
        printf("\nInserisci il numero massimo di elementi di una riga <max 5>: ");
        scanf("%d",&nelementi);
    }while(nelementi>5||nelementi<3);
    for(c=0;c<nelementi-1;c++)
    {
        system("cls");
        printf("                                         Riga %d\n",c+1);
        for(c2=0;c2<nelementi;c2++)
        {
          printf("\nInserisci elemento %d :",c2+1);
          scanf("%f",&x[c][c2]);
        }
    }
    system("cls");
    for(c=0;c<nelementi-1;c++)
    {
        for(c2=0;c2<nelementi-1;c2++)
        {
          if(c2==nelementi-2)
            printf("\t( %6.2f )X%d",x[c][c2],c2+1);
          else
            printf("\t( %6.2f )X%d  +",x[c][c2],c2+1);
        }

        printf("  = \t(%6.2f)",x[c][nelementi-1]);
        printf("\n");
    }
    for(c=0,si=nelementi-2;c<nelementi-2;c++)
    {
        for(c2=0,temp2=0;c2<nelementi-1;c2++)
            if(c!=c2&&c!=nelementi-1)
                temp2+=x[c][c2];
        if(temp2<0)temp2*=(-1);
        temp=x[c][c];
        if(temp<0)temp*=(-1);
        if(temp>temp2)
            si--;
    }
    if(si==0)
    {
        printf("\nSistema convergente");
        printf("\n                       <Press any key to continue>\n\n");
        getch();
    }
    else
    {
        printf("\nSistema divergente: potrebbe durare all'infinito\n\nPremere INVIO per continuare o ESC per reinserire il sistema ");
        key=getch();
        switch(key)
        {
            case 13 :
                system("cls");
                break;
            case 27 :
                return 1;
        }

    }

    key=scegliMetodo();
    risoluzione(nelementi,x,epsilon,key);



}

void credits()
{
    int c,righe=25;
    do{
        for(c=0;c<righe;c++)
            printf("\n");
        printf("                                Credits by BSGeorge");
        righe--;
        Sleep(100);
        system("cls");
        if(righe==0)righe=25;
    }while(!kbhit());
}


int main()
{
    char key;

    do{
        key=welcomeMenu();



        switch(key)
        {
            case 13:
                insertMatrix();
                break;
            case 'c':
            case 'C':
                credits();
                break;
            case 'x':
            case 'X':
                exit(0);
        }

    } while(key!='X'||key!='x');
    return 0;
}


//sostituire ai valori nuovi
//invece di fare i passaggi , ogni volta che si trova il valore si sostituisce nella variabile x sucessiva
//metodo gauss eider
