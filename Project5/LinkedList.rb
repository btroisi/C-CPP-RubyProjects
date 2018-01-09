class Node
	attr_accessor :data, :next
	
	
	def initialize(data,next_node)
		@data=data
		@next=next_node
	end
end

class LinkedList
	attr_accessor :head, :size
	def initialize
		#Initializes LinkedList
		@head=nil
		@size=0	
	end

	def push(data)
		#Adds node to front of list, storing data in new node 
		if @size==0
			@head=Node.new(data,nil)
			@size=@size+1
			
		else
			cur=@head
			while cur.next!=nil
				cur=cur.next
			end
			cur.next=Node.new(data,nil)
			@size=@size+1
		end

		
	end 

	def pop
		#Removes node at front of list and returns data from removed node
		return "Stack is empty" if @size==0
		retval=@head.data
		@head=@head.next
		@size=@size-1
		return retval
				
		
	end

	def append(data)
		#Adds node to end of list, storing data in new node
		if(@size==0)
			new_node=Node.new(data,nil)
			@head=new_node
			@size=@size+1
		
		else
			cur=@head
			while cur.next!=nil
				cur=cur.next
			end
		
			cur.next=Node.new(data,nil)
			@size=@size+1
		end
		
	end

	def remove(data)
		#Removes the first node in the list whose data matches desired value to remove
		return "No elements to remove" if(@size==0)

		cur=@head
		prev=nil
		while cur!=nil
			if cur.data!=data
				prev = cur
				cur=cur.next
			else
				retval=cur.data
				next_node=cur.next
				if prev!=nil
					prev.next=next_node
					@size=@size-1 
					return retval
				elsif prev.next==nil
					@head=cur.next
					@size=@size-1 
					return retval
				end
			end

		end
		return nil

	end


	def get_size
		#Return size of list
		return @size
	end

	def clear
		#Clears the list
		@head=nil
		@size=0
	end 

	def printlist
		#Prints the entire list
		cur = @head
		if @head!=nil
			while cur!=nil
				puts cur.data
				cur=cur.next
			end
		end 
	end
end

#Now testing functions for linked list
#Tests linked list functions for strings and integers
puts "\nCreating linked list of integers by pushing"

list= LinkedList.new()
for i in 1..10
	list.push(i)
end 
list.printlist
puts "Size of list: #{list.get_size}"
puts "After popping 1"
list.pop
list.printlist
puts "Size of list: #{list.get_size}"
puts "After removing 8"
list.remove(8)
list.printlist
list.clear
puts "After clearing list"
list.printlist
puts "Creating a list by appending..."
list.append(12)
list.append(18)
list.append(4)
list.append("CS")
list.printlist
puts "After popping 12 from list"
list.pop
list.printlist
puts "After removing CS from list"
list.remove("CS")
list.printlist
puts "After trying to remove 'No' from list"
list.remove("No")
list.printlist
list.clear
list.printlist
puts "We cleared this list, now we're done!!"











