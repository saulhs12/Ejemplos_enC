//Calculadora Algebraica
//Hecho por Saúl Herrera Saavedra
//https://github.com/saulhs12/Ejemplos_enC
#include <iostream>
#include <math.h>
using namespace std;

//Estructura que contiene dos soluciones de tipo reales de la ecuacion cuadratica
typedef struct raiz_Cuadrada{
    double sol_1;
    double sol_2;
}raiz_Cuadrada;
//Estructura que contiene una solucion de tipo raiz_cuadratica y una solucion de tipo Real
typedef struct raiz_Cubica{
    raiz_Cuadrada sol_1c;
    double sol_3;
    
}raiz_Cubica;
//Estructura que contiene las coordenadas de un punto
typedef struct Punto
{
    double x;
    double y;
}Punto;
//Estructura que contiene los dos puntos de una recta
typedef struct Recta
{
    Punto punto_1;
    Punto punto_2;
}Recta;


/* Funcion que devuelve una estructura de datos de 
tipo raiz_Cuadrada que contiene las soluciones de la 
ecuacion cuadratica dada por el usuario
la funcion recibe 3 datos de tipo double que son los
coeficientes de la ecuacion*/
raiz_Cuadrada raices_cuadradas(double a, double b, double c){
    /*se declara la variable de dentro_raiz que representa el 
    contenido dentro de la raiz de la formula cuadratica*/
    double dentro_raiz;
    // se declara las soluciones que son de tipo raiz_Cuadrada, es lo que va a devolver la funcion
    raiz_Cuadrada soluciones;
    //se calcula lo que esta dentro de la raiz de la formula cuadratica
    dentro_raiz = (pow(b,2))-(4*a*c);
    //se escoje dependiendo si lo que esta dentro de la raiz
    //es menor a 0 o mayor o igual a 0

    if (dentro_raiz<0){
        //cuando es menor que 0
        //lo que esta dentro de la raiz lo convertimos en valor absoluto
        //osea lo convertimos en positivo
        dentro_raiz=-1*dentro_raiz;
        soluciones.sol_1 = (+sqrt(dentro_raiz));
        soluciones.sol_2 = (-sqrt(dentro_raiz));
        double sol_real;
        //tomamos la parte real de ambas soluciones
        sol_real=-b/(2*a);
        if(sol_real ==0){
            soluciones.sol_1 = (+sqrt(dentro_raiz))/2*a;
            soluciones.sol_2 = (-sqrt(dentro_raiz))/2*a;
        }
        //truqueamos la solucion y lo llamamos a que es
        //la solucion compleja
        cout<<"Solucion 1: "<<sol_real<<" +("<<soluciones.sol_1<<") i"<<endl;
        cout<<"Solucion 2: "<<sol_real<<" +("<<soluciones.sol_2<<") i"<<endl;
    }
    else{
        //imprime las solucionesvoid
        soluciones.sol_1= (-b + sqrt(dentro_raiz))/2*a;
        soluciones.sol_2= (-b- sqrt(dentro_raiz))/2*a;
        cout<<"Solucion 1: "<<soluciones.sol_1<<endl;
        cout<<"Solucion 2: "<<soluciones.sol_2<<endl;
    }
    // regresa las soluciones
    return soluciones;
}

