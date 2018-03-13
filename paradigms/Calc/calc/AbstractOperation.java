package calc;

public abstract class AbstractOperation implements Expression {
    Expression leftArgument, rightArgument;

    AbstractOperation(Expression leftArgument, Expression rightArgument) {
        this.leftArgument = leftArgument;
        this.rightArgument = rightArgument;
    }

    @Override
    public double evaluate(double value) {
        return calc(value);
    }

    abstract double calc(double value);
}
