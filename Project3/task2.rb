def binary_search (a,key)  # a is the array and key is the value to be found if key not found, returns "value not found in the array"
    lo = 0
    hi= a.length-1
    
    while (lo<=hi)
        mid = lo+((hi-lo)/2)
        
        if a[mid] == key
            return mid
        elsif a[mid] < key
            lo=mid+1
        else
            hi=mid-1
        end
        
    end
    
    return "Value not found in the array"
end

list = [1,2,3,4,5,6,7]
puts "List for binary searching: #{list}"
puts "Executing binary search for 6...#{binary_search(list,6)}"
puts "Executing Binary search for 8...#{binary_search(list,10)}"