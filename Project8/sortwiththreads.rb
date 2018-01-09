#Brandon Troisi
#CS333 Project 8 sortwiththreads.rb
#Uses threads on mergesort algorithm to sort array

thread_limit=2
module ParallelMergeSort

  def merge_sorted
    return self if size <= 1

    split = size / 2

    # Divide into sub-threads for left and right side of array
    left_part, right_part = [
        Thread.new { self.slice(0, split).merge_sorted },
        Thread.new { self.slice(split, self.size - split).merge_sorted }
    ].map(&:join).map(&:value)

    # Conquer and return
    array = self.class.new
    off_left, off_right = [0, 0] 

    #Execute mergesort on array
    while off_left < left_part.size && off_right < right_part.size
      l, r = left_part[off_left], right_part[off_right]

      #if left side is smaller than right, left side becomes array
      #otherwise right side becomes array
      if l<= r
        array << l
        off_left += 1
      else
        array << r
        off_right += 1
      end
    end

    #Keep splitting left side of array until size of array is 1
    while off_left < left_part.size
      array << left_part[off_left]
      off_left += 1
    end

    #Keep splitting right side of array until size of array is 1
    while off_right < right_part.size
      array << right_part[off_right]
      off_right += 1
    end

    array
  end


end

time1 = Time.now.getutc
Array.send(:include, ParallelMergeSort)
time2 = Time.now.getutc

print "Sorted list ",[10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12].merge_sorted
print "It took ", time2-time1, " seconds to sort for ", thread_limit, " threads \n"