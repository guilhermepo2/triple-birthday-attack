# Evolutive Algorithm for Triple Collision on Hashing

**Problem:** Given three sets M1, M2 and M3 and n where n is the maximum ammount of hashing work you can do on a round, find a size for M1, M2, M3, where |M1| + |M2| + |M3| = n that maximizes the probability of finding a triple collision, that means, find m1 in M1, m2 in M2 and m3 in M3 where H(m1) == H(m2) == H(m3).

It is done using an evolutive algorithm (describe the individual, fitness calculation, random population generation, crossover, mutation and survival of the fittest method)

The hashing function used is SHA1 or MD5 due to performance reasons. It would be better to use even smaller hashing functions (64 or even 32 bits).

The algorithm to find the collisions is brute force, hash everyone in M1 and save it, hash everyone in M2, compare with the ones stored and remove the ones that doesn't have a collision, hash everyone in M3 and compare with the ones stored and remove the ones that doesn't have a collision...

# Implementation Plan

The Algorithm has 2 Modules:
1. **Collision Check:** Given a fixed ammount of work n and the size of M1, M2, M3, where (|M1| + |M2| + |M3| = n) this module will check the sets searching for triple collision and store the messages that originated the collision.
2. **Evolutive Algorithm:** Given the the vector with the size of each set i = (M1,M2,M3) as an individual and being the fitness the ammoumt of collisions found for a given i, this module will perform crossover and mutation operations on the population to search for the optimal individual.

3. Collision Check flow:

  * Create M1, M2, M3 with size of n - this possibly can be too much for the memory to store, it is a good idea to find another hash function to easily generate each message on each set (an int -> hash function maybe)

  * Receive the size of M1, M2 and M3.

  * Search for triple collision using the following algorithm (not optimized pseudo code):

```
stored_hashes_first_round = []
stored_hashes_second_round = []
stored_hashes_third_round = []
collisions = 0
for each m1 in M1:
  stored_hashes_first_round.add(hash(m1))
for each m2 in M2:
  if(hash(m2) in stored_hashes_first_round):
    stored_hashes_second_round.add(hash(m2))
for each m3 in M3:
  if(hash(m3) in stored_hashes_second_round):
    stored_hashes_third_round.add(hash(m3))
    collisions += 1

return collisions
```

4. Evolutive Algorithm:
  * Initialize population with x individuals, where each individual is (|M1|, |M2|, |M3|) initialized randomly, respecting the rule that (|M1| + |M2| + |M3| = n).
  * Calculate the fitness where the fitness is the ammount of collisions for the individual (for a more reliable fitness, create many M1, M2 and M3).
  * Create a new population with crossover and mutation, do not touch the top 10% of the population, evaluate the population again. Survival of the fittest.
  * Do this for a certain ammount of generations.