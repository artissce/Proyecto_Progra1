#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>

//DECLARACION DE FUNCIONES
void menu();
void presentacion();
void encabezado();
void lectura(float nums[],int n);
void despliegue (float calif[],int n);
int NumeroDatos(float nums[]);
int MenuPrimeraOpcion(void);

//tendencia central
float media(float nums[],int n);
void ordenar(float nums[], int n);
float mediana(float nums[],int n);
float moda(float nums[],int n);
//variabilidad
float rango(float nums[],int n);
float varianza(float med,float nums[],int n);
float desvar(float var);
float coefvar(float x, float desvari);
//grafica
int numInt(int n);
int anchInt(int inter, float rang);
void cls(void);
void grafica(float nums[],int n);
float intervalos(int n);

float timer;

void gotoxy(int x, int y) //funcion gotoxy para poder imprimir en coordenadas asignadas por nosotros
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}
	
int selector(int x,int y,int n){
	char tecla='\0'; //variables
	int opc;
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); //colores
	gotoxy(x,y);
	printf("%c",16); //triangulito
	do{
		if(kbhit()) {
			tecla=getch();
			
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			gotoxy(x,y);
			printf("%c",16);
			if(opc>1&&tecla==72){ //si opcion es mayor que uno y la tecla es hacia arriba
				y--; //se resta coordenada
				opc--; //se resta opcion
		}
			if(opc<n&&tecla==80){//si opcion es menor que el tope y la tecla es hacia abajo
				y++; //se suma coordenada
				opc++; //se suma opcion
		}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			gotoxy(x,y);
			printf("%c",16);//bara que parpadea
		}
	}while(tecla!=13);//mientras la tecla no sea enter
	return(opc);
}

