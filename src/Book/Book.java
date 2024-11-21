/**
 * Student Name:Shijun Li
 * Student Number:041121986
 * Lab professor : Amir Afrasiabi Rad
 */
package Book;

/**
 *  Book in the bookstore with title, author, publication year, and ISBN
 */
public class Book {
	/**
	 * indicate the booktitle
	 */
    private String title;
    /**
	 * indicate the author
	 */
    private String author;
    /**
	 * indicate the publication year
	 */
    private int publicationYear;
    /**
	 * indicate the isbn number
	 */
    private String isbn;

    /**
     * Constructor to create a Book instance.
     * 
     * @param title the title of the book
     * @param author the author of the book
     * @param publicationYear the publication year of the book
     * @param isbn the ISBN of the book
     */
    public Book(String title, String author, int publicationYear, String isbn) {
        this.title = title;
        this.author = author;
        this.publicationYear = publicationYear;
        this.isbn = isbn;
    }
    /**
	 * get the title of book
	 */
public String getTitle() {
        return title;
    }
    /**
	 * get the auther of book
	 */
public String getAuthor() {
        return author;
    }
/**
	 * get the publish year of book
	 */
public int getPublicationYear() {
        return publicationYear;
    }
/**
	 * get the isbn number of book
	 */
public String getIsbn() {
        return isbn;
    }

    /**
     * format the values to string
     * 
     * @return a string representation of the book
     */
    @Override
    public String toString() {
        return String.format("%s    %-40s %4d %-30s", isbn, title, publicationYear, author);
    }
}
