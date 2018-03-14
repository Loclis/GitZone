package expression;

public class Divide extends AbstractOperation {
    Divide(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    int calc(int value) {
        return leftArgument.evaluate(value) / rightArgument.evaluate(value);
    }
}

