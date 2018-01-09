
$g = 10  #global variable
VAR1 = 100 #constant 



#Student class
class Student
   @@no_of_students = 0 #class variable
   localvar1="First local variable" #local variable in Student class
   def initialize(name, major, year)
      
      @stud_name = name #instance variable for name
      @stud_major = major #instance variable for major
      @stud_year = year #instance variable for year
   end
   def display_info()
      puts("INSIDE THE STUDENT CLASS")
      localvar2="Yet another local variable" #local variable in method within Student class
      puts "Name  #@stud_name"
      puts "Major #@stud_major"
      puts "Year #@stud_year"
      puts "Types of variables #{defined? @stud_name}, #{defined? @stud_major}, #{defined? @stud_name}"
      puts "Local varible within a class method #{localvar2}" 
      puts "Value of #{defined? VAR1} is #{VAR1}"
         end
   def total_no_of_students()
      @@no_of_students += 1 #increases total number of students by 1 as you add more students
      puts "Total number of students: #@@no_of_students"
      puts "#{defined? $g} in is #{$g}"

end

# Create Object
student1 = Student.new("Brandon Troisi", "CS/Math", "2019")
student2 = Student.new("Kate McCarthy", "Econ", "2020")

# Call Methods
student1.display_info()
student2.display_info()
student1.total_no_of_students()
student2.total_no_of_students()
puts "OUTSIDE OF THE CLASS.."
puts "Local var in Student #{localvar1}"
puts "Total number of students: #{defined? @@no_of_students}, #@@no_of_students"
#puts "Local var in Student method #{localvar2}"

end
