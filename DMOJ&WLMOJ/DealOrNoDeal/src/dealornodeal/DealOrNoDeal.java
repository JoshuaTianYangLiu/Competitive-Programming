/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package dealornodeal;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class DealOrNoDeal {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int c[] = {100,500,1000,5000,10000,25000,50000,100000,500000,1000000};
        int total = 1691600;
        for(int i=0; i<size; i++){
            total-=c[readInt()-1];
        }
        if(total/(10-size)>readInt()){
            System.out.println("no deal");
        }else{
            System.out.println("deal");
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
