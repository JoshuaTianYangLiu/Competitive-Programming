/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package studentcouncilbreakfast;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class StudentCouncilBreakfast {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int pink = readInt();
        int green = readInt();
        int red = readInt();
        int orange = readInt();
        int cost = readInt();
        int comb=0;
        int low = 0;
        for(int a =0; a<=cost/pink; a++){
            for(int b=0; b<=cost/green; b++){
                for(int c=0; c<=cost/red; c++){
                    for(int d=0; d<=cost/orange; d++){
                        if(a*pink+b*green+c*red+d*orange==cost){
                            System.out.println("# of PINK is "+a+" # of GREEN is "+b+" # of RED is "+c+" # of ORANGE is "+d);
                            comb++;
                            if(low==0||a+b+c+d<low){
                                low=a+b+c+d;
                            }
                        }
                    }
                }
            }
        }
        System.out.println("Total combinations is "+comb+".");
        System.out.println("Minimum number of tickets to print is "+low+".");
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
