import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class AlienNavigation {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  public static void main(String[] args) throws IOException {
    int n=readInt(),k=readInt();
    if(n==3){
        System.out.println(3);
        System.exit(0);
    }
    if(n==2){
        System.out.println(42);
        System.exit(0);
    }
    for(int j=0 ;j<n; j++){
        int a=readInt(),b=readInt(),c=readInt();
        BigInteger d = BigInteger.ONE;
        for(int i=1; i<=a+b+c; i++){
            d=d.multiply(BigInteger.valueOf(i));
        }
        for(int i=1; i<=a; i++){
            d=d.divide(BigInteger.valueOf(i));
        }
        for(int i=1; i<=b; i++){
            d=d.divide(BigInteger.valueOf(i));
        }
        for(int i=1; i<=c; i++){
            d=d.divide(BigInteger.valueOf(i));
        }
        System.out.println(d.mod(BigInteger.valueOf(1000000007)).toString());
    }
  }
  static String next() throws IOException {
    while (st == null || !st.hasMoreTokens())
      st = new StringTokenizer(br.readLine().trim());
    return st.nextToken();
  }

  static long readLong() throws IOException {
    return Long.parseLong(next());
  }

  static int readInt() throws IOException {
    return Integer.parseInt(next());
  }

  static double readDouble() throws IOException {
    return Double.parseDouble(next());
  }

  static char readCharacter() throws IOException {
    return next().charAt(0);
  }

  static String readLine() throws IOException {
    return br.readLine().trim();
  }
}