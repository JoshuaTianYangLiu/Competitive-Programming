/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package sandwich;

import java.util.*;
import java.io.*;

/**
 *
 * @author liuti
 */


public class Sandwich {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        String a = readLine();
        Stack<Integer> top = new Stack<Integer>();
        Queue<Integer> bot = new LinkedList<Integer>();
        Stack<Integer> bottom = new Stack<Integer>();
        int num=1;
        for(int i=0; i<size; i++){
            if(a.charAt(i)=='1'){
                top.push(num);
            }else{
                bot.add(num);
            }
            num++;
        }
        for(int i=top.size(); i>0; i--){
            System.out.println(top.pop());
        }
        for(int i=bot.size(); i>0; i--){
            System.out.println(bot.remove());
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
