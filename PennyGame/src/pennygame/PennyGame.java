/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pennygame;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class PennyGame {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        for(int c = 0; c<5; c++){
            int size = readInt();
            int a[] = new int[size];
            int avrg =0;
            for(int i=0;i<size; i++){
                a[i]=readInt();
                avrg += a[i];
            }
            avrg/=size;
            Arrays.sort(a);
            int total =0;
            for(int i=median(a, avrg); i<size; i++){
                total+=a[i]-avrg;
            }
            System.out.println(total);
        }
    }
    static int median(int a[],int avrg){
        for(int i=0; i<a.length; i++){
            if(a[i]>avrg){
                return i;
            }
        }
        return 0;
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
