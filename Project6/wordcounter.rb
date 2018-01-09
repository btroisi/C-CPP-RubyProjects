puts "Enter a file name to read your content from: "
name=gets.chomp
hash=Hash.new
file=File.open(name,"r")


file.each_line { |line|
words = line.split(/[\s,.?]+/)
words.each { |word|
    word=word.downcase
    if hash.has_key?(word)
        hash[word] = hash[word] + 1
    else
        hash[word] = 1
    end
}
}

# sort the hash by value, and then put sorted values into array
hary=hash.sort{|word1,word2| word2[1]<=>word1[1]}
#print first 20 values of array
hary[0,20].each{|e| puts "#{e[0]}: #{e[1]}"}

