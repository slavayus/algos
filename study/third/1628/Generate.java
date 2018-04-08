package timus;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

public class Generate {
    public static void main(String[] args) throws FileNotFoundException {
        PrintWriter data = new PrintWriter(new File("dataRT"));
        int number = 15;
        for (int i = 0; i < 1; i++) {
            int m = 1000;
            int n = 120;
            int k = 60_000;
            data.println(m + " " + n + " " + k);
            for (int l = 1; l < m; l++) {
                for (int j = 1; j < n; j++) {
                    if (j % 2 != 0) {
                        data.println(l + " " + j);
                    }
                }
            }
            data.println();
        }
        data.close();
    }
}
