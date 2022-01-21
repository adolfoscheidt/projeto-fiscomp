#include <stdio.h>
#include <math.h>

#define dx 0.1  //passo
#define xmax 20    //valor maximo de x para o plot

/* função esférica de bessel de ordem l ------------------------------------------ */

double j(int l, double x){
  
  double one, two, thr;
  int k;
  
  one = (sin(x))/x;                    /* começa com a ordem mais baixa */
  two = (sin(x) - x*cos(x))/(x*x);
  if(l==0) return one;
  else if(l==1) return two;
  else if(l>=2){
    for (k = 1 ; k<l ; k+=1)             /* loop para a ordem da função */
      {
	thr = ((2.*k + 1.)/x)*two - one;        /* fórmula de recorrência  */
	one = two;
	two = thr;
      }
    return(thr);
  }
  
}

/* ------------------------------------------------------------------------------*/

/* função esférica de neumann de ordem l -----------------------------------------*/

double y(int l, double x){
  
  double one, two, thr;
  int k;
  
  one = (-cos(x))/x;                    /* começa com a ordem mais baixa */
  two = (-cos(x) - x*sin(x))/(x*x);
  if(l==0) return one;
  else if(l==1) return two;
  else if(l>=2){
    for (k = 1 ; k<l ; k+=1)             /* loop para a ordem da função */
      {
	thr = ((2.*k + 1.)/x)*two - one;        /* fórmula de recorrência  */
	one = two;
	two = thr;
      }
    return(thr);
  }
  
}

/* ------------------------------------------------------------------------------*/

/* início da função main() ------------------------------------------------------*/

main(){

  int i;
  
  for(i=0;i<=xmax/dx;i++){
    
    double x = i*dx;
    
    //A primeira linha corresponde às funções esféricas de Bessel. Se o objetivo for calcular as funções esféricas de Neumann, utilizar a segunda linha.
    
    printf("%f %f %f %f %f %f %f \n", x, j(0,x), j(1,x), j(2,x), j(3,x), j(4,x), j(5,x));
    
    //É importante notar que, no caso das fções de Neumann, o x não pode começar do zero porque elas são indefinidas nesse ponto. Somar um dx ao zero já resolve o problema.
    
    //printf("%f %f %f %f %f %f %f \n", x+dx, y(0,x+dx), y(1,x+dx), y(2,x+dx), y(3,x+dx), y(4,x+dx), y(5,x+dx));
    
  }
  
  /* comandos para o gnuplot:
     
     funções esféricas de Bessel: p 'bessel.dat', 'bessel.dat' u 1:3, 'bessel.dat' u 1:4, 'bessel.dat' u 1:5, 'bessel.dat' u 1:6, 'bessel.dat' u 1:7, 0;
     
     funções esféricas de Neumann: p [0:20][-0.5:0.5] 'neumann.dat', 'neumann.dat' u 1:3, 'neumann.dat' u 1:4, 'neumann.dat' u 1:5, 'neumann.dat' u 1:6, 'neumann.dat' u 1:7, 0;
     
  */
  
}

/* --------------------------- FIM --------------------------------------*/
   

 
