/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package troublingtriangles;

import java.util.*;
import java.io.*;
import java.text.DecimalFormat;

/**
 *
 * @author liuti
 */


public class TroublingTriangles {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        for(int i =0; i<size; i++){
            double xA = readDouble();
            double yA = readDouble();
            double xB = readDouble();
            double yB = readDouble();
            double xC = readDouble();
            double yC = readDouble();
            DecimalFormat d = new DecimalFormat("0.00");
            System.out.print(d.format(Math.abs((xA*(yB-yC)+xB*(yC-yA)+xC*(yA-yB))/2)));
            System.out.println(d.format(Math.sqrt(Math.pow(xA-xB, 2)+Math.pow(yA-yB, 2))+Math.sqrt(Math.pow(xA-xC, 2)+Math.pow(yA-yC, 2))+Math.sqrt(Math.pow(xC-xB, 2)+Math.pow(yC-yB, 2))) +" ");
            
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
