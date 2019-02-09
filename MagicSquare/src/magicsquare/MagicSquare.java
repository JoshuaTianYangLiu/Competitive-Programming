/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package magicsquare;

import java.io.BufferedReader;
import java.io.InputStreamReader;

/**
 *
 * @author Joshua
 */
public class MagicSquare {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        // TODO code application logic here
        BufferedReader input;
        String temp = "";
        input = new BufferedReader(new InputStreamReader(System.in));
        int a[][] = new int[4][4];
        for(int i = 0; i<4; i++){
            temp = input.readLine();
            String[] tempArr;
            tempArr = temp.split(" ");
            for(int j = 0;j<4;j++){
                a[i][j]=Integer.parseInt(tempArr[j]);
            }
        }
        if (isMagic(a)) System.out.println("magic");
        else System.out.println("not magic");
    }
    static boolean isMagic(int a[][]){
        int total= 0;
        int temp =0;
        for(int i = 0; i<4;i++){
            total+=a[0][i];
        }
        for(int i = 0; i<4;i++){
            for(int j=0; j<4;j++){
                temp +=a[i][j];
            }
            if(temp != total) return false;
            temp =0;
        }
        for(int i = 0; i<4;i++){
            for(int j=0; j<4;j++){
                temp +=a[j][i];
            }
            if(temp != total) return false;
            temp =0;
        }
        return true;
    }
}
