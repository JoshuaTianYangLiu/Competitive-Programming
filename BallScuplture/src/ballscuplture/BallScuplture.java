/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ballscuplture;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author Joshua
 */
public class BallScuplture {

    /**
     * @param args the command line arguments
     */
    public static boolean switchpos[];
    
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input = null;
        int a[] = new int[2];
        String temp = "";
        try{
        input = new BufferedReader(new InputStreamReader(System.in));
        temp = input.readLine();
        }catch(IOException e){}
        String[] tempArr =temp.split(" ");
        a[0]=Integer.parseInt(tempArr[0]);
        a[1]=Integer.parseInt(tempArr[1]);
        int switch0[]=new int[a[0]];
        int switch1[]=new int[a[0]];
        switchpos = new boolean[a[0]];
        for(int i = 0; i<a[0];i++){
            try {
                temp = input.readLine();
                tempArr = temp.split(" ");
            } catch (Exception e) {}
            switch0[i] = Integer.parseInt(tempArr[0]);
            switch1[i] = Integer.parseInt(tempArr[1]);
        }
        for(int i = 0; i<a[1];i++){
            runSim(switch0, switch1, switchpos);
        }
        String answer ="";
        for(int i = 0; i<switch0.length; i++){
            if(switchpos[i]){
                answer+="1";
            }else{
                answer+="0";
            }
        }
        System.out.println(answer);
    }
    public static void runSim(int switch0[], int switch1[], boolean switchPos[]){
        int ball = 0;
        while (ball!=switch0.length) {            
            switchPos[ball]= !switchPos[ball];
            if(!switchPos[ball]){
                ball = switch1[ball]-1;
            }else{
                ball = switch0[ball]-1;
            }
        }
    
    }
}
