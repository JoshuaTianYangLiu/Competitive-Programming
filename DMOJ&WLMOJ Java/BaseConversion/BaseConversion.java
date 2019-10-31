/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package baseconversion;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class BaseConversion {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int bTwo;
        String bThree;
        String bTwoSS=readLine();
        bTwo=Integer.parseInt(conv(bTwoSS,2,10));
        bThree=readLine();
        String bTwoS=Integer.toString(bTwo);
        for(int i=0; i<bThree.length(); i++){
            for(int j=0; j<3; j++){
                String tThree=bThree.substring(0,i)+(j)+bThree.substring(i+1,bThree.length());
                if(!tThree.equals(bThree)){
                    int toBaseTwo=Integer.parseInt(conv(tThree,3,10));
                    String toBaseTwoS=Integer.toString(toBaseTwo);

                    if(conv(toBaseTwoS,10,2).length()<=bTwoSS.length()){
                        toBaseTwo=Math.abs(toBaseTwo-bTwo);
                        if(Math.sqrt(toBaseTwo)==Math.floor(Math.sqrt(toBaseTwo))){
                            System.out.println(conv(tThree,3,10));
    //                        System.exit(0);
                        }
                    }
                }
            } 
       }
    }
    static String conv(String val,int s,int e){
        return Integer.toString(Integer.parseInt(val, s),e); 
        
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
