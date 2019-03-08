/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package countinglines;

import java.util.*;
import java.io.*;

/**
 *
 * @author Joshua
 */


public class CountingLines {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int count=0;
        while(input.hasNextLine()){
            input.nextLine();
            count++;
        }
    }
}
