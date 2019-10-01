/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package sortingpractice;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class SortingPractice {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static abstract class a implements Comparator<Integer>{
        public int compareTo(Integer b,Integer c){
            if(b%2==0&&c%2==0)return Integer.compare(b, c);
            if(b%2==1&&c%2==1)return Integer.compare(c,b);
            if(b%2==1&&c%2==0)return 1;
            if(b%2==0&&c%2==1)return -1;
            return 0;
        }
    }
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size=readInt();
        int b[]=new int[size];
        for(int i=0; i<size; i++)b[i]=readInt();
        Arrays.sort(b,new a());
        for(int i=0; i<size; i++)System.out.print(b[i]+" ");
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
