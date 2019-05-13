/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package finonaccisequenceharder;

import java.util.*;
import java.io.*;
import java.math.*;

/**
 *
 * @author Joshua
 */


public class FinonacciSequenceHarder {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        BigInteger a=new BigInteger(next());
        double b=Math.sqrt(5)+1;
        b/=2;
        b=modPow(b,a);
        b/=Math.sqrt(5);
        long c=Math.round(b);
        System.out.println(c);
    }
    static double modPow(double b,BigInteger pow){
        if (pow.equals(BigInteger.ZERO))return 1;
        if (pow.equals(BigInteger.ONE))return b;
        if (pow.mod(BigInteger.TWO).equals(BigInteger.ZERO))return modPow((b*b)%1000000007,pow.divide(BigInteger.valueOf(2)));
        return b*modPow((b*b)%1000000007, pow.divide(BigInteger.valueOf(2)))%1000000007;
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
