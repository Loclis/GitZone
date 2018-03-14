package expression;

public class Multiply extends AbstractOperation {
    Multiply(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    int calc(int value) {
        return leftArgument.evaluate(value) * rightArgument.evaluate(value);
    }
}
