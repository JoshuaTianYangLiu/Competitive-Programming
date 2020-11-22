/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package rainbowrating;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class RainbowRating {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size =readInt();
        for(int i=0; i<size; i++){
            int a =readInt();
            if(a<1000){
                System.out.println("Newbie");
            }else if(a<1200){
                System.out.println("Amateur");
            }else if(a<1500){
                System.out.println("Expert");
            }else if(a<1800){
                System.out.println("Candidate Master");
            }else if(a<2200){
                System.out.println("Master");
            }else if(a<3000){
                System.out.println("Grandmaster");
            }else if(a<4000){
                System.out.println("Target");
            }else System.out.println("Rainbow Master");
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
