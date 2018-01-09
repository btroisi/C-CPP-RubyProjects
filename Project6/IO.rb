#Reads content from file and prints to terminal
def readFromFile()
    puts "Enter a file name to read your content from: " 
    name=gets.chomp 
    file=File.open(name,"r") #Open file that user specified and read contents of that file
    while(line=file.gets)
        puts(line) 
        end
    file.close
end

#Reads from one file and outputs the content in file being read to 
def writeToFile()
    puts "Enter a file name to read your content from and write to another file: " 
    name=gets.chomp 
    file=File.open(name,"r") #Open file that user specified and read contents of that file
    ofile=File.open("outputrb.txt",'w') #Specify file for user to write data to called outputrb.txt
    while(line=file.gets)
        ofile.write(line)
    end
    puts "Written to outputrb.txt"
    file.close
    
end

#Reads binary file based on user input
def readBinaryFile()
    puts "Enter a binary file: " 
    name=gets.chomp 
    contents=File.binread(name) 
    puts contents 

end

readFromFile()
writeToFile()
readBinaryFile()