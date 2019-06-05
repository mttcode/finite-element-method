#include<stdio.h>
#include<math.h>

#define MAX 50

int i,j,k,N;
float A[MAX][MAX+1],L[MAX][MAX],U[MAX][MAX+1],X[MAX];

void pokec()
{
 clrscr();
 printf("\n");
 printf("\n\t -------------------------------------- ");
 printf("\n\t|  M E T O D A  LU - R O Z K L A D U   |");
 printf("\n\t|      ( trojdiagonalna matica )       |");
 printf("\n\t|     ( riesenia sustavy rovnic )      |");
 printf("\n\t -------------------------------------- ");
 printf("\n");
 printf("\n\n");
}


void vynulovanie()
{
 for(i=0;i<N;i++)
  for(j=0;j<N+1;j++)
   A[i][j]=L[i][j]=U[i][j]=X[i]=0;
}

void vstup_rozmer()
{
 do
   {
    printf("  Zadaj rozmer trojdiagonalnej matice ( max %d ) : ",MAX);
    rewind(stdin);
   }
 while(!scanf("%d",&N)||(N<=1)||(N>MAX));
}

void vstup_matica1()
{
 printf("\n VSTUP TROJDIAGONALNEJ MATICE A :\n");

 printf("\n > prvky pod hlavnou diagonalou < \n");
 for(i=0;i<N-1;i++)
  do
    {
     printf("   Zadaj prvok matice A[%d,%d] : ",i+1,i+2);
     rewind(stdin);
    }
  while(!scanf("%f",&A[i+1][i]));

 printf("\n> prvky na hlavnej diagonale < \n");
 for(i=0;i<N;i++)
  do
    {
     printf("   Zadaj prvok matice A[%d,%d] : ",i+1,i+1);
     rewind(stdin);
    }
  while(!scanf("%f",&A[i][i]));

 printf("\n > prvky nad hlavnou diagonalou < \n");
 for(i=0;i<N-1;i++)
  do
    {
     printf("   Zadaj prvok matice A[%d,%d] : ",i+1,i+2);
     rewind(stdin);
    }
  while(!scanf("%f",&A[i][i+1]));

 printf("\n VSTUP MATICE d :\n");
 for(i=0;i<N;i++)
  do
    {
     printf("   Zadaj prvok matice d[%d] : ",i+1);
     rewind(stdin);
    }
  while(!scanf("%f",&A[i][N]));
}

void vypis1()
{
 for(i=0;i<N;i++)
  {
   printf(" (");
   for(j=0;j<N;j++)
    printf(" %.0f ",A[i][j]);
   printf(") ");
   if(i==N/2) printf("* ");
    else      printf("  ");
   printf("( x%d ) ",i+1);
   if(i==N/2) printf("= ");
    else      printf("  ");
   printf("( %.0f ) \n",A[i][N]);
  }
}

void vypis2()
{
 for(i=0;i<N;i++)
  {
   printf(" (");
   for(j=0;j<N;j++)
    printf(" %.0f ",A[i][j]);
   printf(") ");
   if(i==N/2) printf("= ");
    else      printf("  ");
   printf("(");
   for(j=0;j<N;j++)
    printf(" %.0f ",L[i][j]);
   printf(") ");
   if(i==N/2) printf("* ");
    else      printf("  ");
   printf("(");
   for(j=0;j<N;j++)
    printf(" %.0f ",U[i][j]);
   printf(") \n");
  }
}

void vypis3()
{
 for(i=0;i<N;i++)
  {
   printf(" (");
   for(j=0;j<N;j++)
    printf(" %.0f ",L[i][j]);
   printf(") ");
   if(i==N/2) printf("* ");
    else      printf("  ");
   printf("( y%d ) ",i+1);
   if(i==N/2) printf("= ");
    else      printf("  ");
   printf("( %.0f ) \n",A[i][N]);
  }
 printf("\n VYPOCITANY VEKTOR y :\n");
 for(i=0;i<N;i++)
  printf("\n\t y%d = %.2f ",i+1,U[i][N]);
 printf("\n");
}

void vypis4()
{
 for(i=0;i<N;i++)
  {
   printf(" (");
   for(j=0;j<N;j++)
    printf(" %.0f ",U[i][j]);
   printf(") ");
   if(i==N/2) printf("* ");
    else      printf("  ");
   printf("( x%d ) ",i+1);
   if(i==N/2) printf("= ");
    else      printf("  ");
   printf("( %.0f ) \n",U[i][N]);
  }
 printf("\n VYPOCITANY VEKTOR x :\n");
 for(i=0;i<N;i++)
  printf("\n\t x%d = %.2f ",i+1,X[i]);
 printf("\n\t^^^^^^^^^^^^^^\n");
}

void vypocetLaU()
{
 for(i=0;i<N;i++)
  L[i][i]=1;
 U[0][0]=A[0][0];
 U[0][1]=A[0][1];
 L[1][0]=A[1][0]/U[0][0];
 for(i=1;i<N-1;i++)
  {
   U[i][i]=A[i][i]-L[i][i-1]*U[i-1][i];
   L[i+1][i]=A[i+1][i]/U[i][i];
   U[i][i+1]=A[i][i+1];
  }
 U[N-1][N-1]=A[N-1][N-1]-L[N-1][N-2]*U[N-2][N-1];
}

void vypocetY()
{
 U[0][N]=A[0][N];
 for(i=1;i<N;i++)
  U[i][N]=A[i][N]-L[i][i-1]*U[i-1][N];
}

void vypocetX()
{
 X[N-1]=U[N-1][N];
 for(i=N-2;i>-1;i--)
  X[i]=(U[i][N]-U[i][i+1]*X[i+1])/U[i][i];
}

void main()
{
 pokec();
 getch();
 delay(500);
 clrscr();
 vynulovanie();
 vstup_rozmer();
 vstup_matica1();
 delay(1000);
 clrscr();
 printf("\n\n");
 printf("\n\n 1.) VEKTOROVY ZAPIS SUSTAVY ROVNIC :\t A * x = d \n\n");
 vypis1();
 getch();
 clrscr();
 vypocetLaU();
 printf("\n\n 2.) ROZKLAD TROJDIAGONALNEJ MATICE :\t A = L * U \n\n");
 vypis2();
 getch();
 clrscr();
 vypocetY();
 printf("\n\n 3.) VYPOCET SUBSTITUCIE :\t L * y = d \n\n");
 vypis3();
 getch();
 clrscr();
 vypocetX();
 printf("\n\n 4.) RIESENIE SUSTAVY :\t U * x = y \n\n");
 vypis4();
 printf("\n\t ! opis si vysledok a stlac klavesu ! \n");
 getch();
 printf("\n\n");
}
