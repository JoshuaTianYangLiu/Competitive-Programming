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
        System.out.println(f(readLong()));
        
    }
    static int f(long n){
        if (n == 0) return 0; 
        
        if (n == 1 || n == 2) return 1;
        
        long k = n%2==0?n/2:(n+1)/2;
        
        if(n%2==0){
            return ((2*f(k-1) + f(k))*f(k))%1000000007;
        }else{
            return (f(k)*f(k) + f(k-1)*f(k-1))%1000000007;
        }
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
