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
public class Stack2 {
    private char[] a;
    private int    top, m;
 
    public Stack2(int max)
    {
        m = max;
        a = new char[m];
        top = -1;
    }
 
    public void push(char key)
    {
        a[++top] = key;
    }
 
    public char pop()
    {
        return (a[top--]);
    }
 
    public boolean isEmpty()
    {
        return (top == -1);
    }
}
