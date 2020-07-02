class Bird:
     def intro(self):
       print("Существуют разные виды птиц")
 
     def flight(self):
       print("Большинство птиц умеют летать, но некоторые - нет")
 
class parrot(Bird):
     def flight(self):
       print("Попугаи умеют летать")
 
class penguin(Bird):
     def flight(self):
       print("Пингвины не умеют летать")
 
obj_bird = Bird()
obj_parr = parrot()
obj_peng = penguin()
 
obj_bird.intro()
obj_bird.flight()

#пример полиформизма с наследством
#происходит обращение к методам класса - родителя 
obj_parr.intro()
obj_parr.flight()
 
obj_peng.intro()
obj_peng.flight()
