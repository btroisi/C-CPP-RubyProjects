#Brandon Troisi
#CS333 Fall 2017 Project 8
#Mergesort algorithm
#Want to check how long it takes to execute mergesort to order an array
#I got this algorthim from github because I was only interested 
#in computing the time it takes to run it, not writing the algorithm itself

def mergesort(array)
    if array.count <= 1
        # Array of length 1 or less is always sorted
        return array
    end

    # Apply "Divide & Conquer" strategy

    # Divide
    mid = array.count / 2
    part_a = mergesort array.slice(0, mid)
    part_b = mergesort array.slice(mid, array.count - mid)

    # Conquer
    array = []
    offset_a = 0
    offset_b = 0
    while offset_a < part_a.count && offset_b < part_b.count
        a = part_a[offset_a]
        b = part_b[offset_b]

        # Take the smallest of the two, and push it on our array
        if a <= b
            array << a
            offset_a += 1
        else
            array << b
            offset_b += 1
        end
    end

    # There is at least one element left in either part_a or part_b (not both)
    while offset_a < part_a.count
        array << part_a[offset_a]
        offset_a += 1
    end

    while offset_b < part_b.count
        array << part_b[offset_b]
        offset_b += 1
    end

    return array
end

ary=[1,4,2,3,5,68,4,5,39,5,2,83,945,92]
time1 = Time.now.getutc
mergesort ary
time2 = Time.now.getutc
puts "It took ", time2-time1, "to sort the array"