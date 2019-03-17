/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tank;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Tank {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int size = readInt();
        int pSize = readInt();
        int mSize = readInt();
        int t[][] = new int[size][2];
        List<Integer> p = new ArrayList<Integer>();
        List<Integer> m = new ArrayList<Integer>();
        
        for(int i=0; i<size; i++){
            t[i][0]=readInt();
            t[i][1]=readInt();
        }
        for(int i=0; i<pSize; i++){
            p.add(readInt());
        }
        for(int i=0; i<mSize; i++){
            m.add(readInt());
        }
        Collections.sort(p,Collections.reverseOrder());
        Collections.sort(m,Collections.reverseOrder());
        int pArr[] = new int[pSize];
        pArr[0]=p.get(0);
        for(int i=1; i<pSize; i++){
            pArr[i]=pArr[i-1]+p.get(i);
        }
        int mArr[] = new int[mSize];
        mArr[0]=m.get(0);
        for(int i=1; i<mSize; i++){
            mArr[i]=mArr[i-1]+m.get(i);
        }
        int pos=0;
        int tot =0;
        int finTot=pArr[pSize-1]+mArr[mSize-1];
        int finPos=0;
        for(int i=0; i<size; i++){
            int a=0;
            int b=pSize;
            int c=(a+b)/2;
            int ans =0;
            tot=0;
            while(!(p.get(pos)<=t[i][0]&&t[i][0]<=p.get(pos+1))){
                if(p.get(pos)==p.get(c)){
                    ans=p.get(pos);
                    break;
                }else if(p.get(pos)<p.get(c)){
                    b=c;
                    c=Math.round((a+b)/2);
                }else{
                    a=c;
                    c=(int) Math.round((a+b)/2.0);
                }
            }
            tot+=(ans-pos*t[i][0]);
            a=0;
            b=mSize;
            c=(a+b)/2;
            while(!(m.get(pos)<=t[i][1]&&t[i][1]<=m.get(pos+1))){
                if(m.get(pos)==m.get(c)){
                    ans=m.get(pos);
                    break;
                }else if(m.get(pos)<m.get(c)){
                    b=c;
                    c=(int) Math.round((a+b)/2.0);
                }else{
                    a=c;
                    c=(int) Math.round((a+b)/2.0);
                }
            }
            tot+=(ans-pos*t[i][1]);
            if(tot<finTot){
                finTot=tot;
                finPos=pos;
            }
        }
        System.out.println(finPos);
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
