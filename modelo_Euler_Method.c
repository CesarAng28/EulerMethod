#include"bongee_prediction.h"

#define G 9.81

double modelo_Euler_Method(double delta_t,int index, long int gramos, int k_resorte)
{
  int count;
  double pos1 = 10, pos2 = 10,temp;
  double minus_one = -1;

  for(count = 0;count < index;count++)
  {
    temp = (minus_one * pos1)*(1+(k_resorte*(delta_t*delta_t))/(gramos)) + 2*pos2 + (delta_t*delta_t)*(G);

    pos1 = pos2;
    pos2 = temp;
  }

  return pos2;
  
}
