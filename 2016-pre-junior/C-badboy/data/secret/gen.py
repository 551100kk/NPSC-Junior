#!/usr/bin/env python3

import random
import os

ns = [ 1 , 2 , 3 , 10 , 1000 , 1000000 ]
ms = [ 1 , 2 , 3 , 10 , 1000 , 1000000 ]

for N in ns:
    for M in ms:
        if N > M:
            continue
        print( "n_m_%d_%d.in" % ( N , M ) )
        fo = open( "n_m_%d_%d.in" % ( N , M ) , 'w' )
        fo.write( "%d %d\n" % ( N , M ) )
        fo.write( ' '.join(
            str( random.randrange( 1 , 10001 ) ) for i in range( N )
        ) + '\n' )
        fo.write( ' '.join(
            str( random.randrange( 1 , 10001 ) ) for i in range( M )
        ) + '\n' )
        fo.close()
        os.system(
            "../../submissions/accepted/sol < n_m_%d_%d.in > n_m_%d_%d.ans"
            % ( N , M , N , M ) )

N , M = 1000000 , 1000000

print( "n_m_%d_%d_inc.in" % ( N , M ) )
fo = open( "n_m_%d_%d_inc.in" % ( N , M ) , 'w' )
fo.write( "%d %d\n" % ( N , M ) )
fo.write( ' '.join(
    map( str , sorted( ( random.randrange( 1 , 10001 ) for i in range( N ) ) ) ) )
    + '\n' )
fo.write( ' '.join(
    map( str , sorted( ( random.randrange( 1 , 10001 ) for i in range( M ) ) ) ) )
    + '\n' )
fo.close()
os.system(
    "../../submissions/accepted/sol < n_m_%d_%d_inc.in > n_m_%d_%d_inc.ans"
    % ( N , M , N , M ) )


print( "n_m_%d_%d_dec.in" % ( N , M ) )
fo = open( "n_m_%d_%d_dec.in" % ( N , M ) , 'w' )
fo.write( "%d %d\n" % ( N , M ) )
fo.write( ' '.join(
    map( str , sorted( ( random.randrange( 1 , 10001 ) for i in range( N ) ) , reverse=True  ) ) )
    + '\n' )
fo.write( ' '.join(
    map( str , sorted( ( random.randrange( 1 , 10001 ) for i in range( M ) ) , reverse=True  ) ) )
    + '\n' )
fo.close()
os.system(
    "../../submissions/accepted/sol < n_m_%d_%d_dec.in > n_m_%d_%d_dec.ans"
    % ( N , M , N , M ) )


print( "n_m_%d_%d_same.in" % ( N , M ) )
fo = open( "n_m_%d_%d_same.in" % ( N , M ) , 'w' )
fo.write( "%d %d\n" % ( N , M ) )
fo.write( ' '.join(
    str( 7122 ) for i in range( N ) )
    + '\n' )
fo.write( ' '.join(
    str( 2217 ) for i in range( M ) )
    + '\n' )
fo.close()
os.system(
    "../../submissions/accepted/sol < n_m_%d_%d_same.in > n_m_%d_%d_same.ans"
    % ( N , M , N , M ) )
