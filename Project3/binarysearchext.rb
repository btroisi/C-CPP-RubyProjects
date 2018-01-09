ary = [0, 4, 7, 10, 12]
puts "List for binary search: #{ary}"
puts "Searching for 4...#{ary.bsearch {|x| 4 <=>   x }}" #returns 4
puts "Searching for 7...#{ary.bsearch {|x| 7 <=>   x }}" #returns 7
puts "Searching for 10...#{ary.bsearch {|x| 10 <=>   x }}" # retuns 10
puts "Searching for 8...#{ary.bsearch {|x| 8 <=>   x }}" #returns nil
puts "Searching for 16...#{ary.bsearch {|x| 16 <=>   x}}" # returns nil