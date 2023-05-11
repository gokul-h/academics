import textio.TextIO;

public class RomanConverter {
    public static void main(String[] args) {

        System.out.println("Enter a Roman numeral / Arabic Integer");
        System.out.println("Press enter to exit");
        while (true) {

            System.out.println();
            System.out.print("? ");

            while (TextIO.peek() == ' ' || TextIO.peek() == '\t')
                TextIO.getAnyChar();
                if (TextIO.peek() == '\n')
                    break;

                if (Character.isDigit(TextIO.peek())) {
                    int arabic = TextIO.getlnInt();
                    try {
                        RomanNumeral N = new RomanNumeral(arabic);
                        System.out.println(N.toInt() + " = " + N.toString());
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input.");
                        System.out.println(e.getMessage());
                    }
                } else {
                    String roman = TextIO.getln();
                    try {
                        RomanNumeral N = new RomanNumeral(roman);
                        System.out.println(N.toString() + " = " + N.toInt());
                    } catch (NumberFormatException e) {
                        System.out.println("Invalid input.");
                        System.out.println(e.getMessage());
                    }
                }

        } 

    } 

} 