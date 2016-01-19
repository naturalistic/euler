
public class q46 {
	public static void main(String[] args) {

		long i = 3;
		while(true) {
			if(!isPrime(i)) {
				if (!isGoldbach(i)) {
					System.out.println(i);
					return;
				} else {
					System.out.println("GB: " + i);
				}
			}
			i = i+2;
		}
	}
	
	public static boolean isPrime(long i) {
		if(i == 2) {
			return true;
		}
		if(i < 2 || i % 2 == 0) {
			return false;
		}
		
		long limit = (long)Math.sqrt(i);
		for(long div = 3; div <= limit; div+=2) {
			if(i % div == 0) {
				return false;
			}
		}
		return true;
	}
	
	public static boolean isGoldbach(long i) {
		long j = 1;
		long square = 2*j*j;
		while(square < i) {
			if(isPrime(i-square)) {
				System.out.println(i + ", " + square + ", " + (i-square));
				return true;
			}
			j += 1;
			square = 2*j*j;
		}
		return false;
	}
}
