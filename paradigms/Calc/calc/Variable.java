package calc;

public class Variable implements Expression {
    private String name;

    Variable(String name) {
        this.name = name;
    }

    @Override
    public double evaluate(double value) {
        return value;
    }
}
