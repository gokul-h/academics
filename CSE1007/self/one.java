//filename: Book.java
// Book class
public class Book {
    private String Name;
    private String ISBN;
    private String Author;
    private String Publisher;
    public Book() {
    Name = “NULL”;
    ISBN = “NULL”;
    Author = “NULL”;
    Publisher = “NULL”;
    }
    
    public Book(String name, String isbn, String author, String publisher) {
    Name = name;
    ISBN = isbn;
    Author = author;
    Publisher = publisher;
    }
    
    public void setName(String Name) {
    this.Name = Name;
    }
    public String getName() {
    return Name;
    }
    public void setISBN(String ISBN) {
    this.ISBN = ISBN;
    }
    public String getISBN() {
    return ISBN;
    }
    public void setAuthor(String Author) {
    this.Author = Author;
    }
    public String getAuthor() {
    return Author;
    }
    public void setPublisher(String Publisher) {
    this.Publisher = Publisher;
    }
    public String getPublisher() {
    return Publisher;
    }
    
    public void getBookInfo() {
    System.out.printf(“%s %s %s %s”, Name,ISBN,Author,Publisher);
    }
    
    }
    //filename: SavingsAccountTest.java
    // SavingsAccount testing class with the main() method
    public class BookTest {
    public static void main(String[] args) {
    
    Book test[] = new Book[13];
    test[1] = new Book();
    test[1].getBookInfo();
    
    }
    }