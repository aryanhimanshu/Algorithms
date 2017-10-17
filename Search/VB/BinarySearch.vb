Module Binary_Search
  	Sub Main()
  	End Sub
	Function BinarySearch(arr() As Integer, size As Integer, value As Integer) As Integer
		Dim first, last, middle, position As Integer
		Dim found As Boolean
		found = False
		first = 0
		last = size - 1
		position = -1
		'As long as the value has not been found and there are values left to search, it will continue to search
		While (Not found & first <= last)
			'sets middle the middle index to search
			middle = (first + last) / 2
			'Checks to see if value equals the index of the array
			If arr(middle) = value Then
				'Sets found to true to quit the while loops
				found = True
				'Sets middle index to position index
				position = middle
				'Checks to see if value is less than searched value
			ElseIf arr(middle) > value Then
				'Sets the range by changing the upper bound to the index below the index checked
				last = middle - 1
				'Checks to see if value is greater than the searched value
			Else
				'Sets the range by changing the lower bound to the index above the index checked
				first = middle + 1
			End If
		End While
		'Returns the index of the value found
		Return position
	End Function
End Module
