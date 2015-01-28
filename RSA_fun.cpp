
//
//  RSA_fun.cpp
//  RSA
//
//  Created by ivan sarno on 21/01/15.
//
//

#include "RSA_fun.h"

Intero RSA_encrypt(Intero message, Key Pubkey)
{
    return modexp(message, Pubkey.E, Pubkey.N);
}

Intero RSA_decrypt(Intero message, Key Privkey)
{
    return modexp(message, Privkey.E, Privkey.N);
}



bool E_check(Intero E, Intero Phi)
{
    return coprime(E,Phi) && (E-1!=Phi/4) && (E-1!=Phi/2);
}

bool Q_check(Intero Q, Intero P)
{
    Intero dif = (P-Q);
    dif.Abs();
    P=(P-1)/2;
    Q=(Q-1)/2;
  
    return coprime(P,Q) && (dif > Distance);
}

void RSA_key_create(Key &Pubkey, Key &Privkey)
{
    Randinit
    Intero primeP= Primegen; //generates prime number for key mod
    Intero primeQ= Primegen;
    
    while (!Q_check(primeQ,primeP)) //make sure it is appropriate for security standards
    {
        primeQ= Primegen;
    }
    
    Intero Phi = (primeP-1) * (primeQ-1);
    Intero N = primeP * primeQ; //Mod of key
    
    Intero E = RandNum;
    E = E % N;//public key
    
    
    while (!E_check(E, Phi)) //make sure it is appropriate for security standards
    {
        E++;
    }
    Pubkey.E = E;
    Pubkey.N = N;
    
    Privkey.E = inverso(E, Phi); //private key
    Privkey.N = N;
}
