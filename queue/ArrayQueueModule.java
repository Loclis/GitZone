package queue;

//Inv = {size >= 0 && tail == (head + size) % elements.length)
public class ArrayQueueModule {
    private static int head = 0, tail = 0, size = 0;
    private static Object[] elements = new Object[2];

    // Pre:  capacity > 0
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //      for t = 0 .. size' - 1) && tail == head + size && size == size'
    private static void ensureCapacity(final int capacity) {
        if (capacity < elements.length){
            return;
        }

        Object[] newArray = new Object[elements.length * 2];
        if (tail <= head) {
            System.arraycopy(elements, head, newArray,0, elements.length - head);
            System.arraycopy(elements, 0, newArray, elements.length - head, tail);
        } else {
            System.arraycopy(elements, head, newArray, 0, tail - head);
        }

        elements = newArray;
        head = 0;
        tail = size;

        if (elements.length < capacity) ensureCapacity(capacity);
    }

    // Pre: value != null
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && && elements[(tail - 1) % elements.length] == value &&
    //       && tail == head + size && size == size' + 1
    public static void enqueue(final Object value) {
        if (value == null) throw new AssertionError("Null element found.");
        ensureCapacity(size + 1);
        elements[tail++] = value;
        if (tail == elements.length) {
            tail = 0;
        }
        size++;
    }

    // Pre: size > 0
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && tail == (head + size) % elements.length && size == size' && head == head' &&
    //       && tail == tail' && R = elements[head]
    public static Object element() {
        if (size == 0) throw new AssertionError("No elements found.");
        return elements[head];
    }

    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 2) && tail == (head + size) % elements.length && size == size' - 1 &&
    //       && head == (head' + 1) % elements.length && tail == tail' && R = elements[head']
    public static Object dequeue(){
        if (size == 0) throw new AssertionError("No elements found.");
        Object returnValue = elements[head++];
        elements[head] = null;
        if (head == elements.length) {
            head = 0;
        }
        size--;
        return returnValue;
    }

    // Pre: True
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && tail == (head + size) % elements.length && size == size' && head == head' &&
    //       && tail == tail' && R = elements[head] && R == size
    public static int size(){
        return size;
    }

    // Pre: True
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && tail == (head + size) % elements.length && size == size' && head == head' &&
    //       && tail == tail' && R = elements[head] && R == (size == 0)
    public static boolean isEmpty() {
        return size == 0;
    }

    // Pre: True
    // Post: elements.length == 2 && head == tail == size == 0 && elements[0] == elements[1] == null
    public static void clear() {
        elements = new Object[2];
        head = tail = size = 0;
    }

    public static void push(Object value) {
        if (value == null) throw new AssertionError("Null element found.");
        ensureCapacity(size + 1);
        elements[tail--] = value;
        if (tail == -1) tail= elements.length - 1;
        size++;
    }

    public static Object peek(){
        if (size == 0) throw new AssertionError("No elements found");
        return elements[tail];
    }

    public static Object pop(){
        if (size() == 0)
    }
}
