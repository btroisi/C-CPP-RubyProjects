def concat(a,b)
    #Concatenates a and b
    return a+b
end

def add(c,d)
    #Adds a and b
    return c+d
end

def unlimitedparams(a,b,*others)
    #Prints a,b, and all other arguments that may be passed in 
    #this function when called
    #Allows us to pass in unknown number of arguments in function
    puts a
    puts b
    puts others
end

puts concat("Hi","Lo")
puts add(5,6)
unlimitedparams(1,2,3,5,4,2,4,5,4)

class Professor
    #Dynamically create functions that print which class each professor teaches
    ["Bruce", "Stephanie", "Ying"].each do |action|
        define_method("teach_#{action}") do |argument|
              "#{action.gsub('_', ' ')} teaches #{argument}"
        end
    end
end
  
prof = Professor.new
puts prof.teach_Bruce("CS232")
puts prof.teach_Stephanie("CS251")
puts prof.teach_Ying("CS333")


class Parent #Parent class
    def display
        #Display method prints "I am the parent"
        puts "I am the parent"
    end
end
class Child<Parent 
    def display
        #Display method prints "I am the child" 
        #Overrides display method in parent class
        puts "I am the child"
    end
end

ch=Child.new
ch.display
