/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package steinsnumber;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */
public class SteinsNumber {

    /**
     * @param args the command line arguments
     */
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        int q = readInt();
        
        for(int i=0; i<q;i++){
            long total = 0;
            long a = readLong();
            if(a==0) a=1;
            long b = readLong();
            String s ="";
            String e ="";
            s=roundNConvert(a);
            e=eRoundNConvert(b);
            total=Long.parseLong(e,2)-Long.parseLong(s,2)+1;
            if(Long.parseLong(e,2)<Long.parseLong(s,2)) System.out.println(0);
            else{
                System.out.println(total);                
            }
        }
    }
    static String eRoundNConvert(long a){
        String out = "";
        String c = Long.toString(a,3);
        int pos =0;
        int l = c.length();
        for(int i=0; i<l; i++){
            if(c.charAt(i)=='2'){
                break;
            }
            pos++;
            out+=c.charAt(i);
        }
        for(int i=pos; i<l; i++){
            out+='1';
        }
        return out;
    }
    static String roundNConvert(long b){
        int pos =0;
        String a =Long.toString(b,3);
        boolean hasNum = false;
        for(int i=0; i<a.length(); i++){
            if(a.charAt(i)=='2'){
                hasNum=true;
                pos=i;
                break;
            }
        }
        String out = "";
        if(hasNum){
            StringBuilder sb = new StringBuilder(a.substring(0,pos));
            String in = sb.reverse().toString();
            sb = new StringBuilder();
            boolean carry = true;
            boolean temp = true;
            for(int i=0; i<pos; i++){
                if(carry){
                    if(in.charAt(i)=='1'){
                        sb.append('0');
                        
                    }else{
                        sb.append('1');
                        carry=false;
                        temp=false;
                    }
                }else{
                    sb.append(in.substring(i,pos));
                    break;
                }
            }
            if(temp)sb.append('1');
            out = sb.reverse().toString();
            out+='0';
            for(int i=pos+1; i<a.length(); i++){
                out+='0';
            }
        }else{
            out=a;
        }
        return out;
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
