/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package frog1;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Frog1 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int a[];
    static int dp[];
    static int size;
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        size = readInt();
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
        if(b+1==size-1)return Math.abs(a[b]-a[b+1])+f(b+1);
        if(Math.abs(a[b]-a[b+1])+f(b+1)<Math.abs(a[b]-a[b+2])+f(b+2)){
            dp[b]=Math.abs(a[b]-a[b+1])+f(b+1);
            return dp[b];
        }else{
            dp[b]=Math.abs(a[b]-a[b+2])+f(b+2);
            return dp[b];
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
