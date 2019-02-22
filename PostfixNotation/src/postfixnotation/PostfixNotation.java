/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package postfixnotation;

import java.util.*;
import java.io.*;
import static java.math.RoundingMode.HALF_UP;
import java.text.DecimalFormat;

/**
 *
 * @author liuti
 */


public class PostfixNotation {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception{
        // TODO code application logic here
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner in = new Scanner(br.readLine());
        Stack<Double> c = new Stack<Double>();
        while(in.hasNext()){
            if(in.hasNextDouble()){
                c.add(in.nextDouble());
            }else{
                char op = in.next().charAt(0);
                double y = c.pop();
                double x = c.pop();
                if(op=='*')c.add(x*y);
                else if(op=='/')c.add(x/y);
                else if(op=='+')c.add(x+y);
                else if(op=='-')c.add(x-y);
                else if(op=='%')c.add(x%y);
                else if(op=='^')c.add(Math.pow(x, y));
            }
        }
        DecimalFormat d = new DecimalFormat("0.0");
        d.setRoundingMode(HALF_UP);
        System.out.println(d.format(c.pop()));
    }
}
