
public class mainKalkulator {
	public static void main(String args[]) { 
		  
        expressionTree et = new expressionTree(); 
        String postfix = "ab+ef*g*-"; 
        char[] charArray = postfix.toCharArray(); 
        Node root = et.constructTree(charArray); 
        System.out.println("infix expression is"); 
        et.inorder(root); 
  
    } 
}
