/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package friendshipisanumber;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class FriendshipIsANumber {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        int a[] = new int[size];
        for(int i=0; i<size; i++){
            int times = readInt();
            a[i]=readInt();
            for(int j=0; j<times-1; j++){
                a[i]*=readInt();
            }
        }
        for(int i=0; i<3; i++){
            int max =0;
            for(int j=1; j<size; j++){
                if(a[max]<a[j]){
                    max = j;
                }
            }
            System.out.println(max+1);
            a[max]=-2147483648;
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
