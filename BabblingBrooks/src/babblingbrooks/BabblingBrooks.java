/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package babblingbrooks;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class BabblingBrooks {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int streams= readInt();
        List<Double> a = new ArrayList<Double>();
        for(int i=0; i<streams; i++){
            a.add(readDouble());
        }
        int input = readInt();
        while(input!=77){
            if(input ==99){
                int pos = readInt();
                double temp = a.remove(pos-1);
                double perc = readDouble()/100.0;
                a.add(pos-1,temp*perc);
                a.add(pos,temp*(1-perc));
            }else if(input==88){
                int pos = readInt();
                double tempA = a.remove(pos-1);
                double tempB = a.remove(pos-1);
                a.add(pos-1,tempA+tempB);
            }
            input = readInt();
        }
        String out = "";
        for(int i=0; i<a.size(); i++){
            out+=Math.round(a.get(i))+" ";
        }
        System.out.println(out.trim());
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
