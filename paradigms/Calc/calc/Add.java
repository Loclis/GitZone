package calc;

public class Add extends AbstractOperation {
    Add(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    double calc(double value) {
        return leftArgument.evaluate(value) + rightArgument.evaluate(value);
    }
}
