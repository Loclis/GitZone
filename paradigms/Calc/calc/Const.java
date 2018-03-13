package calc;

public class Const implements Expression {
    private double value;

    Const(double value) {
        this.value = value;
    }

    @Override
    public double evaluate(double value) {
        return this.value;
    }
}
