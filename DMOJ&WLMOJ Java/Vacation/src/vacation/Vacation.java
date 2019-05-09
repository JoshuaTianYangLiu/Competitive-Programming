/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package vacation;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Vacation {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int act[][];
    static int size;
    static int dp[][];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        size= readInt();
        act=new int[size][3];
        dp=new int[size][3];
        for(int i=0; i<size; i++){
            for(int j=0; j<3; j++){
                act[i][j]=readInt();
                dp[i][j]=-1;
            }
        }
        int max=0;
        for(int i=0; i<3; i++){
            int a=f(i,0);
            if(max<a)max=a;
        }
        System.out.println(max);
    }
    static int f(int a, int d){
        if(d==size)return 0;
        if(dp[d][a]!=-1)return dp[d][a];
        int b;
        int c;
        if(a==0){
            b=1;
            c=2;
        }else if(a==1){
            b=0;
            c=2;
        }else{
            b=0;
            c=1;
        }
        dp[d][a]=Math.max(f(c,d+1)+act[d][c],f(b,d+1)+act[d][b]);
        return dp[d][a];
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
