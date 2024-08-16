# Studio 16
1. Asher Garvens, Katherine Fang, Tanner Sharon
2. You'd have to declared and abstract class and create pure virtual function
   so you can create unique classes that inherit from the baseclass but override
   the virtual functions.
3. It would be interface inheritance since all the subclasses share the same interface, but they
   do not share any implementation similarities.
4. The member variables should be private at the moment because we want to minimize the interface 
   to the client code.
5. Testing in studio16.cpp below
   We created the object of type TextFile and ran it and encountered the following:
   We just called all the functions on the single object and ran main().
   Writing worked on the first try and we tested getName and read next. Those tests also worked in
   the studio16.cpp file. We tried the unit tests after. Everything behaved as expected
6. Q5. We did this by making a reference to a textFile object. Our full main is copied below also.
   int main(int argc, char** argv){
   TextFile test("asdlasdlkfjasdf");
   AbstractFile &p = test;

   std::vector<char> vec = {'a', 'b', 'c'};

   p.write(vec);
   std::cout << p.getName() << std::endl;
   p.read();
   std::cout << std::endl;
   p.append(vec);
   p.read();
   std::cout << p.getSize() << std::endl;
   }
   