# All-Teachers-In-System
System zarządzania nauczycielami akademickimi

## Table contents:
* [How app 'works'] (#general-info)

## How app 'works'
After start of the up login window is showing up. You need to write your correct "Username" and "Password" data.
If you fail, you can make unlimited attempts again.
If you are correct, new Window with "correct" content of the application will show up.
There is "tab widget" with 4 pages:
a) Read
b) Create
c) Update
d) Delete
Read 'lets you' to take a look of entire content of "Teachers" table of "table.sqlite" database.
Create let's you create new teacher in "Teacher" table of your database.
Update let's you "update" your teacher in "Teacher" table of your database.
Delete let's you "delete" your teacher in "Teacher" table of your database.

Some of GENERAL rules aplying to Update, Create  when you are writing your data:
a) "Name", "Surname", "Title" and "ListOfSubjects" need to start with capital letter (Uppercase)
b) PESEL needs to be valid and have size of 11 character (no less, no more) with every character being digit
c) Sex needs to be "Male" or "Female" (lowercase and uppercase allowed)
d) Date needs to be valid and written with style on the right: "DD.MM.YYYY"
    * Profesors can't be born after 2000 or before of 1940 
e) Sizes of your data (restrictions):
    - length of "Name" size can't be equal to zero (that's empty data) or greater than 20.
    - length of "Surname" can't be equal to zero (that's empty data) or greater than 20.
    - length of QString "Sex", which contains your "Sex" can't be equal to 0 (that's empty data)  or greater than 6.
    - length of "DateOfBirth" of teacher can't be equal to zero (that's empty data)  or greater than 10
    - length of "Title" of teacher can't be equal to zero (that's empty data) or greater than 30
    - length of "ListOfSubjects" can't be equal to zero  (that's empty data) or greater than 50

Some of INDIVIDUAL rules apllying to Delete only:
a) "ID" and other data needs to be "THE SAME" as your data in your database

Some of INDIVIDUAL rules applying to Create only:
a) If there is the same data already in database you can't create "the same teacher" with only diffrence being "ID"


