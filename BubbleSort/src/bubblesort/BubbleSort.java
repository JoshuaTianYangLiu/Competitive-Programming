/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package bubblesort;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class BubbleSort {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size =readInt();
        int a[] = new int[size];
        for(int i=0; i<size; i++){
            a[i]=readInt();
        }
        String b = "";
        for(int i=0; i<size; i++){
            b+=a[i]+" ";
        }
        System.out.println(b.trim());
        int temp =0;
        for(int i=0; i<size-1; i++){
            for(int j=0; j<size-1; j++){
                if(a[j]>a[j+1]){
                    temp = a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;
                    b="";
                    for(int k=0; k<size; k++){
                        b+=a[k]+" ";
                    }
                    System.out.println(b.trim());
                }
            }
        }
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
