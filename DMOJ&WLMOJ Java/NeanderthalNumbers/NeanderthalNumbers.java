/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package neanderthalnumbers;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class NeanderthalNumbers {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static String a;
    static int dp[];
    static String l[]={"ook","ookook","oog","ooga","ug","mook","mookmook","oogam","oogum","ugug"};
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        for(int i=0; i<10; i++){
            a=readLine();
            dp=new int[a.length()];
            Arrays.fill(dp, -1);
            System.out.println(f(0));
            String t="";
//            for(int j=0; j<a.length(); j++)t+=dp[j]+" ";
//            System.out.println(t);
        }
    }
    static int f(int s){
        if(s>=a.length())return 1;
        if(dp[s]!=-1)return dp[s];
        int b=0;
        for(int i=0; i<10; i++){
            if(l[i].length()+s<=a.length()&&a.substring(s, l[i].length()+s).equals(l[i])){
                b+=f(l[i].length()+s);
            }
        }
        dp[s]=b;
        return b;
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
