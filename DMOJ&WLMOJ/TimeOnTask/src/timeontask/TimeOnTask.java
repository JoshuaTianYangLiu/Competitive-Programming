/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package timeontask;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class TimeOnTask {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int t = readInt();
        int size = readInt();
        int a[] = new int[size];
        for(int i=0; i<size; i++){
            a[i]=readInt();
        }
        Arrays.sort(a);
        int total = 0;
        int j =0;
        for(int i =0; i<size+1; i++){
            if(total+a[i]>t){
                break;
            }
            total += a[i];
            j++;
        }
        System.out.println(j);
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
