import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Parser in = new Parser(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskA {
    public void solve(int testNumber, Parser in, OutputWriter out) {
        int n = in.nextInt();
        Integer[] a = new Integer[n];
        boolean[] b = new boolean[n];

        int cnt = n;
        for (int i = 0; i < n; i++) a[i] = in.nextInt();

        Arrays.sort(a);


        int l = 1;
        int st = 1;
        
        for (int i = 0; i < n; i++) {
            for (l = Math.max(l, i+i+1); l < n && a[i]*2 > a[l] ; l++);

            if (l < n) {
                st = Math.max(st, l-i);
                if (st + i < n) cnt = n-i-1;
            }
        }

        out.println(cnt);
    }
}

class Parser
{
    private BufferedReader din;
    private StringTokenizer tokenizer;

    public Parser(InputStream in)
    {
        din = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(din.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt()
    {
        return Integer.parseInt(next());
    }

    }

class OutputWriter extends PrintWriter {
    public OutputWriter(Writer out) {
        super(out);
    }

    public OutputWriter(OutputStream out) {
        super(out);
    }

    }