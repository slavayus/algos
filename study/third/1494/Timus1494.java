package timus;

import java.util.LinkedList;
import java.util.Scanner;

public class Timus1494 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        LinkedList<Integer> balls = new LinkedList<>();

        boolean cheater = false;

        int currentIndex = 0;
        balls.push(0);
        for (int i = 0; i < n; i++) {
            int currentBall = scanner.nextInt();
            Integer last = balls.peek();
            if (last < currentBall) {
                for (int j = currentIndex; j < currentBall - 1; j++) {
                    balls.push(++currentIndex);
                }
                currentIndex++;
            } else {
                if (last == currentBall) {
                    balls.remove();
                } else {
                    cheater = true;
                }
            }
        }
        System.out.println(cheater ? "Cheater" : "Not a proof");
    }
}
