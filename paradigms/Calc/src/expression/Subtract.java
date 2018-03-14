package expression;

public class Subtract extends AbstractOperation{
    Subtract(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    int calc(int value) {
        return leftArgument.evaluate(value) - rightArgument.evaluate(value);
    }
}
