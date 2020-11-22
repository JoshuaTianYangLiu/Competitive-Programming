/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package fromprefixtopostfix;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class FromPrefixToPostFix {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String in=readLine();
        while(!(in.charAt(0)=='0'&&in.length()==1)){
            Stack<Character> sign = new Stack<Character>();
            String out="";
            st=new StringTokenizer(in);
            int size=st.countTokens();
            for(int i=0; i<size; i++){
                char temp = readCharacter();
                if(temp>47&&temp<58){
                    out+=temp+" ";
                }else{
                    sign.add(temp);
                }
            }
            size=sign.size();
            for(int i=0; i<size; i++)out+=sign.pop()+" ";
            System.out.println(out.trim());
            in=readLine();
        }
    }


    static String next () throws IOException {
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
