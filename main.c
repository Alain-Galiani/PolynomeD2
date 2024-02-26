#include <stdio.h>
#include <math.h>

//*************
//*** ENUMS ***
//*************

enum COMMANDE
{
  MANUEL,
  CALCUL_RACINES,
  CALCUL_DELTA
};

//******************
//*** STRUCTURES ***
//******************

struct GLOBAL_PARAMETRES
{
  //*** Type entier pour IN ***

  int i[8][3];
  long long ll[8][3];

  //*** Type Float pour IN ***

  float f[8][3];
  double d[8][3];

  //*** Type entier pour OUT ***

  int oi[8][3];
  long long oll[8][3];

  //*** Type Float pour OUT ***

  float of[8][3];
  double od[8][3];
};

//*******************************
//*** PROTOTYPES DE FONCTIONS ***
//*******************************

double PolyD2(struct GLOBAL_PARAMETRES *ptr_Glo_Para,enum COMMANDE commande);

//********************************
//*** DEFINITIONS DE FONCTIONS ***
//********************************

double PolyD2(struct GLOBAL_PARAMETRES *ptr_Glo_Para,enum COMMANDE commande)
{
  static int debug,nb_erreur;
  static int cc;
  static double a,b,c,delta,x1,x2,rd,aa;

  debug=0;
  nb_erreur=0;

  if(ptr_Glo_Para==NULL)
  {
    printf("\n*** Attention pointeur vers Glo_Para invalide ***\n ");
    return 0.0;
  }

  switch(commande)
  {
    case CALCUL_DELTA:
    case CALCUL_RACINES:

      do
      {
        printf("\n");
        printf("Pour ax² + bx + c : Entrez la valeur a => a = ");
        debug=scanf("%lf",&a);

        if(debug!=1 || a==0.0)
        {
          if(nb_erreur>10)
          {
            printf("\n*** Vous avez fait un nombre d'erreur de saisie trop important, exit Fonction PolyD2 ***\n");
            (*ptr_Glo_Para).od[0][0]=0.0;
            (*ptr_Glo_Para).od[0][1]=0.0;
            (*ptr_Glo_Para).od[0][2]=0.0;
            return 0.0;
          }
          else
          {
            printf("\n*** Attention erreur de saisie, vous devez entrer un nombre different de 0 ***\n");
            nb_erreur++; 
          }
        } 

        while((cc=getchar()) != EOF && cc != '\n');

      } while (debug !=1 || a==0.0);

      do
      {
        printf("\n");
        printf("Pour ax² + bx + c : Entrez la valeur b => b = ");
        debug=scanf("%lf",&b);

        if(debug!=1)
        {
          if(nb_erreur>10)
          {
            printf("\n*** Vous avez fait un nombre d'erreur de saisie trop important, exit Fonction PolyD2 ***\n");
            (*ptr_Glo_Para).od[0][0]=0.0;
            (*ptr_Glo_Para).od[0][1]=0.0;
            (*ptr_Glo_Para).od[0][2]=0.0;
            return 0.0;
          }
          else
          {
            printf("\n*** Attention erreur de saisie, vous devez entrer un nombre ***\n");
            nb_erreur++; 
          }
        } 
        
        while((cc=getchar()) != EOF && cc != '\n');

      } while (debug !=1);

      do
      {
        printf("\n");
        printf("Pour ax² + bx + c : Entrez la valeur c => c = ");
        debug=scanf("%lf",&c);

        if(debug!=1)
        {
          if(nb_erreur>10)
          {
            printf("\n*** Vous avez fait un nombre d'erreur de saisie trop important, exit Fonction PolyD2 ***\n");
            (*ptr_Glo_Para).od[0][0]=0.0;
            (*ptr_Glo_Para).od[0][1]=0.0;
            (*ptr_Glo_Para).od[0][2]=0.0;
            return 0.0;
          }
          else
          {
            printf("\n*** Attention erreur de saisie, vous devez entrer un nombre ***\n");
            nb_erreur++; 
          }
        } 

        while((cc=getchar()) != EOF && cc != '\n');

      } while (debug !=1);

    break;

    default:
      // Rien
    break;  
  }

  switch(commande)
  {
    case CALCUL_DELTA:
      delta=b*b-(4*a*c);
      printf("\nCalcul du Delta\n");
      printf("\nLe delta est égale à : %lf\n",delta);
      (*ptr_Glo_Para).od[0][0]=delta;
      (*ptr_Glo_Para).od[0][1]=0.0;
      (*ptr_Glo_Para).od[0][2]=0.0;
      return delta;
    break;

    case CALCUL_RACINES:
      delta=b*b-(4*a*c);
      printf("\nCalcul des racines\n");
      printf("\nLe delta est égale à : %lf\n",delta);

      if(delta>0)
      {
        printf("Delta est > 0 donc on calcul les deux racines x1 et x2 \n");
        rd=sqrt(delta);
        aa=2*a;
        x1=(-b-rd)/aa;
        x2=(-b+rd)/aa;
        printf("Racines x1 et x2 :   x1 = %lf   x2 = %lf \n",x1,x2);
        (*ptr_Glo_Para).od[0][0]=delta;
        (*ptr_Glo_Para).od[0][1]=x1;
        (*ptr_Glo_Para).od[0][2]=x2;
        return delta;
      }
      else if(delta==0.0)
      {
        printf("Delta est == 0 donc on calcul l'unique racine x1 \n");
        aa=2*a;
        x1=-b/aa;
        printf("Racine x1 :   x1 = %lf \n",x1);
        (*ptr_Glo_Para).od[0][0]=delta;
        (*ptr_Glo_Para).od[0][1]=x1;
        (*ptr_Glo_Para).od[0][2]=0.0;
        return delta;
      }
      else
      {
        printf("Delta est < 0 donc il n'y a pas de solution dans R\n");
        (*ptr_Glo_Para).od[0][0]=delta;
        (*ptr_Glo_Para).od[0][1]=0.0;
        (*ptr_Glo_Para).od[0][2]=0.0;
        return delta;
      } 
    break;

    case MANUEL:
      printf("\n\n");
      printf("*********************************************************************************************************************************\n");
      printf("*\t Manuel de la Fonction Poly2D\t\t\t\t\t\t\t\t\t\t\t\t*\n");  
      printf("*\t\t: Retourne un double\t\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t: Retourne 1.0 avec la commande MANUEL\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t: Reconnait les commandes CALCUL_DELTA , CALCUL_RACINES , MANUEL\t\t\t\t\t\t*\n");
      printf("*\t\t: Prend en parametres (struct GLOBAL_PARAMETRES *ptr_Glo_Para,enum COMMANDE commande)\t\t\t\t*\n");
      printf("*\t\t: Retourne 0.0 si pointeur vers Glo_Para==NULL\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t: Retourne 0.0 si erreur de saisie > 10 avec :\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][0]==0.0\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][1]==0.0\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][2]==0.0\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t: Avec la commande CALCUL_DELTA retourne delta avec :\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][0]==delta\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][1]==0.0\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][2]==0.0\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t: Avec la commande CALCUL_RACINES retourne delta avec :\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tGlo_Para.od[0][0]==delta\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tSi delta > 0\t\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\t\tGlo_Para.od[0][1]==x1\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\t\tGlo_Para.od[0][2]==x2\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tSi delta == 0\t\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\t\tGlo_Para.od[0][1]==x1\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\t\tGlo_Para.od[0][2]==0.0\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\tSi delta < 0\t\t\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\t\tGlo_Para.od[0][1]==0.0\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*\t\t\t\tGlo_Para.od[0][2]==0.0\t\t\t\t\t\t\t\t\t\t*\n");
      printf("*********************************************************************************************************************************\n");
      printf("\n\n");
      return 1.0; 
    break;

    default:
      printf("\nCommande non trouvée \n");
    break;
  }
 
  return 0.0;
}

//*********************
//*** FONCTION MAIN *** 
//*********************

int main(void)
{
  struct GLOBAL_PARAMETRES Glo_Para;
  struct GLOBAL_PARAMETRES *ptr_Glo_Para=NULL;
  ptr_Glo_Para=&Glo_Para;

  printf("\n");
  printf("Hello World \n"); 
  printf("Réponse de la fonction = %lf \n",PolyD2(NULL,CALCUL_DELTA));
  printf("Réponse de la fonction = %lf \n",PolyD2(ptr_Glo_Para,MANUEL));
  printf("Réponse de la fonction = %lf \n",PolyD2(ptr_Glo_Para,CALCUL_DELTA));
  printf("Réponse de la fonction = %lf \n",PolyD2(ptr_Glo_Para,CALCUL_RACINES));
  printf("\n");
  printf("\ndelta = %lf \n",Glo_Para.od[0][0]);
  return 0;    
}