#include <stdio.h>
#include <stdlib.h>


int main()
{
    char ordine,a,b;
    char coefficiente='a';
    float m[20][20], r[20][2]x1=0,x2=0,x3=0;
    printf("Inserire l'ordine della matrice\n");
    scanf("%d",&ordine);
    printf("(ax1+bx2+cx3=d\n");
    printf("<ex1+fx2+gx3=h\n");
    printf("(ix1+jx2+kx3=l\n");
    for(a=0;a<ordine;a++){
        for(b=0;b<ordine+1;b++){
            printf("inserisci coefficiente %c: ",coefficiente);
            scanf("%f",&m[a][b]);
            coefficiente++;
        }
    }
    for(a=0;a<ordine;a++){
        printf("(%5.2fx1+%5.2fx2+%5.2fx3=%5.2f\n",m[a][0],m[a][1],m[a][2],m[a][3]);
    }

    for(a=0;a<ordine;a++)
        for(b=0;b<ordine;b++) if(a!=b) m[a][b]*=-1;


    for(a=0;a<ordine;a++){
        for(b=0;b<ordine+1;b++) if(a!=b) m[a][b]/=m[a][a];
        m[a][a]=1;
    }

    /*

    x1=(-(m[0][1]*x2)/m[0][0])-((m[0][3]*x3)/m[0][0])+(m[0][3]/m[0][0]);
    x2=(-(m[1][0]*x1)/m[1][1])-((m[1][2]*x3)/m[1][1])+(m[1][3]/m[1][1]);
    x3=(-(m[2][0]*x1)/m[2][2])-((m[2][1]*x2)/m[2][2])+(m[2][3]/m[2][2]);
*/



    printf("%f %f %f", x1,x2,x3);
    system("PAUSE");




}
