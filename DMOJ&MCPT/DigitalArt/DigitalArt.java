/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package digitalart;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class DigitalArt {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String a = next();
        double col[][] = new double[2][3]; 
        for(int i =0; i<2; i++){
            for(int j=0; j<3; j++){
                col[i][j]=readDouble();
            }
        }
        if(a.equals("Multiply")){
            for(int i = 0; i<2; i++){
                System.out.print(col[0][i]*col[1][i]+" ");
            }
            System.out.println(col[0][2]*col[1][2]);
        }else if(a.equals("Screen")){
            for(int i = 0; i<2; i++){
                double b = 1-col[0][i];
                double c = 1-col[1][i];
                System.out.print(1-(b*c)+" ");
            }
            double b = 1-col[0][2];
            double c = 1-col[1][2];
            System.out.println(1-(b*c));
        }else if(a.equals("Overlay")){
            for(int i=0; i<2; i++){
                if(col[0][i]<0.5){
                    System.out.print(2*col[0][i]*col[1][i]+" ");
                }else{
                    System.out.print(1-(2*(1-col[0][i])*(1-col[1][i]))+" ");
                }
            }
            if(col[0][2]<0.5){
                    System.out.println(2*col[0][2]*col[1][2]);
                }else{
                    System.out.println(1-(2*(1-col[0][2])*(1-col[1][2])));
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
