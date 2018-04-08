package timus;

import java.util.*;

public class Timus1650 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        Map<String, Billionaire> billionaires = readData(scanner, n);
        Map<String, CityStat> allMoneyInCity = countAllMonyInCity(billionaires);

        TreeSet<Map.Entry<String, CityStat>> sortedAllMoney = new TreeSet<>((t1, t2) -> t1.getValue().money == t2.getValue().money ? t1.getKey().compareTo(t2.getKey()) : Long.compare(t2.getValue().money, t1.getValue().money));
        sortedAllMoney.addAll(allMoneyInCity.entrySet());

        int allDays = scanner.nextInt();
        int numberOfAllMoves = scanner.nextInt();
        int prevDay = 0;

        for (int i = 0; i < numberOfAllMoves; i++) {
            int currentDay = scanner.nextInt();

            Map.Entry<String, CityStat> maxDay = getMaxDay(sortedAllMoney);
            if (maxDay != null) {
                maxDay.getValue().winnerDay += currentDay - prevDay;
            }

            String moveBillionaireName = scanner.next();
            String moveCityName = scanner.next();
            Billionaire billionaire = billionaires.get(moveBillionaireName);
            CityStat currentCityStat = allMoneyInCity.get(billionaire.city);

            sortedAllMoney.remove(new Entry<>(billionaire.city, currentCityStat));

            currentCityStat.money -= billionaire.count;

            sortedAllMoney.add(new Entry<>(billionaire.city, currentCityStat));

            billionaire.city = moveCityName;

            allMoneyInCity.putIfAbsent(billionaire.city, new CityStat(0, 0));
            currentCityStat = allMoneyInCity.get(billionaire.city);

            sortedAllMoney.remove(new Entry<>(moveCityName, currentCityStat));

            currentCityStat.money += billionaire.count;

            sortedAllMoney.add(new Entry(moveCityName, currentCityStat));
            prevDay = currentDay;
        }

        Map.Entry<String, CityStat> maxDay = getMaxDay(sortedAllMoney);

        if (maxDay != null) {
            maxDay.getValue().winnerDay += allDays - prevDay;
        }

        allMoneyInCity.forEach((s, cityStat) -> {
            if (cityStat.winnerDay != 0) {
                System.out.println(s + " " + cityStat.winnerDay);
            }
        });

    }

    private static Map.Entry<String, CityStat> getMaxDay(TreeSet<Map.Entry<String, CityStat>> sortedAllMoney) {
        Iterator<Map.Entry<String, CityStat>> iterator = sortedAllMoney.iterator();
        if (iterator.hasNext()) {
            Map.Entry<String, CityStat> first = iterator.next();

            if (iterator.hasNext()) {
                Map.Entry<String, CityStat> second = iterator.next();
                if (second.getValue().money > first.getValue().money) {
                    return second;
                } else {
                    if (second.getValue().money < first.getValue().money) {
                        return first;
                    }
                }
            } else {
                return first;
            }
        }
        return null;
    }

    private static Map<String, CityStat> countAllMonyInCity(Map<String, Billionaire> billionaires) {
        Map<String, CityStat> allMoneyInCity = new TreeMap<>();
        billionaires.forEach((s, billionaire) -> {
            allMoneyInCity.putIfAbsent(billionaire.getCity(), new CityStat(0L, 0L));
            allMoneyInCity.get(billionaire.city).money += billionaire.count;
        });
        return allMoneyInCity;
    }

    private static Map<String, Billionaire> readData(Scanner scanner, int n) {
        Map<String, Billionaire> billionaires = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String name = scanner.next();
            Billionaire billionaire = new Billionaire(scanner.next(), Long.parseLong(scanner.next()));
            billionaires.put(name, billionaire);
        }
        return billionaires;
    }

    static final class Entry<K, V> implements Map.Entry<K, V> {
        private final K key;
        private V value;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
        }

        @Override
        public K getKey() {
            return key;
        }

        @Override
        public V getValue() {
            return value;
        }

        @Override
        public V setValue(V value) {
            V old = this.value;
            this.value = value;
            return old;
        }
    }

    private static class CityStat {

        private long money;
        private long winnerDay;

        CityStat(long money, long winnerDay) {
            this.money = money;
            this.winnerDay = winnerDay;
        }
    }

    private static class Billionaire {
        private String city;
        private final long count;

        Billionaire(String city, long count) {
            this.city = city;
            this.count = count;
        }

        String getCity() {
            return city;
        }
    }
}