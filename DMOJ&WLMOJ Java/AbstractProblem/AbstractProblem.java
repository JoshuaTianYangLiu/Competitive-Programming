/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package abstractproblem;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class AbstractProblem {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i=0; i<size; i++){
            long a = readLong();
            int total=0;
            if(a!=Long.MAX_VALUE){
            while(a>0){
                if(a%2==0){
                    a/=2;
                }else if((a&2) !=0 &&a !=3){
                    a++;
                }else{
                    a--;
                }
                total++;
            }
            System.out.println(total);
            }else{
                System.out.println(65);
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
