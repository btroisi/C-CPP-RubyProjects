class Rectangle
	def initialize(width,height)
		@width=width
		@height=height
	end
	def area()
		return @width*@height
	end
	def perimeter()
		return 2*@width+2*@height
	end
	def modfunc()
		return @width%(@height)
	end

recta=Rectangle.new(3.4,5.6)
rectb=Rectangle.new(6.8,9.7)

puts "recta area: #{recta.area()}"
 
 puts "rectb area: #{rectb.area()}"
 
 puts "recta perimeter: #{recta.perimeter()}"
 
 puts "rectb perimeter: #{rectb.perimeter()}"
 
 puts "recta widthmodheight: #{recta.modfunc()}"
 
 puts "rectb widthmodheight: #{rectb.modfunc()}"
 
 puts "Difference in perimeter rectb and rect a: #{rectb.perimeter()-recta.perimeter()}"
 
 puts "Ratio of areas of rectb and recta: #{rectb.area()/recta.area()}"
end