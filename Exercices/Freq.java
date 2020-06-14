public class Freq
{
    public static void main(String[] args)
    { // Frequency counter
        BST<String, Integer> st = new BST<String, Integer>();
        while (!StdIn.isEmpty())
        {
            String key = StdIn.readString();
            if (st.contains(key)) st.put(key, st.get(key) + 1);
            else
            st.put(key, 1);
        }
        for (String s : st.keys())
            StdOut.printf("%8d %s\n", st.get(s), s);
    }
}