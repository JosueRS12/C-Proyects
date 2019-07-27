//caballo negro =10, rey negro=1, reina blanca=2 y caballo blanco=20
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

void ingresopos();
void matrizajedrez(int a, int aa, int b, int bb, int c, int cc, int d, int dd);
void pantalla ();
int ahogado(int rf, int rc, int r2f, int r2c);
int jaquecab (int rf, int rc, int cf, int cc);
int jaquereina (int rf, int rc, int r2f, int r2c, int raf, int rac);
int jaquemate(int rf, int rc);


int rey,rey2,reyb,reyb2,reina,reina2,cabb,cabb2,i,j,ajedrez[12][12];

int main() {
   int Ahogado,Jaquecab,Jaquereina,Jaquemate;
   pantalla ();
   ingresopos();
   pantalla ();
   matrizajedrez(rey,rey2,reyb,reyb2,reina,reina2,cabb,cabb2);
  
   Jaquecab= jaquecab(rey,rey2,cabb,cabb2);
   Jaquereina= jaquereina(rey,rey2,reyb,reyb2,reina,reina2);
   Jaquemate= jaquemate(rey,rey2);
	Ahogado= ahogado(rey,rey2,reyb,reyb2);

   if(Ahogado!=0){
      cout<<"\n   Se esta ahogado\n";
   }
   else if(Jaquecab==0&&Jaquereina==0){
      cout<<"\n   El rey esta fuera de peligro\n";
   }
   else if(Jaquemate==Jaquecab||Jaquemate==Jaquereina){
      cout<<"\n   El rey se encuentra en jaque mate\n";
   }
   else {
      cout<<"\n   El rey se encuentra en jaque\n";
   }  
   return 0;
}
void ingresopos(){
   do{
      cout<<" Ingrese la posicion del rey negro. [2 a 9]\n";
      cin>> rey;
      cin>> rey2;
      system("clear");
   }
   while(rey<2||rey>9 || rey2<2||rey2>9);
   
   do{
      cout<<" \nIngrese la posicion del rey blanco. [2,9]\n";
      cin>> reyb;
      cin>> reyb2;
      system("clear");
   }
   while(reyb<2||reyb>9 || reyb2<2||reyb2>9); 
   
   do{
      cout<<" Ingrese la posicion de la reina blanca. [2,9]\n";
      cin>>reina;
      cin>>reina2;
      system("clear");
   }
   while(reina<2||reina>9||reina2<2||reina2>9);

   do{
      cout<<" Ingrese la posicion del caballo blanco. [2,9]\n";
      cin>>cabb;
      cin>>cabb2;
      system("clear");
   }
   while(cabb<2||cabb>9 || cabb2<2||cabb2>9);
   
   
}
void matrizajedrez (int a, int aa, int b, int bb, int c, int cc, int d, int dd){
   for(i=0;i < 12; i++) {
      ajedrez[0][i] = -1;
      ajedrez[1][i] = -1;

      ajedrez[10][i] = -1;
      ajedrez[11][i] = -1;
   }
   for(i=0;i < 12; i++) {
      ajedrez[i][0] = -1;
      ajedrez[i][1] = -1;

      ajedrez[i][10] = -1;
      ajedrez[i][11] = -1;
   }
   for(i=2;i < 10; i++) {
      for(j=2;j < 10; j++) {
         ajedrez[i][j] = 0;
      }
   }
	//Guardar las posiciones de las fichas en la matriz
	ajedrez[a][aa]=1;
   ajedrez[b][bb]=2;
   ajedrez[c][cc]=3;	
   ajedrez[d][dd]=4;
  
   
   	for(i=0;i < 12; i++) {
      for(j=0;j < 12; j++) {
         cout.width(3);
         cout << ajedrez[i][j] ;
      }
      cout << endl;
   }
}
void pantalla (){
   cout<<"     Determinar el estado de el rey en el tablero de ajedrez\n";
   cout<<"     Fichas negras: Rey=1\n";
   cout<<"     Fichas blancas: Caballo=4, reina=3 y rey=2\n";
   cout<<endl;
}
int ahogado(int rf, int rc, int r2f, int r2c){
   //derminar ahogado, cuando "rey esta en jaque con rey"
   int cont=0;
   //entra en jaque con rey blanco
   if (rf-2==r2f&&rc==r2c||rf+2==r2f&&rc==r2c||rf==r2f&&rc+2==r2c||rf==r2f&&rc-2==r2c
   ||rf-2==r2f&&rc-2==r2c||rf-2==r2f&&rc+2==r2c||rf+2==r2f&&rc+2==r2c||rf+2==r2f&&rc-2==r2c){
      i=0;	
      while(i<8){
         switch (i) {
            case 0:
                  rf-=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 1:
                  rf+=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 2:
                  rc+=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 3:
                  rc-=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 4:
                  rf-=1;
                  rc+=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 5:
                  rf+=1;
                  rc+=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 6:
                  rf+=1;
                  rc-=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               case 7:
                  rf-=1;
                  rc-=1;
                  if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
                     cont++;
                  }
                  break;
               
               default: 
                  break;
            }
         i++;
      }
	  
   }
   
   return cont;
}
int jaquecab (int rf, int rc, int cf, int cc){
   // comprobar jaque con el caballo
   int jaquecab=0;
   if(cf-2==rf&&cc+1==rc||cf-2==rf&&cc-1==rc||cf+2==rf&&cc+1==rc||cf+2==rf&&cc-1==rc
   ||cc+2==rc&&cf+1==rf||cc+2==rc&&cf-1==rf||cc-2==rc&&cf+1==rf||cc-2==rc&&cf-1==rf){
      jaquecab=1;
   }
   return jaquecab;
}
int jaquereina (int rf, int rc, int r2f, int r2c, int raf, int rac){
   //comprobar jaque con reina
   int jaquereina=0;
   for(i=1;i<8;i++){
      if (raf-i==rf&&rac==rc||raf+i==rf&&rac==rc||raf==rf&&rac+i==rc||raf==rf&&rac-i==rc
      ||raf-i==rf&&rac-i==rc||raf-i==rf&&rac+i==rc||raf+i==rf&&rac+i==rc||raf+i==rf&&rac-i==rc){
         for(j=1;j<8;j++){ //j<i ?
            if(raf-i!=r2f&&rac!=r2c||raf+i!=r2f&&rac!=r2c||raf!=r2f&&rac+i!=r2c||raf!=r2f&&rac-i!=r2c
            ||raf-i!=r2f&&rac-i!=r2c||raf-i!=r2f&&rac+i!=r2c||raf+i!=r2f&&rac+i!=r2c||raf+i!=r2f&&rac-i!=r2c){
               jaquereina=1;
            }
         }
      }
   }
   return jaquereina;
}
int jaquemate(int rf, int rc){
   int jaquemate=0;
   i=0;
   while(i<8){
      switch (i)
      {
      case 0:
         rf-=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 1:
         rf+=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 2:
         rc+=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 3:
         rc-=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 4:
         rf-=1;
         rc+=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 5:
         rf+=1;
         rc+=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 6:
         rf+=1;
         rc-=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      case 7:
         rf-=1;
         rc-=1;
         if(jaquecab(rf,rc,cabb,cabb2)==1||jaquereina(rf,rc,reyb,reyb2,reina,reina2)==1){
            jaquemate=1;
         }
         break;
      
      default: 
         break;
      }
      i++;
   }
   return jaquemate;
}
