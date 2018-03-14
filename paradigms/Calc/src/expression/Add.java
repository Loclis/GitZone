package expression;

public class Add extends AbstractOperation {
    Add(Expression leftArgument, Expression rightArgument) {
        super(leftArgument, rightArgument);
    }

    @Override
    int calc(int value) {
        return leftArgument.evaluate(value) + rightArgument.evaluate(value);
    }
}
