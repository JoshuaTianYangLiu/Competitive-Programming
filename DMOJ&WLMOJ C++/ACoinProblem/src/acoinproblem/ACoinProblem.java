/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package acoinproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ACoinProblem {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int coin[];
    static int dp[][]=new int[10001][10001];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int q = readInt();
        coin=new int[size];
        for(int i=0; i<size; i++){
            coin[i]=readInt();
        }
        for(int i=0; i<10001; i++){
            for(int j=0; j<10001; j++){
                dp[i][j]=-2;
            }
        }
        
        for(int i=0; i<q; i++){
            int a = readInt();
            int b = readInt();
            System.out.println(find(a,b));
        }
    }
    static int find(int n,int q){
        if(n==0){
            dp[n][q]=0;
            return 0;
        }
        if(n<0){
            return -1;
        }
        if(dp[n][q]!=-2)return dp[n][q];
        int min=Integer.MAX_VALUE;
        boolean changed=false;
        for(int i=0; i<q;i++){
            int a=find(n-coin[i],q);
            if(n-coin[i]>-1)dp[n-coin[i]][q]=a;
            if(a!=-1){
                changed=true;
                if(a<min)min=++a;
            }
        }
        if(changed){
            return min;
        }
        return -1;
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
