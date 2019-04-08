/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package pictureperfect;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class PicturePerfect {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int in = readInt();
        int x=0;
        int y=0;
        while(in!=0){
            for(int i=(int)Math.sqrt(in)+1; i>0; i--){
                if(in%i==0){
                    x = i;
                    y = in/i;
                    break;
                }
            }
            System.out.println("Minimum perimeter is "+2*(x+y)+" with dimensions "+x+" x "+y);
            in=readInt();
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
