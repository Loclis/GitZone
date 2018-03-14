package expression;

public class Variable implements Expression {
    private String name;

    Variable(String name) {
        this.name = name;
    }

    @Override
    public int evaluate(int value) {
        return value;
    }
}
