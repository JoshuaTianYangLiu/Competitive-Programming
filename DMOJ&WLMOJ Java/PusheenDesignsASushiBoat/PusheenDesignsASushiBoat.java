/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pusheendesignsasushiboat;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PusheenDesignsASushiBoat {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static long dp[][];
    static int a[];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        a = new int[size+1];
        int k=readInt();
        dp=new long[size+1][k+1];
        for(int i=0; i<size; i++)a[readInt()]++;
        System.out.println(n(size,k));
    }
    static long n(int n,int k){
        if (k==0){
            return 1;
        }
        if (n==0){
            return 0;
        }
        if(dp[n][k]!=0)return dp[n][k];
        dp[n][k]= n(n-1,k)%998244353+(a[n]*n(n-1,k-1))%998244353;
        return dp[n][k];
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
