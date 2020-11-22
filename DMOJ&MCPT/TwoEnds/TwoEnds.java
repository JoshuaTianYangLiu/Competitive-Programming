/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package twoends;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class TwoEnds {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int a[];
    static int dp[][];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        int j=1;
        while(size!=0){
            a = new int[size];
            dp=new int[size][size];
            int total=0;
            for(int i=0; i<size; i++){
                a[i]=readInt();
                total+=a[i];
                for(int k=0; k<size; k++){
                    dp[i][k]=-1;
                }
            }
            System.out.println("In game "+j+", the greedy strategy might lose by as many as "+(2*f(0,size-1)-total)+" points.");
            size=readInt();
            j++;
        }
    }
    static int f(int l, int r){
        if(l>r)return 0;
        //if right
        if(dp[l][r]!=-1)return dp[l][r];
        int right=0;
        int left=0;
        if(a[l]<a[r-1])right=f(l,r-2)+a[r];
        else right=f(l+1,r-1)+a[r];
        if(a[l+1]<a[r])left=f(l+1,r-1)+a[l];
        else left=f(l+2,r)+a[l];
        dp[l][r]=Math.max(left, right)>dp[l][r]?Math.max(left, right):dp[l][r];
        return Math.max(left, right);
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
