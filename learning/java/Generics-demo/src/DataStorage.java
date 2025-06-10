/*
<T> is a type parameter, making the class flexible to handle any object type.
setData() and getData() work with the type T, which gets specified when the object is created.
 */
// Generic storage class
public class DataStorage<T> {
    private T data;

    public void setData(T data) {
        this.data = data;
    }

    public T getData() {
        return data;
    }
}

