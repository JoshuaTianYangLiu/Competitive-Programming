/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fibonaccisequence;

import java.io.*;
import java.math.BigInteger;
import java.util.*;

/**
 *
 * @author liuti
 */
public class FibonacciSequence {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String[] args)throws IOException {
        BigInteger a=new BigInteger(next());
        long t[]={0,1,1,1};
        long b[]=fast_pow_mod(t,a);
        System.out.println(b[1]);
    }
    static long[] def={1,0,0,1};
    static long[] fast_pow_mod(long b[],BigInteger x){
        if (x.equals(BigInteger.ZERO))return def;
        if (x.equals(BigInteger.ONE))return b;
        if (x.mod(BigInteger.TWO).equals(BigInteger.ZERO))return fast_pow_mod(mul(b,b), x.divide(BigInteger.valueOf(2)));
        return mul(b,fast_pow_mod(mul(b,b), x.divide(BigInteger.valueOf(2))));
    }
    static long[] mul(long n[],long m[]){
        long a=((n[0]*m[0])%1000000007+(n[1]*m[2])%1000000007)%1000000007;
        long b=((n[0]*m[1])%1000000007+(n[1]*m[3])%1000000007)%1000000007;
        long c=((n[2]*m[0])%1000000007+(n[3]*m[2])%1000000007)%1000000007;
        long d=((n[2]*m[1])%1000000007+(n[3]*m[3])%1000000007)%1000000007;
        long e[]={a,b,c,d};
        return e;
    }
    static String next () throws IOException {
        if (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
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
