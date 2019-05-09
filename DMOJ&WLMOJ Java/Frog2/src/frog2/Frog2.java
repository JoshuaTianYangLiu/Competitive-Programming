/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package frog2;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Frog2 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int a[];
    static int dp[];
    static int size;
    static int k;
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        size = readInt();
        k=readInt();
        dp = new int[size];
        a = new int[size];
        for(int i=0; i<size; i++){
            dp[i]=-1;
            a[i]=readInt();
        }
        System.out.println(f(0));
    }
    static int f(int b){
        if(dp[b]!=-1)return dp[b];
        if(b==size-1)return 0;
        int min=Integer.MAX_VALUE;
        for(int i=1; i<=Math.min(k, size-b-1); i++){
            int c = Math.abs(a[b]-a[b+i])+f(b+i);
            min=c<min?c:min;
        }
        dp[b]=min;
        return dp[b];
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
