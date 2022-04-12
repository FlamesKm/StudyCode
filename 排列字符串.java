/**
 * 排列字符串
 */
public class 排列字符串 {

    public static void main(String[] args) {
        String[] input = new String[] { "tmc", "apad", "apache", "nihao", "nihaoa" };
        // String[] keys = arraySort(input);
        arraySort(input);
        for (String key : input) {
            System.out.println(key);
        }
    }

    public static void arraySort(String[] input) {
        for (int i = 0; i < input.length - 1; i++) {
            for (int j = 0; j < input.length - i - 1; j++) {
                if (input[j].compareTo(input[j + 1]) > 0) { // 从小到大
                    String temp = input[j];
                    input[j] = input[j + 1];
                    input[j + 1] = temp;
                }
            }
        }
    }

}