package calc;

public class Main {
    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No arguments found.");
            return;
        }
        try {
            double value = Double.parseDouble(args[0]);
            System.out.println(new Add(
                            new Subtract(
                                    new Multiply(
                                            new Variable("x"),
                                            new Variable("x")
                                    ), new Multiply(
                                    new Const(2),
                                    new Variable("x")
                            )), new Const(1)
                    ).evaluate(value)
            );
        } catch (NumberFormatException e) {
            System.out.println("Invalid input found");
        }
    }
}
