#include <iostream>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
//https://github.com/saulhs12/Ejemplos_enC
using namespace std;
int main(){
    //cantidad de puntos a graficas
    int n = 4;
    //arreglos que contienen las coordenadas de los puntos
    double x[n];
    double y[n];
    //Ciclo para que el usuario ingrese los puntos
    cout<<"Ingresa los puntos a graficar"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Punto "<<i+1<<endl;
        cout<<"x: ";
        cin>>x[i];
        cout<<"y: ";
        cin>>y[i];
    }
    //cosas necesarias para hacer el archivo
    //que contiene las coordenadas
    string command_filename;
    ofstream command_unit;
    string data_filename;
    ofstream data_unit;
    int i;
    string plot_filename;
    //Nombre del archvivo
    string name = "puntos_2";
    //creacion del archivo
    data_filename = name + "_data.dat";
    data_unit.open(data_filename.c_str());
    //escritura del archivo
    for (i = 0; i < n; i++)
    {
        data_unit << x[i] << "  "
            << y[i] << "\n";
    }
    data_unit.close();
    cout << "\n";
    cout << "  Graficar las coordenadas del archivo: \"" << data_filename << "\"\n";
    
    //LLamada a gnuplot para que grafique los puntos
    system("gnuplot -p -e  \"plot 'puntos_2_data.dat'\"");
    plot_filename = name + ".png";
    return 0;
}