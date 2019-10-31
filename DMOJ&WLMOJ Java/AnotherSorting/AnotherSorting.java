/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package anothersorting;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class AnotherSorting {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        ArrayList<Integer> a[] = new ArrayList[10];
        for(int i=0; i<10; i++)a[i]=new ArrayList<Integer>();
        for(int i=0; i<size;i++){
            int b=readInt();
            a[b%10].add(b);
        }
        for(int i=0; i<10; i++)Collections.sort(a[i]);
        String c="";
        for(int i=0; i<10; i++){
            for(int j=a[i].size()-1; j>=0; j--)c+=a[i].get(j)+" ";
        }
        System.out.println(c.trim());
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
