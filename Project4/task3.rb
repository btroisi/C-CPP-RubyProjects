#Qucksort algorithm implemented for any type of variable in ruby

#Choose any element e of the array to be the pivot value (represented by h)
#Divide all other elements (execpt the pivot) into two partitions (l and r)
#All elements less than pivot must be in the l partition
#All elements greater than the pivot must be in the r partition
#Use recursion to sort both l and r partitions
class Array
  def quick_sort
    h, *t = self
    h ? t.partition { |e| e < h }.inject { |l, r| l.quick_sort + [h] + r.quick_sort } : []
  end
end

#Testing our quicksort funciton on an array of ints
ary=Array.new
ary=[1,2,69,5,42,39]
puts "Array before it was sorted #{ary}"
arysorted=ary.quick_sort
puts "Array after it was sorted #{arysorted}"

#Testing our quicksort function on an array of strings
ary1=Array.new
ary1=["Brandon","student","problems","the","dumb","thing"]
puts "String array before it was sorted #{ary1}"
ary1sorted=ary1.quick_sort
puts "String array after it was sorted #{ary1sorted}"

