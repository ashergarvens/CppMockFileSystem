# Studio 19
1. Tanner, Katherine, Asher
2. We created and wrote to an image file and then read the file before and 
   after writing. When we read from the file, it returned the contents which 
   we inserted to the output stream.
3. the client code creates the visitor and calls accept on the file, passing 
   the visitor as an argument. then, the file calls the visit function with 
   the visitor and passes itself as the argument so the visitor can execute 
   on the file
4. the visitor pattern gives delegation of operations to the visitors and 
   not the different file types, which allows the file interfaces to be neat.
   the files only need to implement accept and then the visitor will provide 
   the execution of whatever needs to happen, not the file.
5. If you added a another file type to be visitable, you will have to modify 
   every visitor class (abstract, basic, and Metadata) to have a visit_<file 
   type> method (and you would also need that new file type to have the 
   accept method), which is just hard to manage when you add a lot of different
   visitors and file types. You shouldn't use the visitor pattern when you
   want to add a lot of different concrete types that use the visitor classes
   because it will become inefficient. 