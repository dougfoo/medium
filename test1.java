import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.HashMap;

public class test1 {
    
    private int a;
    public test1(int a) { this.a = a;    }
    public String toString() { return "this repr " + this.a;    }
    public void printme() { System.out.println(this.a);    } 
    public int fib(int a) {
        if (a == 0 || a == 1)
            return a;
        else
            return fib(a-1) + fib(a-2);
    }
    public int add(int a, int b) {
        return a+b;
    }
        
    public static void main(String[] args) throws IOException {
        System.out.println("Foo");

        long t0 = System.currentTimeMillis();                
        for (int i =0; i < 10000000; i++) {         
        }
        long t1 = System.currentTimeMillis();
        System.out.println ("loop 10m pass: "+ (t1-t0)/1000.0);  // ms

        t0 = System.currentTimeMillis();                
        for (int i =0; i < 10000000; i++) {         
            test1 f = new test1(i);
        }
        t1 = System.currentTimeMillis();
        System.out.println ("1m Foo: "+ (t1-t0)/1000.0);  // ms


        t0 = System.currentTimeMillis();                
        for (int i =0; i < 1000000; i++) {         
            double j = 1/Math.sqrt(i);
        }
        t1 = System.currentTimeMillis();
        System.out.println ("1m 1/sqrt: "+ (t1-t0)/1000.0);  // ms


        t0 = System.currentTimeMillis();                
        StringBuilder sb = new StringBuilder();
        for (int i =0; i < 500000; i++) {         
            sb.append(i);
        }
        t1 = System.currentTimeMillis();
        System.out.println ("500k str concat: "+ (t1-t0)/1000.0);  // ms
        System.out.println("str len "+sb.length());

        //  THIS takes 249.998 seconds believe it or not!!
        // t0 = System.currentTimeMillis();                
        // String k = "";
        // for (int i =0; i < 500000; i++) {         
        //     k += i;
        // }
        // t1 = System.currentTimeMillis();
        // System.out.println ("500k str concat: "+ (t1-t0)/1000.0);  // ms
        // System.out.println("str len "+k.length());

        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();

        
        t0 = System.currentTimeMillis();       
        for (int i=0; i < 900000; i++) {
            if (m.get(i/10) == null) 
                m.put(i/10, i);
            else
                m.put(i/10, m.get(i/10)+i);          
            }
        t1 = System.currentTimeMillis();
        System.out.println ("900k make map: "+ (t1-t0)/1000.0);  // ms

        t0 = System.currentTimeMillis();                
        String f = new String(Files.readAllBytes(Paths.get("tale-of-two-cities64x.txt")));
        t1 = System.currentTimeMillis();
        System.out.println ("read 11m word file: "+ (t1-t0)/1000.0);  // ms

        f = new String(Files.readAllBytes(Paths.get("tale-of-two-cities.txt")));
        t0 = System.currentTimeMillis();                
        Arrays.sort(f.toCharArray());
        t1 = System.currentTimeMillis();
        System.out.println ("sort 792k words: "+ (t1-t0)/1000.0);  // ms

        test1 t = new test1(1);
        t0 = System.currentTimeMillis();                
        t.fib(40);
        t1 = System.currentTimeMillis();
        System.out.println ("fib 40: "+ (t1-t0)/1000.0);  // ms

        t0 = System.currentTimeMillis();                
        for (int i =0; i < 10000000; i++) {         
            t.add(i, t.add(i,1));
        }
        t1 = System.currentTimeMillis();
        System.out.println ("test func: "+ (t1-t0)/1000.0);  // ms

        int z = 0;
        t0 = System.currentTimeMillis();                
        for (int i =0; i < 10000000; i++) {         
            int y = i+i+1;
        }
        t1 = System.currentTimeMillis();
        System.out.println ("test inline: "+ (t1-t0)/1000.0);  // ms

    }
}
