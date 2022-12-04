#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846
#define N 4

double factorial(double number);

double getSin(double number);

double getCos(double number);

double getDoublePetaledRose(double a);


int main(void) {
  double Xd, Xr, sin_1, sin_2, cos_1, cos_2, e1, e2, doublePetaledRose;
  
  printf("Set the angle value in degrees...\n");
  scanf("%lf", &Xd);

  Xr = Xd * M_PI / 180.0;

  sin_1 = sin(Xr);

  sin_2 = getSin(Xr);

  cos_1 = cos(Xr);

  cos_2 = getCos(Xr);

  e1 = fabs(sin_1 - sin_2);

  e2 = fabs(cos_1 -  cos_2);

  printf("X = %lf\n\nsin_1 = %.15lf\nsin_2 = %.15lf\ne = %lf", Xd, sin_1, sin_2, e1);

  printf("\n\ncos_1 = %.15lf\ncos_2 = %.15lf\ne = %lf", cos_1, cos_2, e2);

  printf("\n\ndoublePetaledRose");

  doublePetaledRose = getDoublePetaledRose(2);

  return 0;
}

double factorial(double number) 
{
  if(number <= 1.0)
    return (1.0);
  else {
    return (number * factorial(number - 1));
  }
}

double getSin(double Xr) 
{
  double Y;
  int k, n;

  for(Y = 0.0, n = 1, k = 1; n <= N; n = n + 2, k++)
  {
    Y += pow(-1, k + 1) * pow(Xr, n) / factorial(n);
  }

  return Y;
}

double getCos(double Xr) 
{
  double Z;
  int k,n;

  for(Z = 0.0, n = 2, k = 1; n <= N; n = n + 2, k++)
  {
    Z += pow(-1, k + 1) * pow(Xr, n) / factorial(n);
  }

  return Z;
}

double getDoublePetaledRose(double a)
{
  //r = a * sin (2 φ), φ Є (-∞; +∞), (a > 0)

  double r, phi;
   
  for(phi = M_PI / 2; phi <= 2 * M_PI; phi = phi + (M_PI /2)){

    r = a * sin(2 * phi);

    if(r > 0) {
      printf("\n\nphi = %.10lf\n\nr = %.10lf\n", phi, r);
    }
  }

  return r;
}
