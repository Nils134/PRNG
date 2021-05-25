import java.util.Scanner;
import java.lang.Math;

class Input {
    public static void main(String[] args) {
    	
        Scanner input = new Scanner(System.in);
    	while (true) {
            String inputstring =  input.next();
            for (int i = 0; i < 1000000; i++) {
                String number = String.format("%.12f", Math.random());
                System.out.println(number);
            }
        }
        

        // closing the scanner object
    }
}
