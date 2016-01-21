
public class Q48 {

	public static void main(String[] args) {
		System.out.println(addSeries(1000));
	}

	public static long addSeries(long n) {
		long total = 0;
		for(int i = 1; i <= n; i++) {
			total = add(total, power(i, i));
		}
		return total;
	}
	
	public static long power(long a, long b) {
		long total = a;
		for(int i = 1; i < b; i++) {
			total = multiply(total, b);
		}
		return total;
	}
	
	public static long multiply(long a, long b) {
		long total = a;
		for(int i = 1; i < b; i++) {
			total = add(total, a);
		}
		return total;
	}
	
	public static long add(long a, long b) {
		long total = a + b;
		while(total >= 10000000000L) {	// larger digits don't affect smaller ones, so can pre-emptively remove
			total -= 10000000000L;
		}
		return total;
	}
}
