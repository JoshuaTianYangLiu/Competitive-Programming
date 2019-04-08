/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package shoeshopping;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ShoeShopping {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int size;
    static long dp[];
    static long min[];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        size = readInt();
        dp=new long[size];
        min = new long[size];
        for(int i=0; i<size; i++){
            dp[i]=readInt()*10;
            min[i]=-1;
        }
        System.out.printf("%.1f\n",(f(0)/10.0));
    }
    static long f(int a){
        if(a>=size)return 0;
        if(min[a]!=-1)return min[a];
        if(a+2==size){
            long d= Math.min(dp[dp[a]>dp[a+1]?a:a+1]+dp[dp[a]<dp[a+1]?a:a+1]/2,f(a+1)+dp[a]);
            min[a]=d;
            return d;
        }
        if(a+1==size){
            min[a]=dp[a];
            return dp[a];
        }
        long b;
        long c;
        if(dp[a]<dp[a+1]){
            b=dp[a+1];
            if(dp[a]<dp[a+2])c=dp[a+2];
            else c=dp[a];
        }else{
            b=dp[a];
            if(dp[a+1]<dp[a+2])c=dp[a+2];
            else c=dp[a+1];
        }
        long e =Math.min(Math.min(f(a+2)+dp[dp[a]>dp[a+1]?a:a+1]+dp[dp[a]<dp[a+1]?a:a+1]/2, f(a+3)+c+b),f(a+1)+dp[a]);
        if(min[a]==-1||e<min[a])min[a]=e;
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
