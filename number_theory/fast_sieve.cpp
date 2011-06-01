/**************************
 * Sieve of Erastosthenes * (fast, memory efficient version)
 **************************
 * Does some magic, after which gP(n) is non-zero iff n is
 * prime. N is the value of the largest prime you will need.
 * Requires N / 16 bytes of memory.
 * WARNING! Only works for odd numbers; deal with even numbers 
 * yourself!
 * If that is unacceptable, add "n==2||(n&1)&&" after the
 * first bracket in the gP() macro.
 * #include <string.h>
 * #include <math.h>
 **/
//Tested with UVA-10311 Goldbach and Euler
//From http://shygypsy.com/tools/

#define N 100000005
unsigned int prime[N / 64];
#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
    memset( prime, -1, sizeof( prime ) );

    unsigned int i;
    unsigned int sqrtN = ( unsigned int )sqrt( ( double )N ) + 1;
    for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
    {
        unsigned int i2 = i + i;
        for( unsigned int j = i * i; j < N; j += i2 ) rP( j );
    }
}
