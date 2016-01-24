package com.devdaniel.criminalintent;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by b on 24/01/16.
 */
public class Q50 {
    public static void main(String [ ] args)
    {
        System.out.println(GetMaxPrimeParts(1000000));
    }

    public static int GetMaxPrimeParts(int limit) {
        List<Integer> primes = GetPrimes(limit);
        int max_parts = 0;
        int max_parts_prime = 0;
        int j = 0;
        while(j < primes.size()) {
            int sum = 0;
            int parts = 0;
            int parts_prime = 0;

            int i = j;
            int pi;
            do {
                pi = primes.get(i);
                sum += pi;
                if(isPrime(sum)) {
                    parts = j-i+1;
                    parts_prime = sum;
                }
                i--;
            } while(i >= 0 && sum + pi <= limit);

            if(parts > max_parts) {
                max_parts = parts;
                max_parts_prime = parts_prime;
            }
            j++;
        }
        return max_parts_prime;
    }

    public static List<Integer> GetPrimes(int maxPrime) {
        List<Integer> primes = new ArrayList<Integer>();
        if(2 <= maxPrime) {
            primes.add(2);
        }
        int p = 3;
        while(p <= maxPrime) {
            if (isPrime(p)) {
                primes.add(p);
            }
            p += 2;
        }
        return primes;
    }

    public static boolean isPrime(int p) {
        if(p % 2 == 0) {
            return false;
        }
        int limit = (int)Math.sqrt(p);
        int f = 3;
        while(f <= limit) {
            if(p % f == 0) {
                return false;
            }
            f += 2;
        }
        return true;
    }
}
