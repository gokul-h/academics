"""
The Head Librarian at a library wants you to make a program that calculates the fine
for returning the book after the return date. You are given the actual and the
expected return dates. Calculate the fine as follows:
a. If the book is returned on or before the expected return date,
    no fine will be charged, in other words fine is 0.
b. If the book is returned in the same month as the expected return date,
    Fine = 15 Rupees × Number of late days
c. If the book is not returned in the same month but in
    the same year as the expected return date, Fine = 500 Rupees × Number of late months
d. If the book is not returned in the same year, the fine is fixed at 10000 Rupees.
"""