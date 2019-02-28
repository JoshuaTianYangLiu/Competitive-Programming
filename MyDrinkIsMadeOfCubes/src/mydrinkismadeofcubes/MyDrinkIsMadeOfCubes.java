/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package mydrinkismadeofcubes;

import java.util.*;
import java.io.*;


/**
 *
 * @author Joshua
 */
public class MyDrinkIsMadeOfCubes {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        for(int i=0; i<5; i++){
            int vol = readInt();
            int tempVol = vol;
            int coord[] = new int[3];
            for(int k=0; k<2; k++){
                for(int j=(int)Math.round(Math.cbrt(vol)); j<vol+1; j++){
                    if(tempVol%j==0){
                        coord[k]=j;
                        tempVol/=j;
                        break;
                    }
                }
            }
            coord[2]=vol/(coord[0]*coord[1]);
            System.out.println(2*(coord[0]*coord[1]+coord[0]*coord[2]+coord[2]*coord[1]));
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