void bordes(int opc){
	int x,y,i,j;
	timer=1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	switch(opc){
		case 1:
			y=3;
			i=76;
			j=9;
			for(x=20;x<77;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(i,7);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=76;
			j=9;
			x=20;
			for(y=3;y<10;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			
			y=13;
			i=85;
			j=24;
			for(x=11;x<86;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=85;
			j=24;
			x=11;
			for(y=13;y<25;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			break;
			
		case 2:
			y=3;
			i=69;
			j=10;
			for(x=20;x<70;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(x,5);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=70;
			j=10;
			x=20;
			for(y=3;y<11;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			break;	
		case 3:
			timer=1; 
			y=3;
			i=89;
			j=11;
			for(x=20;x<90;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(x,5);
				printf("-"); Sleep(timer);
				gotoxy(i,9);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=90;
			j=11;
			x=20;
			for(y=3;y<12;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			break;
				
		case 4:
			timer=1; 
			y=3;
			i=45;
			j=11;
			for(x=15;x<46;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(x,5);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=45;
			j=11;
			x=15;
			for(y=3;y<12;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			break;
		case 5:
			timer=1; 
			y=3;
			i=55;
			j=13;
			for(x=15;x<56;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(x,5);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=55;
			j=13;
			x=15;
			for(y=3;y<14;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			break;
		case 6
		:;
			for(x=23;x<57;x++){
				gotoxy(x,1);
				printf("-");Sleep(timer);
				gotoxy(x,3);
				printf("-");Sleep(timer);
				gotoxy(x,7);
				printf("-");Sleep(timer);
				
			}
			

			for(y=1;y<8;y++){
				gotoxy(23,y);
				printf("|");Sleep(timer);
				gotoxy(57,y);
				printf("|");Sleep(timer);
			}
			break;
		case 7: 
			y=2;
			i=54;
			j=6;
			for(x=38;x<55;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=54;
			j=6;
			x=38;
			for(y=2;y<7;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			
			y=13;
			i=85;
			j=24;
			for(x=11;x<86;x++){
				gotoxy(x,y);
				printf("-"); Sleep(timer);
				gotoxy(i,j);
				printf("-"); Sleep(timer);
				i--;
			}
			
			i=85;
			j=24;
			x=11;
			for(y=13;y<25;y++){
				gotoxy(x,y);
				printf("|"); Sleep(timer);
				gotoxy(i,j);
				printf("|"); Sleep(timer);
				j--;
			}
			break;
	}
}
	
void gatos(void){
	   gotoxy(12,14);
    printf("----------------------/^--^/-----/^--^/-----/^--^/-----------------------");
     gotoxy(12,15);
    printf("----------------------/____/-----/____/-----/____/-----------------------");
     gotoxy(12,16);
    printf("---------------------/------/---/------/---/-------/---------------------");
     gotoxy(12,17);
    printf("--------------------|--------|-|--------|-|--------|---------------------");
     gotoxy(12,18);
    printf("---------------------/__--__/---/__--__/---/__--__/----------------------");
     gotoxy(12,19);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("|^|^|^|^|^|^|^|^|^|^|^|^");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("^|^|^|^");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("^|^|^|^|^");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("^|^|^|^|^|^|^|^|^|^|^|^|");
     gotoxy(12,20);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("|_|_|_|_|_|_|_|_|_|_|_|_|");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("|_|_|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("|_|_|_|_|_|_");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("_|_|_|_|_|_|_|_|_|_|_|");
     gotoxy(12,21);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("########################");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("######");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("###########");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("/-/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("#######################");
     gotoxy(12,22);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("|_|_|_|_|_|_|_|_|_|_|_|_");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("//");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("||_|_|_|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("//");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("_|_|_|_|_|_|");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	printf("//");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	printf("|_|_|_|_|_|_|_|_|_|_|_|");
     gotoxy(12,23);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|");
}
FILE *Archivo;

//FUNCION PRINCIPAL
int main(){
    setlocale(LC_ALL, "Spanish");
    encabezado();
    menu();
	return 0;
}


//FUNCIONES

//limpia pantalla
void cls(void){
    system("cls");
    return;
}

//presenta
void encabezado(){
	bordes(1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(30,4);
	printf("177932 - Cuenca Esquivel Ana Karen");
	gotoxy(27,5);
	printf("177520 - Esquivel Correa Juan Francisco\n");
	gotoxy(24,6);
    printf("MEDIDAS DE TENDENCIA CENTRAL, VARIANZA Y GRAFICA");
    
    
	gatos();
    
    gotoxy(32,8);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    printf("PRESIONE ENTER PARA CONTINUAR ");
    
}



void presentacion(){
	getch();
	cls();
	bordes(2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(30,4);
    printf("Selecciona una opcion: ");
    gotoxy(24,6);
    printf("1.-Consultar datos o modificacion de datos");
    gotoxy(24,7);
    printf("2.-Desplegar estadisticas");
    gotoxy(24,8);
    printf("3-.Ver grafica");
    gotoxy(24,9);
    printf("4-.SALIR\n");
    
}
//menu para escoger opcion
void menu(){
    int op,n,op2;   
    float nums[100] = {0};
    /*
        float*(accede/sigue memoria) nums (promesita)= float nums[tamano especifico];

        &variale = direccion de la variable;

        SOLO SI ES PUNTERO
        *variable = apuntar a valor
        variable = direccion

        MALLOC->funcion que da ubicaciones de memoria
        en bits

    */
    do{ 
   		n=NumeroDatos(nums);
   		presentacion(); 
        op=selector(21,6,4);
        switch(op){
            case 1:
            	cls();
            	bordes(3);
            	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            	gotoxy(35,4);
                printf("ELEGISTE LA PRIMERA OPCION");
                gotoxy(24,6);
                printf("Deseas ver los datos o modificar los datos andetro del archivo?");
                gotoxy(24,7);
                printf("1.Ver datos");
                gotoxy(24,8);
                printf("2.Editar datos");
                op2=selector(21,7,2);
                switch(op2){
                	case 1: 
                		gotoxy(24,10);
			        	printf("Escogiste: Ver datos");
			        	getch();
                		cls();
						lectura(nums, n);
			            cls();
			            /*gotoxy(20,4);
			            printf("Los datos obtenidos son: ");
			            despliegue(nums,n);
			            getch();
			            cls();*/
			            ordenar(nums,n);
			        	break;
			        case 2:
			        	system("notepad Datos.txt");
			        	gotoxy(24,10);
			        	printf("Perfecto, datos actualizados :)");
			        	break;
			        	op=1;
				}
				break;
                
            case 2: //desplegar estadisticas
           		cls();
                ordenar(nums,n);
                getch();
			    cls();
			    bordes(4);
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			    gotoxy(20,4);
			    printf("ESTADISTICAS");
			    gotoxy(20,6);
                printf("La media es: %.2f",media(nums,n));
                gotoxy(20,8);
                printf("La mediana es: %.2f",mediana(nums,n));
                gotoxy(20,10);
                printf("La moda es: %.2f",moda(nums,n));
                getch();
			    cls();
			    bordes(5);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			    gotoxy(20,4);
                printf("MEDIDAS DE VARIANZA");
                gotoxy(20,6);
                printf("El rango es: %.2f",rango(nums,n));
                float med=media(nums,n);
                gotoxy(20,8);
                printf("La varianza es: %.2f",varianza(med,nums,n));
                float var=varianza(med,nums,n);
                gotoxy(20,10);
                printf("La desviacion estandar %.2f",desvar(var));
                float desvari=desvar(var);
                gotoxy(20,12);
                printf("El coeficiente de varianza: %.2f",coefvar(med,desvari));
                break;
            case 3:
            	cls();
            	bordes(6);
            	gotoxy(26,2);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                printf("ELEGISTE LA TERCERA OPCION");
                grafica(nums,n);
                break;

            case 4:
            	cls();
            	bordes(7);
            	gotoxy(40,4);
            	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                printf("Vuelva pronto!");
                gatos();
                break;
        }
    }while(op!=4);//terminar sesion
}




int NumeroDatos(float nums[]){
	int i,n;
	Archivo = fopen("Datos.txt", "r");
		
	if(Archivo == NULL)
	{
		printf("\nFichero no existe! \nPor favor creelo");
		
	
	}
	
	n=0;
	i=0;
	while (feof(Archivo) == 0){
	fscanf(Archivo,"%f", &nums[i]);
	n++;
	i++;
	}
	  
	fclose(Archivo);
	return (n);
	
}



void lectura(float nums[],int n){
	int i,j,x,y,nr=1,pr;

	j=0;
	x=15;
	y=3;
	for(i=0; i<n; i++){
	gotoxy(x,y);
	printf("%.2f\t", nums[i]);
	j++;
	x=x+7;
	if(j%10==0){
		x=15;
		y=y+2;
		nr++;
	}
	}

	gotoxy(43,1);
	printf("CALIFICACIONES: ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	y=2;
	j=4;
	for(pr=nr;pr>0;pr=pr-1){
		i=92;
		for(x=10;x<93;x++){
		gotoxy(x,y);
		printf("-"); Sleep(timer);
		/*gotoxy(i,j);
		printf("-"); Sleep(timer);*/
		i--;
		}
		j=j+2;
		y=y+2;
	}
	
	
	for(x=10;x<93;x++){
	gotoxy(x,y);
	printf("-"); Sleep(timer);
	}
	
	
	y=2;
	i=92;
	x=10;
	for(pr=nr;pr>0;pr=pr-1){
		j=y+2;
	for(y;y<j;y++){
		gotoxy(x,y);
		printf("|"); Sleep(timer);
		gotoxy(i,y);
		printf("|"); Sleep(timer);
	}
	}
	
	
	
	y=2;
	x=23;
	for(pr=nr;pr>0;pr=pr-1){
	j=y+2;
	for(y;y<j;y++){
		gotoxy(21,y);
		printf("|"); 
		gotoxy(28,y);
		printf("|"); 
		gotoxy(35,y);
		printf("|"); 
		gotoxy(42,y);
		printf("|"); 
		gotoxy(49,y);
		printf("|"); 
		gotoxy(56,y);
		printf("|"); 
		gotoxy(63,y);
		printf("|"); 
		gotoxy(70,y);
		printf("|"); 
		gotoxy(77,y);
		printf("|"); 
	}
	}
	
	  

	getch();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	
}


/*void despliegue (float nums[],int n){
	int i,x,y;
	
	x=20;
	y=6;
	for (i=0;i<n;i++){
		gotoxy(x,y);
		printf("La calificacion %d es: %.2f",i,nums[i]);
		y++;
	}
}*/

//Funciones para medidas de tendecia central
void ordenar(float nums[], int n){
	float aux;
	int i, j,x,y,nr=1,pr;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(nums[j] > nums[j+1]){
				aux = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = aux;
			}
		}
	}
	gotoxy(37,1);
	printf("CALIFICACIONES ORDENADAS: ");
	j=0;
	x=15;
	y=3;
	for(i=0; i<n; i++){
	gotoxy(x,y);
	printf("%.2f\t", nums[i]);
	j++;
	x=x+7;
	if(j%10==0){
		x=15;
		y=y+2;
		nr++;
	}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	y=2;
	j=4;
	for(pr=nr;pr>0;pr=pr-1){
		i=92;
		for(x=10;x<93;x++){
		gotoxy(x,y);
		printf("-"); Sleep(timer);
		/*gotoxy(i,j);
		printf("-"); Sleep(timer);*/
		i--;
		}
		j=j+2;
		y=y+2;
	}
	
	
	for(x=10;x<93;x++){
	gotoxy(x,y);
	printf("-"); Sleep(timer);
	}
	
	
	y=2;
	i=92;
	x=10;
	for(pr=nr;pr>0;pr=pr-1){
		j=y+2;
	for(y;y<j;y++){
		gotoxy(x,y);
		printf("|"); Sleep(timer);
		gotoxy(i,y);
		printf("|"); Sleep(timer);
	}
	}
	
	
	
	y=2;
	x=23;
	for(pr=nr;pr>0;pr=pr-1){
	j=y+2;
	for(y;y<j;y++){
		gotoxy(21,y);
		printf("|"); 
		gotoxy(28,y);
		printf("|"); 
		gotoxy(35,y);
		printf("|"); 
		gotoxy(42,y);
		printf("|"); 
		gotoxy(49,y);
		printf("|"); 
		gotoxy(56,y);
		printf("|"); 
		gotoxy(63,y);
		printf("|"); 
		gotoxy(70,y);
		printf("|"); 
		gotoxy(77,y);
		printf("|");  
	}
	}
	
	  

	getch();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

float mediana(float nums[],int n){
	float me=0;
	if (n%2==0)//par
		me=(nums[(n/2)-1] + nums[n/2])/ 2;
	else//impar
		me=nums[((n+1)/2)-1];
	return me;		
}

float media(float nums[],int n){
	float x=0;
	int i;
	for(i=0;i<n;i++){
		x+=nums[i];
	}
	x/=n;
	return x;
}
float moda(float nums[],int n){
	float may=0;
	float mod=0;
	int i,j;
	for (i=0; i<(n); i++){
		int cont=0;
		for (j=i+1; j<n; j++){
			if (nums[i]==nums[j])
				cont++;
		}
		if (cont>may)
		{
			may=cont;
			mod=nums[i];
		}
	}
	return mod;
}
//Medidas de variabilidad
float rango(float nums[],int n){//sin declarar
	float aux;
	int i, j,x,y,nr=1,pr;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(nums[j] > nums[j+1]){
				aux = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = aux;
			}
		}
	}

    float ran;
    ran=nums[n]-nums[0];
    return ran;
}

//float resultado = varianza(media(nums,9),nums,7);

float varianza(float med,float nums[],int n){
    float var=0;
    int i;
    for(i=0;i<n;i++){
        var=var+pow(nums[i]-med,2);
    }
    return var/(n);
}

float desvar(float var){
    float desvari=0;
	desvari=sqrt(var);
	return desvari;
}
float coefvar(float med, float desvari){
    float cv=0;
	cv=med/desvari;
    return cv;
}
//Grafica
int numInt(int n){
    return 1+3.32*log(n);
}
int anchInt(int inter, float rang){
    return printf("El ancho de los intervalos es: %f",rang/inter);
}

float intervalos(int n){
	float numintervalos;
	
	numintervalos=(3.32*log10(n))+1;
	return (round(numintervalos));
}

void grafica(float nums[],int n){
	int x,y,i,j,z,u,r;
	timer=80;
	float rangografica;
	float numerint,ancho,primero,segundo;

	rangografica=rango(nums,n);
	numerint=intervalos(n);
	ancho=rangografica/numerint;
	gotoxy(25,4);
	printf("Rango: %.2f",rangografica);
	gotoxy(25,5);
	printf("Ancho de intervalos: %.2f", ancho);
	gotoxy(25,6);
	printf("Numero de intervalos: %.2f", numerint);
		
	x=15;
	y=10;
	r=10;
	primero=nums[0];
	
	for(i=0;i<numerint;i++){
		segundo=primero+ancho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		for(z=12;z<74;z++){
			gotoxy(z,y-1);
			printf("-"); 
			gotoxy(z,y+1);
			printf("-");
		}
			
		u=r+2;
		for(r;r<u;r++){
			gotoxy(12,r);
			printf("|"); 
			gotoxy(35,r);
			printf("|"); 
			gotoxy(73,r);
			printf("|"); 
			
		}
		gotoxy(x,y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		printf("%.2f" ,primero);Sleep(timer); printf(" --");Sleep(timer); printf(" %.2f",segundo);Sleep(timer);
		gotoxy(40,y);
		for(j=0;j<n;j++){
			if(nums[j]>=primero && nums[j]<=segundo){
				printf("%c",4); Sleep(timer);
			}
		}
		primero=segundo;
		y=y+2;
	}
	
}
//Funciones para medidas de variabilidad




/*Grafica
- Rango //listo
- # Intervalos //listo
- Ancho intervalo //listo
- Calcular frecuencia-> conteo
*/
