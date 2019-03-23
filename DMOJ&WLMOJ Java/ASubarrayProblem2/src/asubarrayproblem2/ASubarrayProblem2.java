/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package asubarrayproblem2;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ASubarrayProblem2 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int n = readInt();
        int k = readInt();
        int in[] = new int[n];
        int s=0;
        int e=k;
        int oneSum[] = new int[n-k+1];
        for(int i=0; i<n; i++){
            in[i]=readInt();
        }
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=in[i];
        }
        oneSum[0]=sum;
        for(int i=1; i<n-k+1; i++){
            sum+=in[e++];
            sum-=in[s++];
            oneSum[i]=sum;
        }
        s=0;
        e=k-1;
        sum=0;
        int max=0;
        for(int i=0; i<k-1; i++){
            sum+=in[i];
        }
        max=sum;
        for(int i=1; i<n-k+2; i++){
            sum+=in[e++];
            sum-=in[s++];
            if(max<sum){
                max=sum;
            }
        }
        int out=0;
        for(int i=0; i<n-k+1; i++){
            if(oneSum[i]>max)out++;
        }
        System.out.println(out);
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
