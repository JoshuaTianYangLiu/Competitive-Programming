/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package joshua_liu_test1;

import java.io.*;
import java.math.BigDecimal;
import java.util.*;

/**
 *
 * @author Joshua
 */
public class QuestionsA {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(int j=0; j<10; j++){
            BigDecimal t;
            BigDecimal a;
            BigDecimal p;
            BigDecimal q;
            double wT = readDouble()/100;
            double wA = readDouble()/100;
            double wP = readDouble()/100;
            double wQ = readDouble()/100;
            int size = readInt();
            int passed =0;
            for(int i=0; i<size; i++){
                t = new BigDecimal(next());
                a = new BigDecimal(next());
                p = new BigDecimal(next());
                q = new BigDecimal(next());

                if(wT*t+wA*a+wP*p+wQ*q>=50.0){
                    passed++;
                }
            }
            System.out.println(passed);
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
