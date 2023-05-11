class AreaException extends Exception {
    public String toString() {
        return "AreaException: Not enough arguments";
    }
}
class Area {
    int length,
    breadth;
    Area(int l, int b) {
        length = l;
        breadth = b;
        System.out.println("Area: " + l * b);
    }

}
public class Main {
    public static void main(String[] args)throws AreaException {
        try {
            int a = args.length;
            if (a == 0 || a == 1) {
                throw new AreaException();
            }
            Area newarea = new Area(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
        } catch (NumberFormatException e) {
            System.out.println("Illegal Values!");
        }
    }

}
// Test in shell in coding room using commands
// javac Main.java
// java Main 10 11 ->Runs Sucessfully
// java Main 10 -> throws AreaException
