# Evolutive Algorithm for Triple Collision on Hashing

**Problem:** Given three sets M1, M2 and M3 and n where n is the maximum ammount of hashing work you can do on a round, find a size for M1, M2, M3, where |M1| + |M2| + |M3| = n that maximizes the probability of finding a triple collision, that means, find m1 in M1, m2 in M2 and m3 in M3 where H(m1) == H(m2) == H(m3).

This is done using an evolutive algorithm (describe the individual, fitness calculation, random population generation, crossover, mutation and survival of the fittest method)

Write an article about it and blog post "Developing an Evolutive Algorithm to find triple collision in hashing"

The hashing function used is SHA1 or MD5 due to performance reasons

The algorithm to find the collisions is brute force, hash everyone in M1 and save it, hash everyone in M2, compare with the ones stored and remove the ones that doesn't have a collision, hash everyone in M3 and compare with the ones stored and remove the ones that doesn't have a collision...

Conclusions
