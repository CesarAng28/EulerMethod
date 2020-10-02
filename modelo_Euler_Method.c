#include<math.h>
#include"bongee_prediction.h"

#define G 9.81

double modelo_Euler_Method(double delta_t,int index, double masa, int k_resorte)
{
  int count;
  double pos1 = 10, pos2 = 10, temp, m = 60;
  float bt = 10;

  for(count = 0;count < index;count++)
  {
    temp = (-pos1)*(((-bt*delta_t)/m) + 1 +((k_resorte*(pow(delta_t,2)))/m)) - (2*(-bt*delta_t)/m)*pos2 + (pow(delta_t,2))*G;

    pos1 = pos2;
    pos2 = temp;
  }

  return pos2;
  
}
