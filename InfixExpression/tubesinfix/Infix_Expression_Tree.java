/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tubesinfix;

import java.io.DataInputStream;
import java.io.IOException;

/**
 *
 * @author LEGION
 */
public class Infix_Expression_Tree {

    public static void main(String[] args) throws IOException {
        String ch = "y";
        DataInputStream inp = new DataInputStream(System.in);
        while (ch.equals("y"))
        {
            Tree t1 = new Tree();
            System.out.println("Enter the Expression");
            String a = inp.readLine();
            t1.insert(a);
            t1.traverse(1);
            System.out.println("");
            t1.traverse(2);
            System.out.println("");
            t1.traverse(3);
            System.out.println("");
            System.out.print("Enter y to continue ");
            ch = inp.readLine();
        }
    }
    
}
