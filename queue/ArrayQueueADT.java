package queue;

//Inv = {size >= 0 && tail == (head + size) % elements.length)
public class ArrayQueueADT {
    private int head = 0, tail = 0, size = 0;
    private Object[] elements = new Object[2];

    // Pre:  capacity > 0
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //      for t = 0 .. size' - 1) && tail == head + size && size == size'
    private static void ensureCapacity(final ArrayQueueADT queue, final int capacity) {
        if (capacity < queue.elements.length){
            return;
        }

        Object[] newArray = new Object[queue.elements.length * 2];
        if (queue.tail <= queue.head) {
            System.arraycopy(queue.elements, queue.head, newArray,0, queue.elements.length - queue.head);
            System.arraycopy(queue.elements, 0, newArray, queue.elements.length - queue.head, queue.tail);
        } else {
            System.arraycopy(queue.elements, queue.head, newArray, 0, queue.tail - queue.head);
        }

        queue.elements = newArray;
        queue.head = 0;
        queue.tail = queue.size;

        if (queue.elements.length < capacity) ensureCapacity(queue, capacity);
    }

    // Pre: value != null
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && && elements[(tail - 1) % elements.length] == value &&
    //       && tail == head + size && size == size' + 1
    public static void enqueue(final ArrayQueueADT queue, final Object value) {
        if (value == null) throw new AssertionError("Null element found.");
        ensureCapacity(queue,queue.size + 1);
        queue.elements[queue.tail++] = value;
        if (queue.tail == queue.elements.length) {
            queue.tail = 0;
        }
        queue.size++;
    }

    // Pre: size > 0
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && tail == (head + size) % elements.length && size == size' && head == head' &&
    //       && tail == tail' && R = elements[head]
    public static Object element(final ArrayQueueADT queue) {
        if (queue.size == 0) throw new AssertionError("No elements found.");
        return queue.elements[queue.head];
    }

    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 2) && tail == (head + size) % elements.length && size == size' - 1 &&
    //       && head == (head' + 1) % elements.length && tail == tail' && R = elements[head']
    public static Object dequeue(final ArrayQueueADT queue){
        if (queue.size == 0) throw new AssertionError("No elements found.");
        Object returnValue = queue.elements[queue.head++];
        if (queue.head == queue.elements.length) {
            queue.head = 0;
        }
        queue.size--;
        return returnValue;
    }

    // Pre: True
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && tail == (head + size) % elements.length && size == size' && head == head' &&
    //       && tail == tail' && R = elements[head] && R == size
    public static int size(final ArrayQueueADT queue){
        return queue.size;
    }

    // Pre: True
    // Post: (elements[i] == elements[j], i = (head + t) % elements.length, j = (head' + t) % elements.length,
    //       for t = 0 .. size' - 1) && tail == (head + size) % elements.length && size == size' && head == head' &&
    //       && tail == tail' && R = elements[head] && R == (size == 0)
    public static boolean isEmpty(final ArrayQueueADT queue) {
        return queue.size == 0;
    }

    // Pre: True
    // Post: elements.length == 2 && head == tail == size == 0 && elements[0] == elements[1] == null
    public static void clear(final ArrayQueueADT queue) {
        queue.elements = new Object[2];
        queue.head = queue.tail = queue.size = 0;
    }
}
