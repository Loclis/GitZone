package queue;

public abstract class AbstractQueue implements Queue{
    protected int size;

    protected void checkForNull(Object value) {
        if (value == null) {
            throw new AssertionError("Null element found.");
        }
    }

    protected void tryForGet() {
        if (isEmpty()) {
            throw new AssertionError("No elements found.");
        }
    }

    AbstractQueue(){
        size = 0;
    }

    @Override
    public void enqueue(Object value) {
        checkForNull(value);
        pushBack(value);
        size++;
    }

    @Override
    public Object element() {
        tryForGet();
        return getFront();
    }

    @Override
    public Object dequeue() {
        Object returnValue = element();
        popFront();
        size--;
        return returnValue;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public void clear() {
        size = 0;
        doCleaning();
    }

    @Override
    public void push(Object value) {
        checkForNull(value);
        pushFront(value);
        size++;
    }

    @Override
    public Object peek() {
        tryForGet();
        return getBack();
    }

    @Override
    public Object remove() {
        Object returnValue = peek();
        popBack();
        size--;
        return returnValue;
    }

    protected abstract void pushFront(Object value);
    protected abstract Object getFront();
    protected abstract void popFront();
    protected abstract void pushBack(Object value);
    protected abstract Object getBack();
    protected abstract void popBack();
    protected abstract void doCleaning();
}
