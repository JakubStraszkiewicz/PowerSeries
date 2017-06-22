#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<vector>
#define ODPRZODU 1
#define ODTYLU 0
using namespace std;
double silnia(int liczba)
{
	float wynik=1;
	for(int i=1;i<=liczba;i++)
		wynik=wynik*i;
	return wynik;
}

double potega(double liczba,int potega)
{
	double wynik=liczba;
	for(int i=1;i<potega;i++)
		wynik*=liczba;
	return wynik;
}
template <typename T>
T sinh_z_poprzedniego(T x,T e,bool wKtoraStrone)
{
	T y=0,sn=x;
	int k=0;
    vector<T> wektor;
	do
	{
		wektor.push_back(sn);
        k++;
		sn=sn*((x*x)/(2*k+1)/(2*k));
	}while(fabs(sn)>=e);
        if(wKtoraStrone)
            for(int i=0;i<k;i++)
                y=y+wektor[i];
        else
            for(int i=k-1;i>=0;i--)
                y=y+wektor[i];
	return y;
}

double blad_teoretyczny(double x,double e)
{
	double sn=0,k=0;
	do
	{
		k++;
		sn = potega(x, 2 * k + 1) / silnia(2 * k + 1);
	} while (fabs(sn) >= e);
	k++;
	sn = potega(x, 2 * k + 1) / silnia(2 * k + 1);
	return sn;
}
template <typename T>
T sinh_z_definicji(T x,T e,bool wKtoraStrone)
{   
        T y=0,sn=x;
        int k=0;
        vector<T> wektor;
        do
        {
			wektor.push_back(sn);
            k=k+1;
			sn = potega(x, 2 * k + 1) / silnia(2 * k + 1);
        }while(fabs(sn)>=e);
        if(wKtoraStrone)
            for(int i=0;i<k;i++)
                y=y+wektor[i];
        else
            for(int i=k-1;i>=0;i--)
                y=y+wektor[i];
        return y;
}

