/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package lvmex;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class LvmEX {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int size = readInt();
        String a[] = new String[size];
        int num[] = new int[size];
        for(int i=0; i<size; i++){
            a[i]=next();
            if(st.hasMoreTokens()){
                num[i]=readInt();
            }
        }
        int pos =0;
        int reg=0;
        Stack<Integer> hold = new Stack<Integer>();
        while(a[pos].charAt(2)!='N'){
            if(a[pos].charAt(2)=='S'){
                //PUSH
                hold.push(num[pos]);
                pos++;
            }else if(a[pos].charAt(2)=='U'){
                //PLUS
                int b = hold.pop();
                hold.push(b +hold.pop());
                pos++;
            }else if(a[pos].charAt(2)=='O'){
                //STORE
                reg=hold.pop();
                pos++;
            }else if(a[pos].charAt(2)=='A'){
                //LOAD
                hold.push(reg);
                pos++;
            }else if(a[pos].charAt(2)=='M'){
                //TIMES
                int b = hold.pop();
                hold.push(b *hold.pop());
                pos++;
            }else if(a[pos].charAt(2)=='Z'){
                //IFZERO
                if(hold.pop()==0){
                    pos=num[pos];
                }else{
                    pos++;
                }
            }
        }
        System.out.println(hold.peek());
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
