/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package contest3pet2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.logging.Level;
import java.util.logging.Logger;
/**
 *
 * @author Joshua
 */
public class Contest3Pet2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
        String coded="";

        try {
            coded = input.readLine();
        } catch (Exception e) {}
        
        int result[] = getRowCol(coded.length());
        int row = result[0];
        int col = result[1];
        String forOut= "";
        for (int i =0; i<row; i++)
        {
            for (int j =0; j<col; j++)
            {
                forOut +=  Character.toString(coded.charAt(j*row + i));
            }
        }
        System.out.println(forOut);
    }
    
    static int[] getRowCol(int len)
    {
        int RowCol[]= new int[2];
        int mid = (int)(Math.sqrt(len));
        for (int i=mid; i>1; i--)
        {
            if (len%i == 0)
            {
                RowCol[0]=i;
                RowCol[1]=len/i;
                return RowCol;
            }
        }
        RowCol[0]=1;
        RowCol[1]=len;
        return RowCol;
    
    }
    
}
