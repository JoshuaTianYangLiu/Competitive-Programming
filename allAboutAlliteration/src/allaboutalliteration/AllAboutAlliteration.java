/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package allaboutalliteration;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class AllAboutAlliteration {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        char findLet = readCharacter();
        if(findLet>96){
            findLet=(char)(findLet-32);
        }
        String outF ="";
        String out = "";
        int numW = 0;
        int numWF = 0;
        st=new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            String word = st.nextToken();
            if(word.charAt(0)==findLet||word.charAt(0)==(char)(findLet+32)){
                out+=word+" ";
                numW ++;
                if(numW>numWF){
                    outF=out;
                    numWF=numW;
                }
            }else{
                out="";
                numW=0;
            }
        }
        System.out.println(outF.trim());
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
