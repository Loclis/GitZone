package expression;

import exceptions.OverflowException;
import operations.Operations;

public class Multiply<T> extends AbstractBinaryOperation<T> {
    public Multiply(CommonExpression<T> leftArgument, CommonExpression<T> rightArgument, Operations<T> operations) {
        super(leftArgument, rightArgument, operations);
    }

    @Override
    protected T apply(T leftValue, T rightValue) throws OverflowException {
        return operations.multiply(leftValue, rightValue);
    }
}
