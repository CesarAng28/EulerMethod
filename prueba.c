void DesarrolloEcuacion(DATOS *datos,float array[][2])
{
  float x=0,t,n;
  int i;
  t=0;
  for (i=0; i<datos.cantDelta; i++)
  {
    if(i==0)
    {
      array[i][1]=0;
      array[i+1]=+(2(array[i][1])(t)(datos.delta))+(datos.delta)(datos.delta)(9.81);
      array[i][0]= t; //valor del tiempo
    }
    if(i==1)
    {
      array[i+1][1]=-(array[i-1][1])(1+((datos.k)(datos.delta)(datos.delta)/datos.masa))+2(array[i][1])(datos.delta)+(datos.delta)(datos.delta)*9.81;
      t=t+datos.delta;
    }
    array[i+1][0]= t; //valor del tiempo
  }
}