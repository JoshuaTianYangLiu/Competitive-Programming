/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package degreesofseperation;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class DegreesOfSeperation {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static ArrayList<Integer> a[] = new ArrayList[50];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        char in = readCharacter();
        for(int i=0; i<50; i++)a[i]=new ArrayList<Integer>();
        con(1,6);
        con(6,2);
        con(6,5);
        con(6,4);
        con(5,4);
        con(5,3);
        con(3,4);
        con(6,3);
        con(6,7);
        con(7,8);
        con(8,9);
        con(9,10);
        con(12,9);
        con(10,11);
        con(12,11);
        con(13,12);
        con(13,14);
        con(13,15);
        con(3,15);
        con(18,16);
        con(18,17);
        con(17,16);
        while(in!='q'){
            if(in=='i'){
                int x=readInt();
                int y=readInt();
                if(!a[x].contains(y))a[x].add(y);
                if(!a[y].contains(x))a[y].add(x);
            }else if(in=='d'){
                int x=readInt();
                int y=readInt();
                if(a[x].contains(y))a[x].remove(new Integer(y));
                if(a[y].contains(x))a[y].remove(new Integer(x));
            }else if(in=='n')System.out.println(a[readInt()].size());
            else if(in=='f'){
                int x=readInt();
                Queue<Integer> b = new LinkedList<Integer>();
                for(int i=0; i<a[x].size(); i++){
                    b.add(a[x].get(i));
                }
                boolean added[] = new boolean[50];
                int count=0;
                while(!b.isEmpty()){
                    int y=b.remove();
                    for(int i=0; i<a[y].size(); i++){
                        if(a[y].get(i)!=x&&!a[x].contains(a[y].get(i))){
                            if(!added[a[y].get(i)]){
                                count++;
                                added[a[y].get(i)]=true;
                            }
                        }
                    }
                }
                System.out.println(count);
            }else if(in=='s'){
                int x=readInt();
                int y=readInt();
                int c[]=new int[50];
                boolean checked[]=new boolean[50];
                Arrays.fill(c,-1);
                Queue<Integer> b=new LinkedList<Integer>();
                checked[x]=true;
                for(int i=0; i<a[x].size(); i++){
                    b.add(a[x].get(i));
                    c[a[x].get(i)]=1;
                }
                while(!b.isEmpty()){
                    int z=b.remove();
                    checked[z]=true;
                    for(int i=0; i<a[z].size(); i++){
                        int d=a[z].get(i);
                        if((c[d]==-1||c[d]>c[z]+1)) c[d]=c[z]+1;
                        if(!checked[d]) b.add(d);
                    }
                }
                if(c[y]==-1)System.out.println("Not connected");
                else System.out.println(c[y]);
            }
            in=readCharacter();
        }
    }
    static void con(int x,int y){
        if(!a[x].contains(y))a[x].add(y);
        if(!a[y].contains(x))a[y].add(x);
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
