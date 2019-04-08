/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;
import java.util.Scanner;
import java.io.*;
/**
 *
 * @author Joshua
 */


public class HelloWorld {

    /**
     * @param args the command line arguments
     */
    String num1 = "5";
    String num2 = "6";
    
    public void add()
    {
        System.out.println(num1 + "+" +  num2 + "=" +( num1 + num2));
        System.out.println(num1.concat(num2));
        String grass = "world"; 
        System.out.println(grass.charAt(1));
     
    }
    public void add(String num)
    {
        System.out.println(num1.concat(num));
    }
    
    public void CompareDate()
    {
      Scanner sc = new Scanner (System.in);
      int month = sc.nextInt();
      int day = sc.nextInt();
      if (month < 2 )
      {
          System.out.println("Before");
      }
      else if (month > 2)
      {
          System.out.println("After");
      }
      else if (day > 18)
      {
          System.out.println("After");
      }
      else if (day < 18)
      {
          System.out.println("Before");
      }
      else System.out.println("Special");
    }
    
    public boolean IsPalindrome(String currentStr)
    {
        for(int i=0; i<currentStr.length()/2; i++)
        {
            if (currentStr.charAt(i) != currentStr.charAt(currentStr.length() -i-1))
                return false;
        }
        return true;
    }
    public void Palindrome()
    {
      Scanner sc = new Scanner (System.in);
      String word = sc.nextLine();
      String currentStr;
      int length = word.length();
      int maxLen = 0;
      for (int i = 0; i<length-1; i++)  
      {
          for (int j = i; j<length; j++)  
          {
            currentStr = word.substring(i,j+1);
            if (IsPalindrome(currentStr))
            {
                  if (maxLen<currentStr.length())
                      maxLen = currentStr.length();
            }
          }   
      }
      System.out.println("maxLen = " + maxLen);
    }
    
    public void Example2 ()
    {
        int input1 ;
        Scanner sc1 = new Scanner(System.in);
        System.out.println("Please input your text here");
        try
        {
            input1 =sc1.nextInt();
            System.out.println(input1);
        }
        catch(Exception e)
        {
            System.out.println("input error!"+e.getMessage());
        }
    }    
    public void Array2()
    {
        int number1 ;

        System.out.println("Please input your number here");
        Scanner sc2 = new Scanner(System.in);
        number1 = sc2.nextInt();
        int[] arr = new int[number1];

        for (int i=0;i<number1; i++)
            arr[i]=i;

        for (int i=0;i<number1; i++)
            System.out.println(arr[i]);

    }       
    public static void main(String[] args)
    {
      HelloWorld s = new HelloWorld();
      //s.add(" aaa ");
     // s.add();
     // s.CompareDate();
     // s.Palindrome();
      s.Array2();
    }
}