/*Funcion que devuelve una estructura de datos de 
tipo raiz_Cubica que contiene las soluciones de la 
ecuacion cubica dada por el usuario
la funcion recibe 4 datos de tipo double que son los
coeficientes de la ecuacion*/
raiz_Cubica raices_cubicas(int x3,int x2,int x1,int ind){
    //cantidad de numeros * 2 para el algoritmo de Rufinni
    raiz_Cubica solucion;
    
    //Declaracion de lo que la funcion va a devolver
    // El programa recorre 2000 numeros para encontrar
    // el numero necesario para el algoritmo de Rufinivoid
    //declaracion de los coeficientes necesarios para resolver la ecuacion c
    //cuadratica que se forma gracias a rufini
    int caso_p;
    // Variables necesarias para Rufini
	int n_x2,n_x1,n_ind,  z_x,z_x2,z_x1,z_ind;
    double a,b,c;
		
    caso_p = 10;
    
    int min= -caso_p;
    //Algoritmo de Rufini (Lo hice hace mucho ya ni lo entiendo, pero funciona xd)
    while (min<= caso_p)
    {
        n_x2 = min * x3;
        z_x2 = n_x2+ x2;
        n_x1 = min * z_x2;
        z_x1 = x1 + n_x1;
        n_ind = min * z_x1;
        z_ind = ind + n_ind;
        //condicion para encontrar la solucion real entera
        if(z_ind == 0){
            a = x3;
            b = z_x2;
            c = z_x1;
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<c<<endl;
            solucion.sol_3 = min;
        }
        //printf("i: %d solucion: %.1f",min ,sol_x1);
        min++;
    }
    //Le asignamos a los primeros dos soluciones llamando a la funcion raices_cuadraticas con
    //los parametros de a,b,c que obtuvimmos anteriormente
    solucion.sol_1c = raices_cuadradas(a,b,c);
    //cout<<"Solución 1: "<<sol_real<<" +("<<solucion.sol_1c.sol_1<<") i"<<endl;
    //cout<<"Solución 2: "<<sol_real<<" +("<<solucion.sol_1c.sol_2<<") i"<<endl;
    //imprime la solucion real
    cout<<"Solucion 3: "<<solucion.sol_3<<endl; 
    //se devuelven ambas soluciones
    return solucion;
}
//Funcion para crear un punto
Punto crear_Punto(struct Punto punto ){
    cout<<"Ingresa los valores del punto "<<endl;
    cout<<"x = ";
    cin>>punto.x;
    cout<<"y = ";
    cin>>punto.y;
    return punto;
}
//Funcion para sacar la raiz de la recta
double raiz_recta(Recta recta){
    //declaramo la pendiente (m) y b
    double m,b;
    //calculamos la pendiente
    m = (recta.punto_2.y - recta.punto_1.y)/(recta.punto_2.x-recta.punto_1.x);
    // calculamos b
    b = recta.punto_1.y -(m*recta.punto_1.x);
    // calculamos la raiz
    double raiz= -b/m;
    //imprimimos los resultados
    cout<<"---------------------"<<endl;
    cout<<"m: "<<m<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"La raiz es: "<<raiz<<endl;
    return raiz;
}
//funcion del menu
void Menu(int seleccion){
    if (seleccion == 1)
    {
        //ec Cuadratica
        double a,b,c;
        //El usuario ingresa los coeficientes de la ecuacion
        cout<<"Ingresa el coeficiente de x^2: ";
        cin>>a;
        cout<<"Ingresa el coeficiente de x: ";
        cin>>b;
        cout<<"Ingresa el término independiente: ";
        cin>>c;
        //Llamada a la funcion con los parametros ingresados por el usuario
        raices_cuadradas(a,b,c);

    }   
    else if(seleccion==2){
        //ec cubica
        double x1,x2,x3,ind;
        //El usuario ingresa los coeficientes de la ecuacion
        cout<<"Ingresa el coeficiente de x^3: ";
        cin>>x3;
        cout<<"Ingresa el coeficiente de x^2: ";
        cin>>x2;
        cout<<"Ingresa el coeficiente de x: ";
        cin>>x1;
        cout<<"Ingresa el término independiente: ";
        cin>>ind;
        //Llamada a la funcion con los parametros ingresados por el usuario
        raices_cubicas(x3,x2,x1,ind);
    }
    else if(seleccion==3){
        //recta
        Punto punto_1,punto_2;
        Recta recta;
        //el usuario crea los puntos necesarios
        cout<<"Ingresa las coordenadas del punto 1"<<endl;
        punto_1=crear_Punto(punto_1);
        cout<<"Ingresa las coordenadas del punto 2"<<endl;
        punto_2=crear_Punto(punto_2);
        //se crea la recta a partir de los dos puntos
        recta.punto_1=punto_1;
        recta.punto_2=punto_2;
        //se llama a la funcion y como parametro la recta ya construida
        raiz_recta(recta);
    }
    //por si el usuario ingresa algo erroneo
    else{
        cout<<"Por favor ingresa un número válido del Menú"<<endl;
    }
}

int main() {
	// variable para salir o seguir en el menu
    bool salir = true;
    //variable para elegir una opcion
    int seleccion = 0;
 
    //Ciclo do while para un menu hasta que el usuario lo quiera terminar
    do
        {
            int *i;
            i = new int;
            cout<<"Selecciona la opción que quiera realizar"<<endl;
            cout<<"****************************"<<endl;
            cout<<"[1] Calcular las raices de una ecuación Cuadratica"<<endl;
            cout<<"[2] Calcular las raices de una ecuación Cúbica"<<endl;
            cout<<"[3] Calcular las raices de una recta"<<endl;
            cin>>seleccion;
            Menu(seleccion);
            
            cout<<"Para realizar otra operacion presione 1"<<endl;
            cout<<"Para salir del programa presione 2"<<endl;
            int se;
            cin>>se;
            if (se!=1) salir=false;
        } while (salir == true);
	return 0;
}
