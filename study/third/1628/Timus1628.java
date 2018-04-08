package timus;

import java.util.Scanner;

public class Timus1628 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        byte[][] bytes = new byte[m][n];

        for (int i = 0; i < k; i++) {
            bytes[scanner.nextInt() - 1][scanner.nextInt() - 1] = 1;
        }

        int whiteStreaks = 0;
        for (int i = 0; i < m; i++) {
            int currLength = 0;
            for (int j = 0; j < n; j++) {
                if (bytes[i][j] < 1) {
                    currLength++;
                } else {
                    if (currLength == 1) {
                        bytes[i][j - 1] = -1;
                    }
                    if (currLength > 1) {
                        whiteStreaks++;
                    }
                    currLength = 0;
                }
            }
            if (currLength > 1) {
                whiteStreaks++;
            }
            if (currLength == 1) {
                bytes[i][n - 1] = -1;
            }
        }

        for (int i = 0; i < n; i++) {
            int currLength = 0;
            for (int j = 0; j < m; j++) {
                if (bytes[j][i] < 1) {
                    currLength++;
                } else {
                    if (currLength == 1 && bytes[j - 1][i] == -1) {
                        whiteStreaks++;
                    }
                    if (currLength > 1) {
                        whiteStreaks++;
                    }
                    currLength = 0;
                }
            }
            if (currLength > 1) {
                whiteStreaks++;
            }
            if (currLength == 1 && bytes[m - 1][i] == -1) {
                whiteStreaks++;
            }
        }

        System.out.println(whiteStreaks);

    }
}
