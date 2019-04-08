/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package multipleofk;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class MultipleOfK {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int N = readInt();
        int K = readInt();
        int a[] = new int[K];
        int total=0;
        int max=-1;
        Arrays.fill(a,-1);
        for(int i=0; i<N; i++){
            total+=readInt();
            total%=K;
            if(total==0){
                max=i+1;
                continue;
            }
            if(a[total]==-1)a[total]=i;
            else{
                if (i-a[total]>max)max=i-a[total];
            }
        }
        System.out.println(max);
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
