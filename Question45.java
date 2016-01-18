
public class Question45 {

	
	public static void main(String[] args) {
		System.out.println(Next());
	}
	
	public static long Next() {
		long i = 286; // 286
		while(true) {
			long t = Tri(i);
			long j = i/3;
			long p = Pent(j);
			while(p <= t) {
				if(p == t) {
					long k = i/4;
					long h = Hex(k);
					while(h <= t) {
						if(h == t) {
							return t/2;
						}
						k = k+1;
						h = Hex(k);
					}
				}
				j = j+1;
				p = Pent(j);
			}
			i = i+1;
		}
	}
	
	public static long Tri(long i) {
		return i*(i+1); // times 2
	}
	
	public static long Pent(long j) {
		return j*(3*j-1);
	}
	
	public static long Hex(long k) {
		return 2*k*(2*k-1);
	}
}
