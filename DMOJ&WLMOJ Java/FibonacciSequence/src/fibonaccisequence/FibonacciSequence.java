/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fibonaccisequence;

import java.io.*;
import java.math.BigDecimal;
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
        double phi = (Math.sqrt(5)+1)/2;
        BigDecimal n1 = new BigDecimal(phi);
        BigDecimal n2 = new BigDecimal(-1*phi);
        BigDecimal d = new BigDecimal(Math.sqrt(5));
        long a = readLong();
        if(a<3){
            System.out.println(1);
        }else{
            n1=
        }
    }
    static int fib(int n){ 
    int F[][] = new int[][]{{1,1},{1,0}}; 
    if (n == 0) 
        return 0; 
    power(F, n-1); 
       
    return F[0][0]; 
    } 
       
    static void multiply(int F[][], int M[][]){ 
    int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
    int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
    int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
    int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
      
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
    }
    static void power(int F[][], int n){ 
    if( n == 0 || n == 1) 
      return; 
    int M[][] = new int[][]{{1,1},{1,0}}; 
       
    power(F, n/2); 
    multiply(F, F); 
       
    if (n%2 != 0) 
       multiply(F, M); 
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