int main()
{
	double wzorzec=sinh(4.0);
	
	FILE* wyjscie;
	wyjscie=fopen("wynik.txt","w");
	fprintf(wyjscie,"Wynik z funkcji bibliotecznej \n");
	fprintf(wyjscie,"%.60F \n",wzorzec);
	
	fprintf(wyjscie,"float liczone z definicji dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",sinh_z_definicji<float>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d bezwzglêdny float liczone z definicji dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_definicji<float>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d wzglêdny float liczone z definicji dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_definicji<float>(4.0,i,ODPRZODU))/wzorzec*100);
	fprintf(wyjscie,"\n");
	
	fprintf(wyjscie,"float liczone z poprzedniego wyrazu dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10) //E-20
		fprintf(wyjscie,"%.60lf \n",sinh_z_poprzedniego<float>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d bezwzglêdny float liczone z poprzedniego dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_poprzedniego<float>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d wzglêdny float liczone z poprzedniego dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_poprzedniego<float>(4.0,i,ODPRZODU))/wzorzec*100);
	fprintf(wyjscie,"\n");
	fprintf(wyjscie,"\n");
	fprintf(wyjscie,"\n");
	
	
	
	fprintf(wyjscie,"float liczone z definicji dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",sinh_z_definicji<float>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d bezwzglêdny float liczone z definicji dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_definicji<float>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d wzglêdny float liczone z definicji dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_definicji<float>(4.0,i,ODTYLU))/wzorzec*100);
	fprintf(wyjscie,"\n");
	
	fprintf(wyjscie,"float liczone z poprzedniego wyrazu dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10) //E-20
		fprintf(wyjscie,"%.60lf \n",sinh_z_poprzedniego<float>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d bezwzglêdny float liczone z poprzedniego dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_poprzedniego<float>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d wzglêdny float liczone z poprzedniego dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_poprzedniego<float>(4.0,i,ODTYLU))/wzorzec*100);
		
	fprintf(wyjscie,"\n");
	fprintf(wyjscie,"---------------------------------------------");
	fprintf(wyjscie,"\n");
	
	fprintf(wyjscie,"double liczone z definicji dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",sinh_z_definicji<double>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d bezwzglêdny double liczone z definicji dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_definicji<double>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d wzglêdny double liczone z definicji dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_definicji<double>(4.0,i,ODPRZODU))/wzorzec*100);
	fprintf(wyjscie,"\n");
	
	fprintf(wyjscie,"double liczone z poprzedniego wyrazu dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10) //E-20
		fprintf(wyjscie,"%.60lf \n",sinh_z_poprzedniego<double>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d bezwzglêdny double liczone z poprzedniego dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_poprzedniego<double>(4.0,i,ODPRZODU));
	fprintf(wyjscie,"b³¹d wzglêdny double liczone z poprzedniego dodawanie od najmniejszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_poprzedniego<double>(4.0,i,ODPRZODU))/wzorzec*100);
	fprintf(wyjscie,"\n");
	fprintf(wyjscie,"\n");
	fprintf(wyjscie,"\n");
	
	
	
	fprintf(wyjscie,"double liczone z definicji dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",sinh_z_definicji<double>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d bezwzglêdny double liczone z definicji dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_definicji<double>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d wzglêdny double liczone z definicji dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_definicji<double>(4.0,i,ODTYLU))/wzorzec*100);
	fprintf(wyjscie,"\n");
	
	fprintf(wyjscie,"double liczone z poprzedniego wyrazu dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10) //E-20
		fprintf(wyjscie,"%.60lf \n",sinh_z_poprzedniego<double>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d bezwzglêdny double liczone z poprzedniego dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.60lf \n",wzorzec-sinh_z_poprzedniego<double>(4.0,i,ODTYLU));
	fprintf(wyjscie,"b³¹d wzglêdny double liczone z poprzedniego dodawanie od najwiekszych \n");
	for(double i=0.1;i>0.00000000000000001;i/=10)
		fprintf(wyjscie,"%.6E \n",(wzorzec-sinh_z_poprzedniego<double>(4.0,i,ODTYLU))/wzorzec*100);

	fprintf(wyjscie,"Roznice miedzy metodami \n");
	for (double i = 0.1;i>0.00000000000000001;i /= 10)
		fprintf(wyjscie, "%.60lf \n", (sinh_z_definicji<double>(4.0,i,ODTYLU) - sinh_z_poprzedniego<double>(4.0, i, ODTYLU)));
	fprintf(wyjscie, "Blad teoretyczny\n");
	for (double i = 0.1;i>0.00000000000000001;i /= 10)
		fprintf(wyjscie, "%.60lf \n", blad_teoretyczny(4.0, i));
		
	fprintf(wyjscie,"B³¹d wzglêdny dla liczenia z poprzedniego \n");
	for (double i = 1;i<=20;i+=0.0001)
		fprintf(wyjscie, "%.60lf \n",fabs((sinh(i) - sinh_z_poprzedniego<double>(i, 0.0000000000000001,ODTYLU))/sinh(i)));

	fprintf(wyjscie, "b³¹d wzglêdny dla liczenia z definicji\n");
	for (double i = 1;i <= 20;i += 0.0001)
		fprintf(wyjscie, "%.60lf \n", fabs((sinh(i)-sinh_z_definicji<double>(i,0.0000000000000001,ODPRZODU))/sinh(i)));

	fprintf(wyjscie,"B³¹d wzglêdny dla dodawania od przodu \n");
	for (double i = 1;i<=20;i+=0.0001)
		fprintf(wyjscie, "%.60lf \n",fabs((sinh(i) - sinh_z_poprzedniego<double>(i, 0.0000000000000001,ODPRZODU))/sinh(i)));
		
	fprintf(wyjscie,"B³¹d wzglêdny dla dodawania od tylu \n");
	for (double i = 1;i<=20;i+=0.0001)
		fprintf(wyjscie, "%.60lf \n",fabs((sinh(i) - sinh_z_poprzedniego<double>(i, 0.0000000000000001,ODTYLU))/sinh(i)));

	return 0;
}
