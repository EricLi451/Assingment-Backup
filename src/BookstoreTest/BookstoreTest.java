/**
 * Student Name:Shijun Li
 * Student Number:041121986
 * Lab professor : Amir Afrasiabi Rad
 */
package BookstoreTest;

import Bookstore.*;
import java.io.*;
import java.text.*;
import java.util.*;
import Book.Book;

/**
 * Main class to test the Bookstore functionality.
 */
public class BookstoreTest {

    /**
     * Main method to run the test.
     */
    public static void main(String[] args) {
        try {
            Bookstore bookstore = new Bookstore();           //instanciate bookstore

            DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
            String currentDate = dateFormat.format(new Date());

            System.out.printf("Awesome Bookstore's Inventory for %s\n", currentDate);

            bookstore.loadBooksFromCsv("books.csv");

            BufferedReader isbnReader = new BufferedReader(new FileReader("isbn.txt"));
            String isbn;
            while ((isbn = isbnReader.readLine()) != null) {
                Book book = bookstore.getBookByIsbn(isbn.trim());
                if (book != null) {
                    System.out.println(book);
                } else {
                    System.out.printf("%s    Not found\n", isbn.trim());
                }
            }
            isbnReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }}

