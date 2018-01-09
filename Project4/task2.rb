#Function types in ruby

#Function passing with procs, blocks of code that are bound to 
#a set of local variables
#Once bound code can be called in different conxtexts 
#and still access those variables
puts "Funciton passing with procs"
#This function multiplies a number n by a factor factor

def gen_times(factor)
	return Proc.new {|n| n*factor}
end

times3=gen_times(3)
times5=gen_times(5)

puts times3.call(12) #Prints 36 as this is 12*3
puts times5.call(4) #Prints 20 as this is 4*5

#References to funcitons can also be passed in as a parameter
#of a function in ruby

puts "Function pasing with blocks"
#Function a passes in x and y sums x and y
def a(x,y)
     x + y
   end

#Function x passes in parameter b and sends message to an object instance that
#is defined when it is called
#This passes in b,3,4. 
 def x(b)
 	send(b,3,4)
 end

   #Passes funciton a as a parameter for x which returns the sum of 3 and 4
   puts x(:a)  # Prints 7 wihich is 3+4

def block_method
  yield("Brandon","CS")
  yield("Katie","Econ")
end

block_method do |name, major|
  puts "#{name} is a #{major} major"
end 

l=-> (name){puts "Hi #{name}"}
l.call("Jack")

