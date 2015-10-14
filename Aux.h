//
//  Aux.h
//  RSA
//
//  Created by ivan sarno on 21/08/15.
//  Copyright (c) 2015 ivan sarno. All rights reserved.
//
//Version V.3.1

#ifndef __RSA__Aux__
#define __RSA__Aux__
#include <gmpxx.h>
#include <time.h>
#include <stdlib.h>

namespace RSA
{
    namespace Aux
    {
        typedef mpz_class BigInteger;
        BigInteger pow(const BigInteger &base, BigInteger exp);
        BigInteger mod_pow(const BigInteger &base, BigInteger exp, const BigInteger &mod);
        BigInteger inverse(const BigInteger &number, const BigInteger &modulus);
        bool coprime (BigInteger a, BigInteger b);
        //controls for buffers allocation
        void power_buffer_check();
        void power_buffer_init(unsigned int size);
        void power_buffer_release();
        
        //buffer
        extern BigInteger *power_buffer;
        extern unsigned int buffer_size;
        
        class Generator
        {
        public:
            Generator();
            virtual BigInteger get(unsigned int size);//return a positive BigInteger of size bit
        };
        
    }
}

#endif /* defined(__RSA__Aux__) */
