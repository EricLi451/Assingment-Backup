/**
 * Student Name:Shijun Li
 * Student Number:041121986
 * Lab professor : Amir Afrasiabi Rad
 */
package Bookstore;

import java.io.*;
import java.util.*;

import Book.Book;

/**
 *manages a collection of books using Map with the ISBN  numebr as the key.
 */
public class Bookstore {
	/**
	 * create a map to store each single line of book info in map
	 */
    private Map<String, Book> inventory;

    /**
     * initialize the Bookstore
     */
    public Bookstore() {
        inventory = new HashMap<>();
    }

    /**
     * Adds a book to the bookstore inventory.
     * 
     * @param  book to be added
     */
    public void addBook(Book book) {
        inventory.put(book.getIsbn(), book);
    }

    /**
     * retrieve a book by its ISBN.
     * 
     * @param the ISBN of the book
     * @return the Book object if found otherwise null
     */
    public Book getBookByIsbn(String isbn) {
        return inventory.get(isbn);
    }

    /**
     * Loads books from  CSV file 
     * 
     * @param filePath 
     * @throws IOException
     */
    public void loadBooksFromCsv(String filePath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String line;
        while ((line = reader.readLine()) != null) {
            String[] data = line.split(",");
            if (data.length == 4) {
                String title = data[0].trim();
                String author = data[1].trim();
                int publicationYear = Integer.parseInt(data[2].trim());
                String isbn = data[3].trim();
                Book book = new Book(title, author, publicationYear, isbn);
                addBook(book);
            }
        }
        reader.close();
    }
}
