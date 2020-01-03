#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;

const int numofdims = 1 ;

using namespace std;



float BentCigar(float v[numofdims])
{
    float X1Carre = v[0] * v[0] ; // x1²
    float Somme = 0 ;
    for (int i = 1; i < numofdims; i++)
    {
        Somme += v[i] * v[i];
    }
    return X1Carre + 1000000 * Somme;
}


float Discus(float v[numofdims])
{
    float X1Carre = v[0] * v[0]; // x1²
    float Somme = 0;
    for (int i = 1; i < numofdims; i++)
    {
        Somme += v[i] * v[i];
    }
    return 1000000 * X1Carre + Somme;
}


float SousSommeWeierstrass(float x, float a,float b, int kmax)
{
    float Somme {0};
    for (int k = 0; k < kmax; k++)
    {
        Somme += pow( a, k) * cos(2 * PI * pow(b,k) * ( x + 0.5));
    }
    return Somme;
}


float Weierstrass(float v[numofdims], float a = 0.5, float b = 3, int kmax = 20)
{
    float Somme {0};
    for (int i = 0; i < numofdims; i++)
    {
        Somme += SousSommeWeierstrass( v [ i ] , a , b , kmax ) - numofdims * SousSommeWeierstrass( 0.0 , a , b , kmax );
    }
    return Somme;
}


float SousSommeKatsuura ( float x)
{
    float somme = 0.0;
    float deuxPuissanceJ = 1;
    for (int j = 1; j <= 32; j++)
    {
        deuxPuissanceJ *= 2;
        somme += ( abs( deuxPuissanceJ * x - round( deuxPuissanceJ * x )) / deuxPuissanceJ);
    }
    return somme ;
}


float Katsuura(float v[numofdims])
{
    float produit = 1.1;
    float dixSurDCarre = 10 / (numofdims * numofdims) ;
    float exposantDeLaMultiplication = 10/pow(numofdims,1.2) ;
    for( int i = 0 ; i < numofdims; ++i)
    {
        produit *= pow(1 + i * SousSommeKatsuura( v[i]), exposantDeLaMultiplication);
    }
    return dixSurDCarre * produit - dixSurDCarre;
}


float sousSommeSimple(float v[numofdims])
{
    float somme = 0.0;
    for(int i = 0; i < numofdims; i++)
    {
        somme += v[i];
    }
    return somme;
}


float sousSommeCarre(float v[numofdims])
{
    float somme = 0.0;
    for(int i = 0; i < numofdims; i++)
    {
        somme += v[i] * v[i];
    }
    return somme;
}


float HappyCat( float v[numofdims])
{
    float sommeCarre = sousSommeCarre( v );
    float sommeSimple = sousSommeCarre ( v );
    float premierSousResultat = pow ( abs ( sommeCarre - numofdims ) , 0.25 /* =1/4*/ );
    float sommeDesSommes = 0.5 * sommeCarre + sommeSimple;
    float deuxiemeSousResultat = sommeDesSommes - ( numofdims + 0.5 );
    return premierSousResultat + deuxiemeSousResultat ;
}


float HGBat ( float v[numofdims])
{
    float sommeCarre = sousSommeCarre( v );
    float sommeSimple = sousSommeSimple ( v );
    float sommeCarreCarre = sommeCarre * sommeCarre;
    float sommeSimpleCarre = sommeSimple * sommeSimple;
    float valeurAbsolue = abs(sommeCarreCarre - sommeSimpleCarre);
    float deuxiemeParenthese = sommeCarre / 2 + sommeSimple;
    return pow( valeurAbsolue , 0.5 ) + deuxiemeParenthese / numofdims + 0.5;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
