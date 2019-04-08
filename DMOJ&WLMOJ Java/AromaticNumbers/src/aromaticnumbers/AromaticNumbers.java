/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package aromaticnumbers;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class AromaticNumbers {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        String a = readLine();
        int total=0;
        for(int i=0; i<(a.length()-2)/2; i++){
            int roman1 = 0;
            int roman2 = 0;
            if(a.charAt(2*i+1)=='I'){
                roman1=1;
            }else if(a.charAt(2*i+1)=='V'){
                roman1=5;
            }else if(a.charAt(2*i+1)=='X'){
                roman1=10;
            }else if(a.charAt(2*i+1)=='L'){
                roman1=50;
            }else if(a.charAt(2*i+1)=='C'){
                roman1=100;
            }else if(a.charAt(2*i+1)=='D'){
                roman1=500;
            }else if(a.charAt(2*i+1)=='M'){
                roman1=1000;
            }
            if(a.charAt(2*i+3)=='I'){
                roman2=1;
            }else if(a.charAt(2*i+3)=='V'){
                roman2=5;
            }else if(a.charAt(2*i+3)=='X'){
                roman2=10;
            }else if(a.charAt(2*i+3)=='L'){
                roman2=50;
            }else if(a.charAt(2*i+3)=='C'){
                roman2=100;
            }else if(a.charAt(2*i+3)=='D'){
                roman2=500;
            }else if(a.charAt(2*i+3)=='M'){
                roman2=1000;
            }
            if(roman1<roman2){
                total-=(a.charAt(2*i)-48)*roman1;
            }else{
                total+=(a.charAt(2*i)-48)*roman1;
            }
        }
        int i = (a.length()-2)/2;
        if(a.charAt(2*i-1)=='I'){
            total+=(a.charAt(2*i)-48)*1;
        }else if(a.charAt(2*i+1)=='V'){
            total+=(a.charAt(2*i)-48)*5;
        }else if(a.charAt(2*i+1)=='X'){
            total+=(a.charAt(2*i)-48)*10;
        }else if(a.charAt(2*i+1)=='L'){
            total+=(a.charAt(2*i)-48)*50;
        }else if(a.charAt(2*i+1)=='C'){
            total+=(a.charAt(2*i)-48)*100;
        }else if(a.charAt(2*i+1)=='D'){
            total+=(a.charAt(2*i)-48)*500;
        }else if(a.charAt(2*i+1)=='M'){
            total+=(a.charAt(2*i)-48)*1000;
        }
        System.out.println(total);
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
