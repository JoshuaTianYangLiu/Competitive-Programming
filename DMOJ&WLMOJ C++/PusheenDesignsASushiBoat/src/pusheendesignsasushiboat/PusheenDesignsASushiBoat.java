/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pusheendesignsasushiboat;

import java.util.*;
import java.io.*;
import java.math.BigInteger;

/**
 *
 * @author Joshua
 */


public class PusheenDesignsASushiBoat {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int a[] = new int[size+1];
        int k=readInt();
        int n=0;
        for(int i=0; i<size; i++){
            int temp = readInt();
            if(a[temp]==0)n++;
            a[temp]++;
        }
        int b[] = new int[n];
        n=0;
        for(int i=0; i<=size; i++){
            if(a[i]!=0){
                b[n]=a[i];
                n++;
            }
        }
        int out=0;
        BigInteger product;
        for (int i=0; i<=n-k; i++) { 
            product=new BigInteger("1");
            for (int j = i; j < k + i; j++) product=product.multiply(BigInteger.valueOf(b[j]));
            product=product.mod(BigInteger.valueOf(998244353));
            out+=product.intValue(); 
            out%=998244353;
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
