#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int _MillerRabin(long long p);
int _Fermat(int a,long long p);
int _isPrime(long long p);
long long modulo(long long base, long long exponent, long long mod);


int confiabilityRange = 15;


int main(int argc, char **argv)
{
    int cont = 0;
    for(int i = 5; i < 1000000; i+=2){
        if( _isPrime(i) ){
            printf("Prime number: %d\n",i);
            cont++;
        }
        
    }
    printf("Total de numeros primos: %d", cont);
	return 0;
}







int _isPrime(long long p){
    if( p == 1 || p == 2 || p == 3){
        return 1;
    }
    for(int i = 2; i < 4; i++){
        if( _Fermat(i,p) == 0 ){
            return 0;
        }
    }
    
    if( _MillerRabin(p) )
        return 1;
    else
        return 0;
}


int _Fermat(int a,long long p){
    long long t;
    if( (t = modulo(a, p-1, p)) != 1 ){  //  its composed 100%
        //printf("%lld", t );
        return 0;
    }
    else{                       //may be prime
        return 1;
    }
}

int _MillerRabin(long long p){
    int pass = 0;
    long long d = p - 1;
    int s = 0;
    while( d%2 == 0 ){
        s++;
        d /= 2;
    }
    unsigned int exp = d;
    for(int i = 0 ; i < confiabilityRange ; i++){
        
        long long a = rand() % (p - 1) + 1;
        
        int mod = modulo ( a , exp , p );
        
        if( mod == 1 || mod == -1 ) {
            pass = 1;
            return 1;
        }
        
        mod = mod - p;
        
        if( mod == 1 || mod == -1 ) {
            pass = 1;
            return 1;
        }
        exp *= 2;
        
    }
    if (pass == 1)
        return 1;
    else
        return 0;
        
        
    //return 0;
}














//UTILITY FUNCTIONS


long long modulo(long long base, long long exponent, long long mod){

    long long x = 1;

    long long y = base;

    while (exponent > 0)

    {

        if (exponent % 2 == 1)

            x = (x * y) % mod;

        y = (y * y) % mod;

        exponent = exponent / 2;

    }

    return x % mod;

}