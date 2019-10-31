/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package crayolalightsaber;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class CrayolaLightsaber {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int colour[] = new int[6];
        for(int i=0; i<size; i++){
            String a = next();
            if(a.equals("red")){
                colour[0]++;
            }else if(a.equals("orange")){
                colour[1]++;
            }else if(a.equals("yellow")){
                colour[2]++;
            }else if(a.equals("green")){
                colour[3]++;
            }else if(a.equals("blue")){
                colour[4]++;
            }else if(a.equals("black")){
                colour[5]++;
            }
        }
        int total=1;
        int c = 5;
        for(int i=0; i<6; i++){
            if(colour[i]>colour[c]){
                c=i;
            }
        }
        colour[c]--;
        out:
        for(;;){
            for(int i=0; i<6; i++){
                if(i!=c&&colour[i]>0){
                    colour[i]--;
                    total++;
                    c=i;
                    break;
                }
                if(i==5){
                    break out;
                }
            }
        }
        System.out.println(total);
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
