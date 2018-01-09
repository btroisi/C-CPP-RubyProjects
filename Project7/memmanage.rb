#Test garbage collection on creating global object 
GC.start
freed_before = GC.stat[:total_freed_object]
total_before=GC.stat[:total_allocated_object]


globarr = []
100_000.times do
  globarr << "hi"
end


GC.start
freed_after = GC.stat[:total_freed_object]
total_after=GC.stat[:total_allocated_object]
numfreed=freed_after-freed_before
numalloc=total_after-total_before
puts "Objects Freed global array : #{numfreed}"
puts "Total number of objects allocated global array: #{numalloc}"

#Observe garbage collection for creating 100,000 references 
#to "hi", not actual string objects by using freeze
GC.start
freed_before = GC.stat[:total_freed_object]
total_before=GC.stat[:total_allocated_object]

f=[]
100_000.times do
    f<<"hi".freeze
end

GC.start
freed_after = GC.stat[:total_freed_object]
total_after=GC.stat[:total_allocated_object]
numfreed=freed_after-freed_before
numalloc=total_after-total_before
puts "Objects Freed after freeze: #{numfreed}"
puts "Total number of objects allocated after freeze: #{numalloc}"


#Creates 1,000,000 copies of "hi" and observe garbage collection when
#Making copies inside function
def make_array_GC
    GC.start
    freed_before = GC.stat[:total_freed_object]
    total_before=GC.stat[:total_allocated_object]

    array=[]
    1_000_000.times do
        array<<"hi"
    end

    GC.start
    freed_after= GC.stat[:total_freed_object]
    total_after=GC.stat[:total_allocated_object]
    numfreed=freed_after-freed_before
    numalloc=total_after-total_before
    puts "Objects Freed after array creation in function: #{numfreed}"
    puts "Total number of objects allocated after array creation in function: #{numalloc}"
end 

#Test garbage collection before and after function call
GC.start
freed_before = GC.stat[:total_freed_object]
total_before=GC.stat[:total_allocated_object]
make_array_GC
GC.start
freed_after= GC.stat[:total_freed_object]
total_after=GC.stat[:total_allocated_object]
numfreed=freed_after-freed_before
numalloc=total_after-total_before
puts "Objects Freed after function call: #{numfreed}"
puts "Total number of objects allocated after function call: #{numalloc}"

#Make 1,000,000 copies of "hi"
def make_large_arr
    array=[]
    1_000_000.times do
        array<<"hi"
    end
end

#Call function many times and see how long it takes to execute on each iteration
for i in 0..100
    begintime=Time.now
    make_large_arr
    endtime=Time.now
    puts "Time it takes to execute make_large_arr on iteration #{i}: #{endtime-begintime} "
end 

