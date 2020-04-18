#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <sstream>
#include <iomanip>
#define NOM_ARCHIVO "plagas.txt"
using namespace std;

int menupp(int mpp)
{int y;
    if (mpp==1)
    {y=1;}
    else{y=0;}
    return y;}

float descuento1(float hectareas, float totalsindescuento){
	
	float descuento;
	if (hectareas>500)
	{
		descuento=(totalsindescuento*0.05);
	}
	else
	{
		descuento=0;
	}
	
	return descuento;
}

float descuento2( float totalsindescuento){

	float descuento;
	if (totalsindescuento>500)
	{
		descuento=(totalsindescuento*0.10);
	}
	else
	{
		descuento=0;
	}
	
	return descuento;
}

int main()
{
	
	
	float hectarias,parcial,parcial1,parcial2,parcial3,total;
	int servicios1,regreso;
	int x=1,opcion;
	while (x==1)
{cout<<"Bienvenido, eliga una de las siguientes opciones \n 1.Realizar venta.   \n 2.Ver Historico de venta. \n ";cin>>opcion;
if (opcion==1)
{cout<<"Ingrese el area a trabajar en hectareas "<<endl;
	cin>>hectarias;
cout<<"Seleccione una de las siguientes opciones de trabajo \n 1. Mala hierba 10  \n 2. Langostas  20	\n 3. Gusanos  30 \n 4. Todos los servicios. \n";
cin>>servicios1;

if(servicios1==1)
{parcial=hectarias*10;
}
else {
	if (servicios1==2)
	{
		parcial=hectarias*20;
	}
	else {
		if(servicios1==3)
		{
			parcial=hectarias*30;
		}
		else {
			if (servicios1==4)
			{parcial=hectarias*50;
			}
			
		}
	}
}
parcial1=descuento1(hectarias,parcial);
parcial2=descuento2(parcial);



total=parcial-parcial1-parcial2;









ofstream servicios;

try {
servicios.open(NOM_ARCHIVO,ios::app);
servicios<<servicios1<<"\n"<<hectarias<<"\n"<<total<<"\n";
servicios.close();
	
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
cout<<"Si desea regresar al menu oprima 1, si no presione 2 "<<endl;
cin>>regreso;
x=menupp(regreso);
system("CLS");


}
else if (opcion==2)
{    FILE *entrada;
   int ch, num_lineas;
   if ((entrada = fopen(NOM_ARCHIVO, "r")) == NULL){
      perror(NOM_ARCHIVO);
      return 1;
   }
   num_lineas = 0;
   while ((ch = fgetc(entrada)) != EOF)
      if (ch == '\n')
         num_lineas++;
   fclose(entrada);
     ifstream servicios;
string texto;
int numerolineas;
string datos1[num_lineas];
servicios.open(NOM_ARCHIVO,ios::in);
  numerolineas=num_lineas-1;
  
  //En la siguientes lineas se obtiene los valores del archivo txt. //
   for(int i=0;i<=numerolineas;i++){
  fflush(stdin);
getline(servicios,texto); 
datos1[i]=texto;
   }
   
   
   //En las siguientes lineas se dividen esos valores para categorizarlos //
   string tiposervicio[numerolineas],checta[numerolineas],pagos[numerolineas];
   int aumento=0;
      int aumento1=0;
         int aumento2=0;
       int   cantidadservicio1=0,cantidadservicio2=0,cantidadservicio3=0,cantidadservicio4=0,suma=0;
         
         
         
         
         
         
         
         
         
   for(int indicador1=0;indicador1<numerolineas;)
{tiposervicio[aumento]=datos1[indicador1];

if (tiposervicio[aumento]=="1")
{
	cantidadservicio1=cantidadservicio1+1;
}
else {
	if (tiposervicio[aumento]=="2")
{
	cantidadservicio2=cantidadservicio2+1;
}
else{
		if (tiposervicio[aumento]=="3")
{
	cantidadservicio3=cantidadservicio3+1;
}
else {
		if (tiposervicio[aumento]=="4")
{
	cantidadservicio4=cantidadservicio4+1;
}
}
	
}
}

aumento++;
indicador1=indicador1+3;
}
 for(int indicador2=1;indicador2<numerolineas;)
{checta[aumento1]=datos1[indicador2];
aumento1++;
indicador2=indicador2+3;
}
 for(int indicador3=2;indicador3<=numerolineas;)
{pagos[aumento2]=datos1[indicador3];
suma=atoi(pagos[aumento2].c_str())+suma;
aumento2++;
indicador3=indicador3+3;
}

if (cantidadservicio1>cantidadservicio2 && cantidadservicio1>cantidadservicio3 && cantidadservicio1>cantidadservicio4)

{
	cout<<"El servicio con mayor demanda es Mala hierba"<<endl;
}
else {
	if (cantidadservicio2>cantidadservicio1 && cantidadservicio2>cantidadservicio3 && cantidadservicio2>cantidadservicio4)

{
	cout<<"El servicio con mayor demanda es Langosta"<<endl;
}
else {
		if (cantidadservicio3>cantidadservicio1 && cantidadservicio3>cantidadservicio2 && cantidadservicio3>cantidadservicio4)

{
	cout<<"El servicio con mayor demanda es Gusano"<<endl;
}
else {
	
		cout<<"Tiene mayor demanda seleccionar todos los servicios"<<endl;
}
}
	
}

cout<<"La cantidad de servicios con trabajo mala hierba es igual a "<<cantidadservicio1<<"\n";
cout<<"La cantidad de servicios con trabajo langosta es igual a "<<cantidadservicio2<<"\n";
cout<<"La cantidad de servicios con trabajo gusano es igual a "<<cantidadservicio3<<"\n";
cout<<"La cantidad de servicios con todas las opciones es igual a "<<cantidadservicio4<<"\n";
cout<<"La cantidad total pagada por los clientes es de  "<<suma<<"\n";





cout<<"Si desea regresar al menu oprima 1, si no presione 2 "<<endl;
cin>>regreso;
x=menupp(regreso);
system("CLS");

      return 0;
}
}

	
}
