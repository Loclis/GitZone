package calc;

public class Subtract extends AbstractOperation{
    Subtract(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    double calc(double value) {
        return leftArgument.evaluate(value) - rightArgument.evaluate(value);
    }
}
