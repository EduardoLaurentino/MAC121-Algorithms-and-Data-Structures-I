/******************************************************************************
 *  Compilation:  javac Evaluate.java
 *  Execution:    java Evaluate
 *  Dependencies: Stack.java
 *
 *  Evaluates (fully parenthesized) arithmetic expressions using
 *  Dijkstra's two-stack algorithm.
 *
 *  % java Evaluate
 *  ( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )
 *  101.0
 *
 *  % java Evaulate
 *  ( ( 1 + sqrt ( 5 ) ) / 2.0 )
 *  1.618033988749895
 *
 *
 *
 *  Remarkably, Dijkstra's algorithm computes the same
 *  answer if we put each operator *after* its two operands
 *  instead of *between* them.
 *
 *  % java Evaluate
 *  ( 1 ( ( 2 3 + ) ( 4 5 * ) * ) + )
 *  101.0
 *
 *  Moreover, in such expressions, all parentheses are redundant!
 *  Removing them yields an expression known as a postfix expression.
 *  1 2 3 + 4 5 * * +
 *
 *
 ******************************************************************************/


public class Evaluate {
    public static void main(String[] args) {
        Stack<String> stack  = new Stack<String>();

        while (!StdIn.isEmpty()) {
            String token = StdIn.readString();
            if      (!s.equals(")")) ops.push(s);
            else {
                String op = ops.pop();
                String v = "";
                if (vals.size() > 0) v = vals.pop() + op;
                vals.push(v);
            }
            //else vals.push(Double.parseDouble(s));
        }
        StdOut.println(vals.pop());
    }
}
