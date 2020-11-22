/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package rainfallstorageii;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class RainfallStorageII {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        
        long total=0;
        int max=0;
        long maxIndex=0;
        int diff[] = new int[size];
        for(int i=0; i<size; i++){
            diff[i]=readInt();
            if(diff[i]>max){
                max=diff[i];
                maxIndex=i;
            }
        }
        long n[] = new long[max+1];
        long s[] = new long[max];
        long e[] = new long[max];
        int curMax=0;
        for(int i=0; i<=maxIndex; i++){
            if(diff[i]>curMax){
                for(int j=curMax; j<diff[i]; j++)s[j]=i+1;
                curMax=diff[i];
            }
            if(diff[i]!=0){
                n[0]++;
                if(diff[i]<=max)n[diff[i]]--;
            }
        }
        curMax=0;
        for(int i=size-1; i>=maxIndex; i--){
            if(diff[i]>curMax){
                for(int j=curMax; j<diff[i]; j++)e[j]=i+1;
                curMax=diff[i];
            }
            if(i!=maxIndex){
                if(diff[i]!=0){
                    n[0]++;
                    if(diff[i]<=max)n[diff[i]]--;
                }
            }
        }
        long carry=0;
        for(int i=0; i<max; i++){
            if(i==0)carry=n[i];
            else{
                carry+=n[i];
            }
            if(e[i]!=0){
                total+=e[i]-s[i]+1-carry;
            }
        }
        System.out.println(total);
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
