package calc;

public class Multiply extends AbstractOperation {
    Multiply(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    double calc(double value) {
        return leftArgument.evaluate(value) * rightArgument.evaluate(value);
    }
}
