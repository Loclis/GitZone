package calc;

public class Divide extends AbstractOperation {
    Divide(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    double calc(double value) {
        return leftArgument.evaluate(value) / rightArgument.evaluate(value);
    }
}

