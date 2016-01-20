import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Q47 {

	public static void main(String[] args) {
		setupPrimes();
		long i = 2;
		int factors = 4;
		long first = 0;
		long consecutive = 0;
		while(true) {
			if(hasPrimeFactors(i, factors)) {
				if(consecutive == 0) {
					first = i;
				}
				consecutive = consecutive+1;
				if(consecutive == factors) {
					System.out.println(first);;
					return;
				}
			} else {
				consecutive = 0;
			}
			i = i+1;
		}
	}
	
	public static void setupPrimes() {
		primes.add(new Long(2));
		primes.add(new Long(3));
	}
	
	public static List<Long> primes = new ArrayList<Long>();
	
	public static long getPrime(int i) {
		while(primes.size() <= i) {
			long nextPrime = primes.get(primes.size()-1) + 2;
			while(!isPrime(nextPrime)) {
				nextPrime = nextPrime + 2;
			}
			primes.add(nextPrime);
		}
		return primes.get(i-1);
	}
	
	public static boolean hasPrimeFactors(long i, int n) {
		long pfactors = 0;
		int j = 1;
		long prime = getPrime(j);
		while(i >= prime) {
			if(i % prime == 0) {
				while(i % prime == 0) {
					i /= prime;
				}
				pfactors = pfactors + 1;
				if(pfactors == n) {
					return true;
				}
			}
			j = j + 1;
			prime = getPrime(j);
		}
		return false;
	}
	
	// TODO: just set this to try everything 2, 3, 5, 7, 9 ect. probably faster
	public static boolean isPrime(long i) {
		long limit = (long) Math.sqrt(i);
		for(Iterator<Long> it = primes.iterator(); it.hasNext();) {
			long div = (long)it.next();
			if(div > limit) {
				break;
			}
			if(i % div == 0) {
				return false;
			}
		}
		return true;
	}
}
