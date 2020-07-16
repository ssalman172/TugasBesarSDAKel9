/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tubesinfix;

/**
 *
 * @author LEGION
 */
public class Node {
    public char data;
    public Node leftChild;
    public Node rightChild;
 
    public Node(char x)
    {
        data = x;
    }
 
    public void displayNode()
    {
        System.out.print(data);
    }   
}
