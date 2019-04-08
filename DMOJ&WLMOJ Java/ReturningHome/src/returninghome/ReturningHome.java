/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package returninghome;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class ReturningHome {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        Stack<String> a = new Stack<String>();
        String b = "";
        while(!b.equals("SCHOOL")){
            b = readLine();
            a.push(b);
        }
        a.pop();
        int x = (a.size()+1)/2;
        for(int i=0; i<x; i++){
            
            char dir = a.pop().charAt(0);
            String place = "";
            String out = "";
            if(a.size()>0){
                place = a.pop();
            }
            switch(dir){
                case 'L':
                    out="RIGHT";
                    break;
                case 'R':
                    out="LEFT";
                    break;
            }
            if(place.equals("")){
                System.out.println("Turn "+out+" into your HOME.");
            }else{
                System.out.println("Turn "+out+" onto "+place+" street.");
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
