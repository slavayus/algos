package timus;

import java.util.*;

public class NewTimus1628 {
    private static List<Dot> oneX = new ArrayList<>();
    private static List<Dot> oneY = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        Dot[] data = readData(k, scanner);

        Arrays.sort(data, 0, k, (dot, t1) -> dot.x == t1.x ? dot.y - t1.y : dot.x - t1.x);

        int whiteStreaks = n + m;
        if (m == 1 && n == 1 && data.length == 0) {
            whiteStreaks--;
        }

        if (m != 1 && n == 1) {
            whiteStreaks = data.length == 0 ? 1 : 0;

            for (int i = 1; i < data.length; i++) {
                if (data[i].x - data[i - 1].x > 1) {
                    whiteStreaks++;
                }
            }

            if (data.length > 0 && data[0].x > 1) {
                whiteStreaks++;
            }
            if (data.length > 0 && data[data.length - 1].x < m) {
                whiteStreaks++;
            }
        } else {
            if (m == 1 && n != 1) {
                whiteStreaks = data.length == 0 ? 1 : 0;

                for (int i = 1; i < data.length; i++) {
                    if (data[i].y - data[i - 1].y > 1) {
                        whiteStreaks++;
                    }
                }

                if (data.length > 0 && data[0].y > 1) {
                    whiteStreaks++;
                }
                if (data.length > 0 && data[data.length - 1].y < n) {
                    whiteStreaks++;
                }
            } else {
                whiteStreaks = countRight(data, n, whiteStreaks);
                Arrays.sort(data, 0, k, (dot, t1) -> dot.y == t1.y ? dot.x - t1.x : dot.y - t1.y);
                whiteStreaks = countDown(data, m, whiteStreaks, oneY);
            }
        }

        whiteStreaks += checkInOne();
        System.out.println(whiteStreaks);
    }

    private static int countDown(Dot[] data, int m, int whiteStreaks, List<Dot> oneY) {
        if (data.length == 0) {
            return whiteStreaks;
        }

        whiteStreaks--;
        if (data[0].x > 2) {
            whiteStreaks++;
        }
        if (data[0].x == 2) {
            oneY.add(new Dot(1, data[0].y));
        }

        int length;
        for (int i = 1; i < data.length; i++) {
            if (data[i].y != data[i - 1].y) {

                whiteStreaks--;

                length = m - data[i - 1].x;
                if (length > 1) {
                    whiteStreaks++;
                }
                if (length == 1) {
                    oneY.add(new Dot(m, data[i - 1].y));
                }

                if (data[i].x > 2) {
                    whiteStreaks++;
                }
                if (data[i].x == 2) {
                    oneY.add(new Dot(1, data[i].y));
                }
            } else {
                length = data[i].x - data[i - 1].x;
                if (length > 2) {
                    whiteStreaks++;
                }
                if (length == 2) {
                    oneY.add(new Dot(data[i].x - 1, data[i].y));
                }
            }
        }

        if (m - data[data.length - 1].x > 1) {
            whiteStreaks++;
        } else {
            if (m - data[data.length - 1].x == 1) {
                oneY.add(new Dot(m, data[data.length - 1].y));
            }
        }

        return whiteStreaks;
    }

    private static int countRight(Dot[] data, int n, int whiteStreaks) {
        if (data.length == 0) {
            return whiteStreaks;
        }

        whiteStreaks--;
        if (data[0].y > 2) {
            whiteStreaks++;
        }
        if (data[0].y == 2) {
            oneX.add(new Dot(data[0].x, 1));
        }

        int length;
        for (int i = 1; i < data.length; i++) {
            if (data[i].x != data[i - 1].x) {

                whiteStreaks--;

                length = n - data[i - 1].y;
                if (length == 1) {
                    oneX.add(new Dot(data[i - 1].x, n));
                }
                if (length > 1) {
                    whiteStreaks++;
                }

                if (data[i].y > 2) {
                    whiteStreaks++;
                }
                if (data[i].y == 2) {
                    oneX.add(new Dot(data[i].x, 1));
                }
            } else {
                length = data[i].y - data[i - 1].y;
                if (length > 2) {
                    whiteStreaks++;
                }
                if (length == 2) {
                    oneX.add(new Dot(data[i].x, data[i].y - 1));
                }
            }
        }

        if (n - data[data.length - 1].y > 1) {
            whiteStreaks++;
        } else {
            if (n - data[data.length - 1].y == 1) {
                oneX.add(new Dot(data[data.length - 1].x, n));
            }
        }
        return whiteStreaks;
    }

    private static int checkInOne() {
        oneY.sort((dot, t1) -> dot.x == t1.x ? dot.y - t1.y : dot.x - t1.x);

        Iterator<Dot> iteratorOneX = oneX.iterator();
        Iterator<Dot> iteratorOneY = oneY.iterator();
        if (!(iteratorOneX.hasNext() && iteratorOneY.hasNext())) {
            return 0;
        }

        Dot currentDotX = iteratorOneX.next();
        Dot currentDotY = iteratorOneY.next();

        int count = 0;
        while (iteratorOneX.hasNext() && iteratorOneY.hasNext()) {
            if (currentDotX.x < currentDotY.x) {
                currentDotX = iteratorOneX.next();
                continue;
            }
            if (currentDotX.x > currentDotY.x) {
                currentDotY = iteratorOneY.next();
                continue;
            }
            if (currentDotX.x == currentDotY.x) {
                if (currentDotX.y < currentDotY.y) {
                    currentDotX = iteratorOneX.next();
                    continue;
                }
                if (currentDotX.y > currentDotY.y) {
                    currentDotY = iteratorOneY.next();
                    continue;
                }
                if (currentDotX.y == currentDotY.y) {
                    count++;
                    currentDotX = iteratorOneX.next();
                    currentDotY = iteratorOneY.next();
                }
            }
        }

        while (iteratorOneX.hasNext()) {
            if (currentDotX.x == currentDotY.x && currentDotX.y == currentDotY.y) {
                count++;
            }
            currentDotX = iteratorOneX.next();
        }

        while ((iteratorOneY.hasNext())) {
            if (currentDotX.x == currentDotY.x && currentDotX.y == currentDotY.y) {
                count++;
            }
            currentDotY = iteratorOneY.next();
        }

        if (currentDotX.x == currentDotY.x && currentDotX.y == currentDotY.y) {
            count++;
        }

        return count;
    }

    private static Dot[] readData(int k, Scanner scanner) {
        Dot[] data = new Dot[k];

        for (int i = 0; i < k; i++) {
            data[i] = new Dot(scanner.nextInt(), scanner.nextInt());
        }
        return data;
    }

    private static class Dot {
        private int x;
        private int y;

        Dot(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "\n" + "x = " + x + " y = " + y;
        }
    }
}