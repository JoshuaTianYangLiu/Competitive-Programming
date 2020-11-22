/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package soundsfishy;

import java.util.Scanner;

/**
 *
 * @author Joshua
 */
public class SoundsFishy {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        boolean up = true;
        boolean down = true;
        boolean e = true;
        for(int i = 0;i<3;i++){
            int y = in.nextInt();
            if(y<x){
                up = false;
            }
            if(y>x){
                down = false;
            }
            if(y!=x){
                e = false;
            }else{
                up=false;
                down=false;
            }
            x=y;
        }
        if(up) System.out.println("Fish Rising");
        else if(down) System.out.println("Fish Diving");
        else if(e) System.out.println("Fish At Constant Depth");
        else System.out.println("No Fish");
    }
}
