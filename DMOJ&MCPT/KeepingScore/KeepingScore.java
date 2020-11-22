/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package keepingscore;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class KeepingScore {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        String hold = readLine();
        int count =1;
        int cPoints =0;
        String cLine = "";
        int total =0;
        int numOfChar =0;
        System.out.println("Cards Dealt              Points");
        while(hold.charAt(count)!='D'){
            if(hold.charAt(count)=='A'){
                cLine += hold.charAt(count)+" ";
                cPoints+=4;
            }else if(hold.charAt(count)=='K'){
                cLine += hold.charAt(count)+" ";
                cPoints+=3;
            }else if(hold.charAt(count)=='Q'){
                cLine += hold.charAt(count)+" ";
                cPoints+=2;
            }else if(hold.charAt(count)=='J'){
                cLine += hold.charAt(count)+" ";
                cPoints+=1;
            }else{
                cLine+=hold.charAt(count)+" ";
            }
            count++;
            numOfChar++;
        }
        if(numOfChar<3) cPoints+=3-numOfChar;
        System.out.println("Clubs "+cLine+cPoints);
        total+=cPoints;
        cLine="";
        cPoints=0;
        count++;
        numOfChar=0;
        while(hold.charAt(count)!='H'){
            if(hold.charAt(count)=='A'){
                cLine += hold.charAt(count)+" ";
                cPoints+=4;
            }else if(hold.charAt(count)=='K'){
                cLine += hold.charAt(count)+" ";
                cPoints+=3;
            }else if(hold.charAt(count)=='Q'){
                cLine += hold.charAt(count)+" ";
                cPoints+=2;
            }else if(hold.charAt(count)=='J'){
                cLine += hold.charAt(count)+" ";
                cPoints+=1;
            }else{
                cLine+=hold.charAt(count)+" ";
            }
            count++;
            numOfChar++;
        }
        if(numOfChar<3) cPoints+=(3-numOfChar);
        System.out.println("Diamonds "+cLine+cPoints);
        total+=cPoints;
        cLine="";
        cPoints=0;
        count++;
        numOfChar=0;
        while(hold.charAt(count)!='S'){
            if(hold.charAt(count)=='A'){
                cLine += hold.charAt(count)+" ";
                cPoints+=4;
            }else if(hold.charAt(count)=='K'){
                cLine += hold.charAt(count)+" ";
                cPoints+=3;
            }else if(hold.charAt(count)=='Q'){
                cLine += hold.charAt(count)+" ";
                cPoints+=2;
            }else if(hold.charAt(count)=='J'){
                cLine += hold.charAt(count)+" ";
                cPoints+=1;
            }else{
                cLine+=hold.charAt(count)+" ";
            }
            count++;
            numOfChar++;
        }
        if(numOfChar<3) cPoints+=(3-numOfChar);
        System.out.println("Hearts "+cLine+cPoints);
        total+=cPoints;
        cLine="";
        cPoints=0;
        count++;
        numOfChar=0;
        for(int i=count; i<hold.length(); i++){
            if(hold.charAt(count)=='A'){
                cLine += hold.charAt(count)+" ";
                cPoints+=4;
            }else if(hold.charAt(count)=='K'){
                cLine += hold.charAt(count)+" ";
                cPoints+=3;
            }else if(hold.charAt(count)=='Q'){
                cLine += hold.charAt(count)+" ";
                cPoints+=2;
            }else if(hold.charAt(count)=='J'){
                cLine += hold.charAt(count)+" ";
                cPoints+=1;
            }else{
                cLine+=hold.charAt(count)+" ";
            }
            count++;
            numOfChar++;
        }
        if(numOfChar<3) cPoints+=(3-numOfChar);
        System.out.println("Spades "+cLine+cPoints);
        total+=cPoints;
        System.out.println("Total "+total);
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
