/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package topickornottopick;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ToPickOrNotToPick {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static int dp[];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int a[] = new int[size+1];
        dp=new int[size+1];
        Arrays.fill(dp,-1);
        for(int i=0; i<size; i++){
            a[readInt()]++;
        }
        
        System.out.println(f(a,0));
    }
    static int f(int a[],int pos){
        int out=0;
        if(pos>=a.length)return 0;
        if(dp[pos]!=-1) return dp[pos];
        if(pos==0){
            out=Math.max(f(a,pos+1),f(a,pos+2));
            dp[pos]=out;
            return out;
        }
        out=a[pos]*pos+Math.max(f(a,pos+2),f(a,pos+3));
        dp[pos]=out;
        return out;
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
