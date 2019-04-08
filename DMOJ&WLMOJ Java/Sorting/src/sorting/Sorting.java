/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package sorting;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Sorting {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int k = readInt();
        List<Integer> a[] = new ArrayList[k];
        for(int i=0; i<k; i++){
            a[i]=new ArrayList<Integer>();
        }
        for(int i=0; i<size; i++){
            a[i%k].add(readInt());
        }
        for(int i=0; i<k; i++){
            Collections.sort(a[i]);
        }
        if(isOrder(a,size,k))System.out.println("YES");
        else System.out.println("NO");
    }
    static boolean isOrder(List<Integer>[] a,int size,int k){
        int count=1;
        for(int i=0; i<size; i++){
            if(i+1!=a[i%k].get(i/k))return false;
        }
        return true;
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
