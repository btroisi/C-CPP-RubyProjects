
#Control statements in ruby

puts "Case statements"
#Case statements in ruby

#Take in user input from command line
print "Enter your class year: "
class_year=gets.chomp


case class_year
	#If user input is 2021 program prints "You're a freshman"
	when "2021"
		puts "You're a freshman"
	#If user input is 2020 program prints "You're a sophomore"
	when "2020"
		puts "You're a sophomore"
	#If user input is 2019 program prints "You're a junior"
	when "2019"
		puts "You're a junior"
	#If user input is 2018 program prints "You're a senior"
	when "2018"
		puts "You're a senior"
	#For all other user input program prints "You're not a college student"
	else
		puts "You're not a college student"
end



puts "For loops"
puts "Printing numbers 0-9 in ascending order"

#For loop that prints numbers 0 to 9 in ascending order 
for j in 0..9 do
	puts "#{j}"
end

#Use a for loop to print all values in array sportsary.
sportsary=["Football","Basketball","Baseball","Lacrosse","Wrestling","Rugby","Crew"]
puts "A list of sports"
for k in 0..sportsary.length
	puts sportsary[k]
end

#Use each and do to print all values in array sportarray
puts "Printing a list of sports using each"

sportsary.each do |sport|
	puts sport
end

#Use a while loop with a redo to play a guessing game where you must gues a number between 1 and 10

puts "A while loop with a redo demonstrated with a guessing game"
#The correct number is some random number between 1 and 10 
correct_num=rand(1..10)
#Program reads user input from command line for their guess between 1 and 10
print "Guess a number between 1 and 10: "
guess=gets.chomp.to_i

#While the user's guess is not equal to the correct number
#The user keeps guessing
while guess!=correct_num do

	print "Guess again: "
	guess=gets.chomp.to_i
	
	#If the user inputs a value between 1 and 10
	if guess.between?(1,10)
		#If the user guesses the correct number
		#Program prints congratulations you guessed the correct number
		if guess==correct_num
			puts "Congratulations you guessed the correct number"
			break
		end
	
	#Otherwise, the program prints "Invalid inpu" and redo statement sends user back to the beginning of the loop
	else 
		puts "Invalid input "
		redo
	end
	
end

#Use until statment to show how many "seconds" there are left in the program
#It goes from 5 up until 0 seconds
time_left = 5

until time_left == 0
  
    #If time_left is 1 prints "There is only 1 second left for this program"
    if time_left == 1
        puts "There is only #{time_left} second left for this program"
    #Otherwise prints "There are (2-5) seconds left for this program" depending on what time_left is.
    else
        puts "There are #{time_left} seconds left for this program"
    end

    time_left -= 1
end


