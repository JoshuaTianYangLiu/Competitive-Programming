import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;

public class PredictingCollisions {

  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  static StringTokenizer st;
  static int fun[] = new int[6];
  static int der[] = new int[6];
  public static void main(String[] args) throws IOException {
    int n = readInt();
    for(int i=n; i>=0; i--){
        fun[i]=readInt();
    }
    int m = readInt();
    for(int i=m; i>=0; i--){
        fun[i]-=readInt();
    }
    for(int i=1; i<6; i++){
        der[i-1]=fun[i]*i;
    }
    double a = (double)readInt();
    double b = (double)readInt();
    if(a==0)a=b;
    BigDecimal c = new BigDecimal(a);
    while(calcFun(c).abs().compareTo(new BigDecimal("0.00000001"))==1){
        c=c.subtract(calcFun(c).divide(calcDer(c),20,RoundingMode.CEILING));
    }
    System.out.println(c.doubleValue());
  }
  static BigDecimal calcFun(BigDecimal a){
    BigDecimal ret = new BigDecimal("0");
    for(int i=0; i<6; i++){
        ret = ret.add(a.pow(i).multiply(new BigDecimal(fun[i])));
    }
    return ret;
  }
  static BigDecimal calcDer(BigDecimal a){
    BigDecimal ret = new BigDecimal("0");
    for(int i=0; i<6; i++){
        ret = ret.add(a.pow(i).multiply(new BigDecimal(der[i])));
    }
    return ret;
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