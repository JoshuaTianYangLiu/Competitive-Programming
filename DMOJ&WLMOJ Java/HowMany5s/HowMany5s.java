/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package howmany5s;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

/**
 *
 * @author Joshua
 */


public class HowMany5s {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        long r = readInt();
        BigInteger num = new BigInteger(next());
        //long num =readLong();
        BigInteger a = new BigInteger("0");
        BigInteger temp = new BigInteger("0");
        for(int i=1; i<size; i++){
            a = new BigInteger(next());
            temp = a;
            a = a.multiply(num);
            num = num.gcd(temp);
            num = a.divide(num);
            //(a*num/gcd(a,num))%1000000007;
        }
        num = num.add(BigInteger.valueOf(r));
        System.out.println(num.remainder(BigInteger.valueOf(1000000007)));
    }

    static long gcd(long a,long b) {
        while (b != 0) {
            long t =a;
            a=b;
            b=t%b;
        }
        return a;
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
