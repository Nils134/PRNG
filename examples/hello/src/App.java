import java.util.*;

class Input {
    public static void main(String[] args) {
    	
        Scanner input = new Scanner(System.in);
        Random random = new Random();
        random.setSeed(42);
    	while (true) {
            String inputstring =  input.next();
            for (int i = 0; i < 1000000; i++) {
                String number = String.format("%.12f", random.nextDouble());
                System.out.println(number);
            }
        }
        
    }
}
