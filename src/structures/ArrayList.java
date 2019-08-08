package structures;

/**
 * ArrayList Implementation
 * 
 * @author saibulusu
 *
 */
public class ArrayList<T> {

  T[] array; // the array that contains every generic value

  /**
   * Constructor to create an arraylist
   */
  public ArrayList() {
    // the array is initially at length 0
    array = (T[]) (new Object[0]);
  }

  /**
   * Get the value in this arraylist at the given index
   * 
   * @param index the location in the array where the desired value resides
   * @return the value at the given index
   */
  public T get(int index) {
    // cannot get a value that is out of range
    if (0 > index || index >= array.length) {
      throw new IllegalArgumentException();
    }
    return array[index];
  }

  /**
   * Insert a given value to the array list
   * 
   * @param value the value to be inserted into the arraylist
   */
  public void insert(T value) {
    // the new array will contain all of the right elements
    T[] newArray = (T[]) new Object[array.length + 1];
    // copy every element over
    for (int i = 0; i < array.length; i++) {
      newArray[i] = array[i];
    }
    // add the new element and reassign array to contain all of the right elements now
    newArray[array.length] = value;
    array = newArray;
  }

  /**
   * Insert a given value to the array list at the given location
   * 
   * @param value the value to be inserted
   * @param index the location at which to insert the value
   */
  public void insert(T value, int index) {
    if (0 > index || index > array.length) {
      throw new IllegalArgumentException();
    }
    // the new array will contain all of the right elements
    T[] newArray = (T[]) new Object[array.length + 1];
    // copy the first set of elements over
    for (int i = 0; i < index; i++) {
      newArray[i] = array[i];
    }
    // add the new element and reassign array to contain all of the right elements now
    newArray[index] = value;
    // copy the second set of elements over
    for (int i = index + 1; i < newArray.length; i++) {
      newArray[i] = array[i - 1];
    }
    array = newArray;
  }

  /**
   * Remove a value from this list at the given index and return the value that was removed
   * 
   * @param index the location of the value being removed
   * @return the value being removed in this array list
   */
  public T delete(int index) {
    // make sure the desired index to remove is in range
    if (0 > index || index >= array.length) {
      throw new IllegalArgumentException();
    }
    // create a new array that is one element smaller
    T[] newArray = (T[]) new Object[array.length - 1];
    // adjust the elements
    for (int i = newArray.length - 1; i > index; i--) {
      newArray[i] = array[i + 1];
    }
    T ignore = array[index];
    // add the remaining values
    for (int i = index - 1; i >= 0; i--) {
      newArray[i] = array[i];
    }
    // reassign array to the new array with one less element
    array = newArray;
    return ignore;
  }

  /**
   * Accessor for the size of the list
   * 
   * @return
   */
  public int size() {
    return array.length;
  }

  /**
   * Check if the list is empty
   * 
   * @return whether the list has a size of 0 or not
   */
  public boolean isEmpty() {
    return array.length == 0;
  }

  /**
   * Remove every element from the list
   */
  public void clear() {
    // simply reinitializing array is the fastest way to remove every element
    array = (T[]) new Object[0];
  }
}
