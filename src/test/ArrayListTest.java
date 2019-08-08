package test;

import static org.junit.Assert.fail;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import structures.ArrayList;

/**
 * Tester class for ArrayList object
 * 
 * @author saibulusu
 *
 */
public class ArrayListTest {

  ArrayList<String> list; // the list that is being tested on

  /**
   * Reinitialize the array list each time before another test
   * 
   * @throws java.lang.Exception
   */
  @BeforeEach
  void setUp() throws Exception {
    list = new ArrayList<String>();
  }

  @Test
  void test0_init() {
    try {
      if (!list.isEmpty()) {
        fail("list should be empty at initialization");
      }
      if (list.size() != 0) {
        fail("size should initially be zero");
      }
    } catch (Exception e) {
      fail("unexpected exception");
    }
  }
  
  @Test
  void test1_addElement() {
    try {
      list.insert("Hello, World!");
      if (list.size() != 1) {
        fail("size of the list should be one after adding one value");
      }
    } catch (Exception e) {
      fail("unexpected exception");
    }
  }
  
  @Test
  void test2_addElementWrongIndex() {
    try {
      try {
        list.insert("", -1);        
      } catch (IllegalArgumentException e) {
        return;
      }
    } catch (Exception e) {
      fail("unexpected exception");
    }
  }
  
  @Test
  void test3_addElements() {
    try {
      list.insert("1", 0);
      list.insert("2", 0);
      list.insert("3", 1);
      if (!list.get(0).equals("2") || !list.get(1).equals("3") || !list.get(2).equals("1")) {
        fail("insertion failed");
      }
    } catch (Exception e) {
      fail("unexpected exception");
    }
  }
  
  @Test
  void test4_removeElements() {
    try {
      list.insert("");
      list.insert("two", 1);
      list.delete(1);
      if (!list.get(0).equals("")) {
        fail("wrong value deleted");
      }
      if (list.size() != 1) {
        fail("wrong size after inserting two and deleting 1");
      }
      if (list.isEmpty()) {
        fail("list should not be empty");
      }
    } catch (Exception e) {
      fail("unexpected exception");
    }
  }
  
  void test5_removeAllElements() {
    try {
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.insert("");
      list.clear();
      if (list.size() != 0 || !list.isEmpty()) {
        fail("list should be empty after clearing every element");
      }
    } catch (Exception e) {
      fail("unexpected exception");
    }
  }
}
