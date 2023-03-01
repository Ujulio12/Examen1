#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>


using namespace std;
const int  Numero_Equipos=5;
const int  equipo1=5;
const int  equipo2=5;
const int  equipo3=5;
const int  equipo4=5;
const int  equipo5=5;
const int  MAX_PUNTUACION=50;
const int  MIN_PUNTUACION=0;
const int  NUMERO_COLUMNAS=4;
const int MAXIMA_LONGITUD_CADENA=100;
float totalPromedio1=0;
float totalPromedio2=0;
float totalPromedio3=0;
const char equipo=5;
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz1(float matriz[Numero_Equipos][NUMERO_COLUMNAS+1]);
void imprimirMatrizLinea();
void imprimirMatriz1(float matriz1[Numero_Equipos][NUMERO_COLUMNAS+1],char equipos[Numero_Equipos][MAXIMA_LONGITUD_CADENA]);




int main()
{
    srand(getpid());
    float matriz1[Numero_Equipos][NUMERO_COLUMNAS+1];
    char equipo1[Numero_Equipos][MAXIMA_LONGITUD_CADENA]{"Equipo1","Equipo2","Equipo3","Equipo4","Equipo5"};
    llenarMatriz1(matriz1);
    imprimirMatriz1(matriz1,equipo1);
}
int busquedaAleatorios(int minimo, int maximo)
{
return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);}
}
void llenarMatriz1(float matriz1[Numero_Equipos][NUMERO_COLUMNAS+1])
{
    int x,y;
    for(y=0; y<Numero_Equipos;y++)
    {
        float suma=0;
        for(x=0;x<NUMERO_COLUMNAS;x++)
        {
            //sumando puntuaciones y guardandolas
            int puntuacion=busquedaAleatorios(MIN_PUNTUACION,MAX_PUNTUACION);
            matriz1[y][x];
            suma=matriz1[y][x]+suma;
        }
        float promedio= suma/NUMERO_COLUMNAS;
        matriz1[y][NUMERO_COLUMNAS]=promedio;
        totalPromedio1=(float)promedio+totalPromedio1;
    }
}
void imprimirMatrizLinea()
{
    int x;
    cout <<"+--------";
    for (x = 0; x < NUMERO_COLUMNAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
void imprimirMatriz1(float matriz1[Numero_Equipos][NUMERO_COLUMNAS+1],char equipo[Numero_Equipos][MAXIMA_LONGITUD_CADENA])
{
    int x,y;
    float promedioMayor=matriz1[0][NUMERO_COLUMNAS];
    float promedioMenor=matriz1[0][NUMERO_COLUMNAS];
    float equipoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    float equipoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    cout<<"\tLIGA PRIMERA DIVISION" <<endl;
    imprimirMatrizLinea();
    cout << setw(9) << "EQUIPO";
    cout << setw(9) << "2010";
    cout << setw(9) << "2011";
    cout << setw(9) << "2012";
    cout << setw(9) << "2013";
    cout << setw(9) << "PROM" <<endl;
    imprimirMatrizLinea();
    promedioMayor=0;
    promedioMenor=100;
    for(y=0; y<Numero_Equipos;y++)
    {
        cout <<"!" << setw(7)<<equipo[y]<<"!";
        for(x=0;x<NUMERO_COLUMNAS;x++)
        {
            int puntuacion=matriz1[y][x];
            cout << setw(8) << puntuacion <<"!";
        }
        float promedio=matriz1[y][NUMERO_COLUMNAS];
        if (promedio>promedioMayor)
        {
            promedioMayor=promedio;
            memcpy(equipoPromedioMayor,equipo[y],MAXIMA_LONGITUD_CADENA);
        }
        if (promedio<promedioMenor)
        {
            promedioMenor=promedio;
            memcpy(equipoPromedioMenor,equipo[y],MAXIMA_LONGITUD_CADENA);
        }
        cout <<setw(8) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    float promedioLigaPD=totalPromedio1/Numero_Equipos;
    cout << "Promedio Mayor del equipo "<< setw(8) << equipoPromedioMayor << "puntuacion: " << setw (8) << promedioMayor <<endl;
    cout << "Promedio Menor del equipo "<< setw(8) << equipoPromedioMenor << "puntuacion: " << setw (8) << promedioMenor <<endl;
    cout << "Promedio total de Liga "<< setw(8) << equipo << "puntuacion: " << setw (8) << promedioLigaPD <<endl;
    cout << "" << endl;


}
