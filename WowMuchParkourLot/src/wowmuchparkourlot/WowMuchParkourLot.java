/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package wowmuchparkourlot;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class WowMuchParkourLot {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size =readInt();
        int x =0;
        int y =0;
        
        for(int i=0; i<size; i++){
            String dir = next();
            int b = readInt();
            switch(dir){
                case "North": 
                    y+=b;
                    break;
                case "South":
                    y-=b;
                    break;
                case "West":
                    x-=b;
                    break;
                case "East":
                    x+=b;
                    break;
            }
        }
        System.out.println(x+" "+y);
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
