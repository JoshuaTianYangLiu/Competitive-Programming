/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package herding;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class Herding {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    static public class Coord{
    int x;
    int y;
        Coord(int a,int b){
            x=a;
            y=b;
        }
    }
    static int rank[][];
    static Coord p[][];
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        //DOES NOT WORK
        int yIn=readInt();
        int xIn= readInt();
        p=new Coord[xIn][yIn];
        rank=new int[xIn][yIn];
        int total=xIn*yIn;
        int mX=0;
        int mY=0;
        for(int y=0; y<yIn; y++){
            for(int x=0; x<xIn; x++)p[x][y]=new Coord(x,y);
        }
        
        for(int i=yIn-1; i>=0; i--){
            String a = readLine();
            for(int j=0; j<xIn; j++){
                if(a.charAt(j)=='N'){
                    mX=0;
                    mY=1;
                }else if(a.charAt(j)=='S'){
                    mX=0;
                    mY=-1;
                }else if(a.charAt(j)=='W'){
                    mX=-1;
                    mY=0;
                }else if(a.charAt(j)=='E'){
                    mX=1;
                    mY=0;
                }
                int in1[]=findSet(j,i);
                int in2[]=findSet(j+mX,i+mY);
                if(in1[0]!=in2[0]||in1[1]!=in2[1])total--;
                if (rank[in1[0]][in1[1]]<rank[in2[0]][in2[1]]) p[in2[0]][in2[1]] =new Coord(in1[0],in1[1]);
                else p[in1[0]][in1[1]] =new Coord(in2[0],in2[1]);
                if(rank[in1[0]][in1[1]]==rank[in2[0]][in2[1]])rank[in1[0]][in1[1]]++;
            }
        }
        System.out.println(total);
    }
    static int[] findSet(int a,int b ){
        while(p[a][b].x!=a&&p[a][b].y!=b){
            a=p[a][b].x;
            b=p[a][b].y;
        }
        int temp[]={a,b};
        return temp;
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
