/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package crossspiral;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class CrossSpiral {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        int rectX = readInt();
        int rectY = readInt();
        boolean cross[][] = new boolean[rectY][rectX];
        int cornerX = readInt();
        int corwnerY = readInt();
        for(int i=cornerX; i<rectX-cornerX; i++){
            for(int j=0; j<rectY; j++){
                cross[j][i]=true;
            }
        }
        for(int i=cornerY; i<rectY-cornerY; i++){
            for(int j=0; j<rectX; j++){
                cross[i][j]=true;
            }
        }
        int x = cornerX;
        int y = 0;
        int size=readInt();
        int state = 0;
        for(int i=0; i<size; i++){
            //TL
            boolean thrAllStates=true;
            if(state==0){
                try{
                    if(cross[y][x+1]){
                        cross[y][x]=false;
                        x++;
                        thrAllStates=false;
                    }else if(cross[y+1][x]){
                        cross[y][x]=false;
                        y++;
                        thrAllStates=false;
                    }else{
                        state=1;
                    }
                }catch(Exception e){
                    state=1;
                }
                //BR
            }else{
                thrAllStates=false;
            }
            if(state==1){
                try{
                    if(cross[y+1][x]){
                        cross[y][x]=false;
                        y++;
                        thrAllStates=false;
                    }else if(cross[y][x-1]){
                        cross[y][x]=false;
                        x--;
                        thrAllStates=false;
                    }else{
                        state=2;
                    }
                }catch(Exception e){
                    state=2;
                }
            }else{
                thrAllStates=false;
            }
            if(state==2){
                try{
                    if(cross[y][x-1]){
                        cross[y][x]=false;
                        x--;
                        thrAllStates=false;
                    }else if(cross[y-1][x]){
                        cross[y][x]=false;
                        y--;
                        thrAllStates=false;
                    }else{
                        state=3;
                    }
                }catch(Exception e){
                    state=3;
                }
            }else{
                thrAllStates=false;
            }
            if(state==3){
                try{
                    if(cross[y-1][x]){
                        cross[y][x]=false;
                        y--;
                        thrAllStates=false;
                    }else if(cross[y][x+1]){
                        cross[y][x]=false;
                        x++;
                        thrAllStates=false;
                    }else{
                        state=0;
                        i--;
                    }
                }catch(Exception e){
                    i--;
                    state=0;
                }
            }else{
                thrAllStates=false;
            }
            if(thrAllStates) break;
        }
        System.out.println(x+1);
        System.out.println(y+1);
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
