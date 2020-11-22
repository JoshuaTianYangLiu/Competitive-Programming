import java.util.*;
import java.io.*;
public class C1355 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
	public static void main(String[]args) throws IOException{
		int a = readInt(); int b = readInt(); int c = readInt(); int d = readInt();
		long sum = 0;
		for(int x = a; x<=b; x++) {
			int y = Math.max(b,c-x+1);
			sum+=(c-Math.max(d+1-x,Math.max(c-x+1,b))+1)*(d-c+1);
			
			for(int y = Math.max(b, c-x+1); y<=c; y++) {
				int max = Math.min(x+y-c,d-c+1);
				sum+=Math.max(0, max);
			}
		}
		System.out.println(sum);
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}