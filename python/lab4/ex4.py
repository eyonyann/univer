class Book:
    book_count = 0

    def __init__(self, title, author, year, pages):
        self.title = title
        self.author = author
        self.year = year
        self.pages = pages
        Book.book_count += 1

    def display_info(self):
        print(f"Title: {self.title}\nAuthor: {self.author}\nYear: {self.year}\nPages: {self.pages}")

    @staticmethod
    def is_thick(pages):
        return pages > 500

    @classmethod
    def increase_all_years(cls):
        cls.book_count += 1
        print(f"All books have been updated. Total books: {cls.book_count}")

book1 = Book("The Catcher in the Rye", "J.D. Salinger", 1951, 277)
book2 = Book("To Kill a Mockingbird", "Harper Lee", 1960, 281)
book3 = Book("War and Peace", "Leo Tolstoy", 1869, 1225)

book1.display_info()

print(f"Is 'War and Peace' a thick book? {Book.is_thick(book3.pages)}")

Book.increase_all_years()
