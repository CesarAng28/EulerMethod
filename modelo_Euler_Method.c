#include<math.h>
#include"bongee_prediction.h"

#define G 9.81

double modelo_Euler_Method(double delta_t,int index, long int gramos, int k_resorte)
{
  int count;
  double pos1 = 10, pos2 = 10, temp;

  for(count = 0;count < index;count++)
  {
    temp = (-1*pos1)*(1+((k_resorte*(pow(delta_t,2)))/gramos)) + 2*pos2 + (pow(delta_t,2))*G;

    pos1 = pos2;
    pos2 = temp;
  }

  return pos2;
  
}
